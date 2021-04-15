// g++ jazzMachine.cpp -lstdc++fs -o jazz
// ./jazz -song NIYS -rhythm -root -samples 6 -pitchOrder 2 -rhythmOrder 3
// -newSongs 1

#include "Binasc.cpp"
#include "MidiEvent.cpp"
#include "MidiEventList.cpp"
#include "MidiFile.cpp"
#include "MidiMessage.cpp"
#include "Options.cpp"

#include <bits/stdc++.h>
#include <experimental/filesystem>
#include <iostream>
#include <list>
#include <map>
#include <random>
#include <stdio.h>
#include <vector>

using namespace smf;
using namespace std;

class Chord;

double gen_rand_float();
template <class T> vector<T> subVec(vector<T> data, int a, int b);
template <class T> vector<T> concat(T thing, vector<T> list);
template <class T> vector<T> concat(vector<T> list, vector<T> addedList);
template <class T> string strVec(vector<T> data);
template <class T> vector<T> toVector(set<T> s);
template <class T> void PrintMap(map<vector<T>, map<T, int>> mMap);
template <class T> T weightedRandomPick(map<T, double> m);
bool operator==(const Chord &lhs, const Chord &rhs);
bool operator!=(const Chord &lhs, const Chord &rhs);
bool operator<(const Chord &lhs, const Chord &rhs);
vector<Chord> upOctave(vector<Chord> c);
vector<Chord> downOctave(vector<Chord> c);
vector<Chord> transpose(vector<Chord> c, int t);
string toString(Chord c);

namespace fs = experimental::filesystem;

class Args {
public:
  string configPath;

  string song;
  string readPath;
  string writePath;

  bool rhythm;
  bool root;
  bool useSamples;

  int samples;
  int pitchOrder;
  int rhythmOrder;
  int newSamples;
  int voiceLeadingRange;

  int newGenOctaves;
  double octaveMultiple;

  Args() {}
  Args(string c) {
    configPath = c;
    voiceLeadingRange = -1;
    ifstream f(configPath);
    string temp;
    while (f >> temp) {
      if (temp == string("-song")) {
        f >> temp;
        song = string(temp);
      }
      if (temp == string("-rhythm")) {
        f >> temp;
        if (temp == string("true")) {
          rhythm = true;
        } else {
          rhythm = false;
        }
      }
      if (temp == string("-root")) {
        f >> temp;
        if (temp == string("true")) {
          root = true;
        } else {
          root = false;
        }
      }
      if (temp == string("-samples")) {
        f >> temp;
        samples = stoi(temp);
        useSamples = true;
      }
      if (temp == string("-pitchOrder")) {
        f >> temp;
        pitchOrder = stoi(temp);
      }
      if (temp == string("-rhythmOrder")) {
        f >> temp;
        rhythmOrder = stoi(temp);
      }
      if (temp == string("-newSongs")) {
        f >> temp;
        newSamples = stoi(temp);
      }
      if (temp == string("-readPath")) {
        f >> temp;
        readPath = string(temp);
      }
      if (temp == string("-writePath")) {
        f >> temp;
        writePath = string(temp);
      }
      if (temp == string("-voiceLeading")) {
        f >> temp;
        voiceLeadingRange = stoi(temp);
      }
      if (temp == string("-newGenOctaves")) {
        f >> temp;
        newGenOctaves = stoi(temp);
      }
      if (temp == string("-octaveMultiple")) {
        f >> temp;
        octaveMultiple = stod(temp);
      }
    }
    fs::directory_iterator entry;
    if (song != string("")) {
      entry = fs::directory_iterator(readPath + song);
    } else {
      cout << "Error: No song name passed" << endl;
    }
    if (entry == end(entry)) {
      cout << "Error: No songs in folder/no folder" << endl;
    }
    if (!useSamples) {
      int i = 0;
      while (entry != end(entry)) {
        entry++;
        i++;
      }
      samples = i;
    }
  }
}; // namespace experimental::filesystemclassArgs

class Chord {
public:
  vector<int> notes;
  Chord() {}
  Chord(vector<int> notes) { this->notes = notes; }

  vector<int> getNotes() { return notes; }
  vector<Chord> getPermutations() { return concat(*this, recursePerms(notes)); }
  vector<Chord> recursePerms(vector<int> n) {
    set<Chord> temp;
    for (long unsigned int i = 0; i < n.size(); i++) {
      temp.insert(Chord(concat(subVec(n, 0, i), subVec(n, i + 1, n.size()))));

      vector<Chord> temp2 =
          recursePerms(concat(subVec(n, 0, i), subVec(n, i + 1, n.size())));
      if (temp2.size() > 1)
        for (long unsigned int j = 0; j < temp2.size(); j++) {
          temp.insert(temp2[j]);
        }
    }
    return toVector(temp);
  }
  void add(int n) { notes.push_back(n); }
  void clear() { notes.clear(); }
};

class rootMap {
public:
  vector<int> notes;
  vector<double> times;

  rootMap() {
    notes.push_back(-1);
    times.push_back(0.0);
  }
  rootMap(Args a) { Load(a); }
  void Load(Args a) {
    if (a.root) {
      for (const auto &entry :
           fs::directory_iterator(a.readPath + a.song + "/Root_Note")) {
        MidiFile fq;
        fq.read(entry.path());
        for (int i = 3; i < fq.getEventCount(0); i++) {
          if (fq.getEvent(0, i).getP0() == 144) {
            times.push_back(fq.getTimeInSeconds(0, i));
            notes.push_back(fq.getEvent(0, i).getP1());
          }
        }
        break;
      }
    }
  }
};

class pitchMap {

public:
  MidiFile file;
  map<int, map<vector<Chord>, map<Chord, double>>> m;

  pitchMap() {}

  pitchMap(Args a, rootMap r) { Load(a, r); }

  void Load(Args a, rootMap r) {
    vector<Chord> dataPitch;
    vector<double> dataTime;
    for (const auto &entry : fs::directory_iterator(a.readPath + a.song)) {
      cout << entry.path() << endl;
      if (entry.path() == a.readPath + a.song + string("/Root_Note"))
        continue;
      file.read(entry.path());
      dataPitch.clear();
      dataTime.clear();

      double prevTime = 0.0;
      Chord *newChord = new Chord();

      for (int i = 3; i < file.getEventCount(0); i++) {
        if (file.getEvent(0, i).getP0() == 144) {
          if (file.getEvent(0, i).getP0() - prevTime == 0.0) {
            newChord->add(file.getEvent(0, i).getP1());
          } else {
            dataPitch.push_back(*newChord);
            dataTime.push_back(prevTime);
            newChord->clear();
          }

          prevTime = file.getTimeInSeconds(0, i);
        }
      }

      int rootCounter = 0;

      for (int i = a.pitchOrder; i < dataPitch.size(); i++) {
        while ((rootCounter < ((int)r.notes.size() - 1)) &&
               dataTime[i] > r.times[rootCounter + 1]) {
          rootCounter++;
        }
        m[r.notes[rootCounter]][subVec(dataPitch, i - a.pitchOrder, i)]
         [dataPitch[i]]++;
        for (int j = 0; j < a.newGenOctaves; j++) {
          m[r.notes[rootCounter]][transpose(
              subVec(dataPitch, i - a.pitchOrder, i), -12 * j)][dataPitch[i]] +=
              pow(a.octaveMultiple, j);
          m[r.notes[rootCounter]][transpose(
              subVec(dataPitch, i - a.pitchOrder, i), 12 * j)][dataPitch[i]] +=
              pow(a.octaveMultiple, j);
        }
      }
    }
  }
};

class rhythmMap {
public:
  double QUARTER_NOTE = 0.5;
  double EIGHTH_NOTE = 0.25;
  double SIXTEENTH_NOTE = 0.125;

  MidiFile file;
  map<vector<double>, map<double, double>> m;

  rhythmMap() {}
  rhythmMap(Args a) { Load(a); }
  void Load(Args a) {

    vector<double> data;
    vector<int> dataIndicies;

    for (const auto &entry : fs::directory_iterator(a.readPath + a.song)) {

      if (entry.path() == a.readPath + a.song + string("/Root_Note"))
        continue;
      file.read(entry.path());
      data.clear();
      dataIndicies.clear();

      for (int i = 3; i < file.getEventCount(0); i++) {
        if (file.getEvent(0, i).getP0() == 144) {
          dataIndicies.push_back(i);
        }
      }

      for (int i = 0; i < dataIndicies.size() - 1; i++) {
        double t = file.getTimeInSeconds(0, dataIndicies[i + 1]) -
                   file.getTimeInSeconds(0, dataIndicies[i]);
        if (t > QUARTER_NOTE) {
          double tempT = t - QUARTER_NOTE;
          if (std::fmod(t, SIXTEENTH_NOTE) == 0 &&
              std::fmod(t, EIGHTH_NOTE) != 0) {
            data.push_back(-SIXTEENTH_NOTE); // Negative numbers signify a rest
          }
          while (tempT > 0) {
            data.push_back(-EIGHTH_NOTE); // Negative numbers signify a rest
            tempT -= EIGHTH_NOTE;
          }
        } else if (t > 0) {
          data.push_back(round(t * 8) /
                         8.0); // Deals with "Close enough" numbers
        }
      }

      for (int i = a.rhythmOrder; i < data.size() - a.rhythmOrder; i++) {
        m[subVec(data, i - a.rhythmOrder, i)][data[i]]++;
      }
    }
  }
};

class jazzMachine {

  pitchMap pitches;
  rhythmMap rhythms;
  rootMap roots;
  Args args;

public:
  jazzMachine() {}

  jazzMachine(Args a) {
    cout << "Entered Constructor" << endl;
    args = Args(a.configPath);
    cout << "Finished Args" << endl;
    roots = rootMap(args);
    cout << "Finished roots" << endl;
    pitches = pitchMap(args, roots);
    cout << "Finished pitches" << endl;
    rhythms = rhythmMap(args);
    cout << "Finished rhythms" << endl;
  }

  void GenerateNewPieces() {
    MidiFile t, s;
    fs::directory_iterator a = fs::directory_iterator(args.readPath);

    t.read(a->path());
    s.read(a->path());

    double totalTime = t.getFileDurationInTicks();

    for (int q = 0; q < args.newSamples; q++) {
      s.clear();

      map<vector<Chord>, map<Chord, double>>::iterator item =
          pitches.m[roots.notes[0]].begin();
      std::advance(item, gen_rand_float() * (pitches.m[roots.notes[0]].size()));
      vector<Chord> prevNotes = (*item).first;

      map<vector<double>, map<double, double>>::iterator item2 =
          rhythms.m.begin();
      std::advance(item2, gen_rand_float() * (rhythms.m.size()));
      vector<double> prevRhythms = (*item2).first;

      double timeCounter = 0;
      int rootCounter = 0;

      while (timeCounter < totalTime) {
        while (rootCounter < roots.notes.size() - 1 &&
               timeCounter >
                   t.getAbsoluteTickTime(roots.times[rootCounter + 1])) {
          rootCounter++;
        }
        while (pitches.m[roots.notes[rootCounter]][prevNotes].size() == 0) {
          item = pitches.m[roots.notes[rootCounter]].begin();

          std::advance(item, gen_rand_float() *
                                 (pitches.m[roots.notes[rootCounter]].size()));
          prevNotes = (*item).first;
        }

        if (rhythms.m[prevRhythms].size() == 0) {
          item2 = rhythms.m.begin();
          std::advance(item2, gen_rand_float() * (rhythms.m.size()));
          prevRhythms = (*item2).first;
        }
        Chord newNote =
            weightedRandomPick(pitches.m[roots.notes[rootCounter]][prevNotes]);
        double newRhythm = weightedRandomPick(rhythms.m[prevRhythms]);

        for (int j = 0; j < prevNotes.size() - 1; j++) {
          prevNotes[j] = prevNotes[j + 1];
        }

        for (int j = 0; j < prevRhythms.size() - 1; j++) {
          prevRhythms[j] = prevRhythms[j + 1];
        }

        prevNotes[prevNotes.size() - 1] = newNote;
        prevRhythms[prevRhythms.size() - 1] = newRhythm;

        if (newRhythm > 0) {
          for (int i = 0; i < newNote.getNotes().size(); i++) {
            s.addNoteOn(0, timeCounter, 0, newNote.getNotes()[i], 80);
            s.addNoteOff(0, timeCounter + t.getAbsoluteTickTime(0.125), 0,
                         newNote.getNotes()[i], 80);
          }
          timeCounter += t.getAbsoluteTickTime(newRhythm);
        } else {
          timeCounter += t.getAbsoluteTickTime(-newRhythm);
        }
      }

      s.sortTracks();
      s.write(args.writePath + args.song + "/" + args.song + "Solo" +
              to_string(q) + ".mid");
    }
  }
};

double gen_rand_float() {
  static std::random_device rd;
  static std::mt19937 engine(rd());
  static std::uniform_real_distribution<double> dist(0.0, 1.0);
  return dist(engine);
}

template <class T> vector<T> subVec(vector<T> data, int a, int b) {
  vector<T> temp;
  for (int i = a; i < b; i++)
    temp.push_back(data[i]);
  return temp;
}

template <class T> vector<T> concat(T thing, vector<T> list) {
  vector<T> temp;
  temp.push_back(thing);
  for (int i = 0; i < list.size(); i++)
    temp.push_back(list[i]);
  return temp;
}

template <class T> vector<T> concat(vector<T> list, vector<T> addedList) {
  vector<T> temp = list;
  for (int i = 0; i < addedList.size(); i++)
    temp.push_back(addedList[i]);
  return temp;
}

template <class T> vector<T> toVector(set<T> s) {
  vector<T> temp;
  for (typename set<T>::iterator i = s.begin(); i != s.end(); i++) {
    temp = concat((*i), temp);
  }
  return temp;
}

template <class T> string strVec(vector<T> data) {
  string temp = "(";
  for (int i = 0; i < data.size(); i++) {
    if (i == data.size() - 1) {
      temp += to_string(data[i]);
    } else {
      temp += to_string(data[i]) + ", ";
    }
  }
  temp += ")";
  return temp;
}

template <class T> void PrintMap(map<vector<T>, map<T, int>> mMap) {
  for (typename map<vector<T>, map<T, int>>::iterator i = mMap.begin();
       i != mMap.end(); i++) {
    cout << strVec((*i).first) << " -> ";
    for (typename map<T, int>::iterator j = (*i).second.begin();
         j != (*i).second.end(); j++) {
      cout << (*j).first << ": " << (*j).second << "  ";
    }
    cout << endl;
  }
}

template <class T> T weightedRandomPick(map<T, double> m) {
  vector<T> list;
  vector<double> weights;
  double sum = 0;
  for (typename map<T, double>::iterator i = m.begin(); i != m.end(); i++) {
    list.push_back((*i).first);
    weights.push_back((*i).second);
    sum += (*i).second;
  }

  double randPick = gen_rand_float() * sum;
  double count = 0;

  for (int i = 0; i < list.size(); i++) {
    count += weights[i];
    if (count > randPick) {
      return list[i];
    }
  }
  return list[list.size() - 1];
}

vector<Chord> upOctave(vector<Chord> c) {
  for (int i = 0; i < c.size(); i++) {
    for (int j = 0; j < c[i].notes.size(); j++) {
      c[i].notes[j] += 12;
    }
  }
  return c;
}

vector<Chord> downOctave(vector<Chord> c) {
  for (int i = 0; i < c.size(); i++) {
    for (int j = 0; j < c[i].notes.size(); j++) {
      c[i].notes[j] -= 12;
    }
  }
  return c;
}

vector<Chord> transpose(vector<Chord> c, int t) {
  for (int i = 0; i < c.size(); i++) {
    for (int j = 0; j < c[i].notes.size(); j++) {
      c[i].notes[j] += t;
    }
  }
  return c;
}

bool operator==(const Chord &lhs, const Chord &rhs) {

  vector<int> a = lhs.notes;
  vector<int> b = rhs.notes;

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  if (a.size() == b.size()) {
    for (long unsigned int i = 0; i < b.size(); i++) {
      if (a[i] != b[i]) {
        return false;
      }
    }
    return true;
  }
  return false;
}

bool operator!=(const Chord &lhs, const Chord &rhs) { return !(lhs == rhs); }

bool operator<(const Chord &lhs, const Chord &rhs) {
  if (lhs.notes.size() < rhs.notes.size()) {
    return true;
  } else if (lhs.notes.size() > rhs.notes.size()) {
    return false;
  } else {
    for (int i = 0; i < lhs.notes.size(); i++) {
      if (lhs.notes[i] < rhs.notes[i]) {
        return true;
      } else if (lhs.notes[i] > rhs.notes[i]) {
        return false;
      }
    }
    return false;
  }
}

string toString(Chord c) {
  string temp;
  temp = temp + "(";
  for (long unsigned int i = 0; i < c.notes.size(); i++) {
    if (i == c.notes.size() - 1) {
      temp = temp + to_string(c.notes[i]) + ")";
    } else {
      temp = temp + to_string(c.notes[i]) + ", ";
    }
  }
  return temp;
}

/*
void GenerateNewPiece(string in, string out, PitchMap pMap, int newSongs)
{
  int      q = 0;
  MidiFile t;
  for (const auto& entry : fs::directory_iterator(in))
  {
    t.clear();
    t.read(entry.path());
    map<vector<int>, map<int, int>>::iterator item = pMap.begin();
    std::advance(item, gen_rand_float() * (pMap.size()));
    vector<int> prevNotes = (*item).first;
    list<int>   activeNotes;

    for (int i = 3; i < t.getEventCount(0); i++)
    {
      if (t.getEvent(0, i).getP0() == 144)
      {
        if (pMap[prevNotes].size() == 0)
        {
          item = pMap.begin();
          std::advance(item, gen_rand_float() * (pMap.size()));
          prevNotes = (*item).first;
        }

        int newNote = weightedRandomPick(pMap[prevNotes]);
        for (int j = 0; j < prevNotes.size() - 1; j++)
        {
          prevNotes[j] = prevNotes[j + 1];
        }
        prevNotes[prevNotes.size() - 1] = newNote;
        t.getEvent(0, i).setP1(newNote);
        activeNotes.push_back(newNote);
      }
      else if (t.getEvent(0, i).getP0() == 128)
      {
        int newNote = activeNotes.front();
        t.getEvent(0, i).setP1(newNote);
        activeNotes.pop_front();
      }
    }
    t.write(out + "/" + to_string(q) + ".mid");
    q++;
    if (q == newSongs)
    {
      break;
    }
  }
}
*/
