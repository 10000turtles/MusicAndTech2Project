// g++ jazzMachine.cpp -lstdc++fs -o jazz
// ./jazz -song NIYS -rhythm -root -samples 6 -pitchOrder 2 -rhythmOrder 3 -newSongs 1

#include "Binasc.cpp"
#include "MidiEvent.cpp"
#include "MidiEventList.cpp"
#include "MidiFile.cpp"
#include "MidiMessage.cpp"
#include "Options.cpp"
#include <experimental/filesystem>
#include <filesystem>
#include <iostream>
#include <list>
#include <random>

using namespace smf;
using namespace std;

typedef map<int, map<vector<int>, map<int, int>>> PitchMap;
typedef map<vector<double>, map<double, int>>     RhythmMap;
typedef vector<pair<double, int>>                 RootMap;

namespace fs = filesystem;

double gen_rand_float()
{
  static std::random_device                     rd;
  static std::mt19937                           engine(rd());
  static std::uniform_real_distribution<double> dist(0.0, 1.0);
  return dist(engine);
}

template <class T>
vector<T> subVec(vector<T> data, int a, int b)
{
  vector<T> temp;
  for (int i = a; i < b; i++)
    temp.push_back(data[i]);
  return temp;
}

template <class T>
vector<T> concat(T thing, vector<T> list)
{
  vector<T> temp;
  temp.push_back(thing);
  for (int i = 0; i < list.size(); i++)
    temp.push_back(list[i]);
  return temp;
}

template <class T>
string strVec(vector<T> data)
{
  string temp = "(";
  for (int i = 0; i < data.size(); i++)
  {
    if (i == data.size() - 1)
    {
      temp += to_string(data[i]);
    }
    else
    {
      temp += to_string(data[i]) + ", ";
    }
  }
  temp += ")";
  return temp;
}

template <class T>
void PrintMap(map<vector<T>, map<T, int>> mMap)
{
  for (typename map<vector<T>, map<T, int>>::iterator i = mMap.begin(); i != mMap.end(); i++)
  {
    cout << strVec((*i).first) << " -> ";
    for (typename map<T, int>::iterator j = (*i).second.begin(); j != (*i).second.end(); j++)
    {
      cout << (*j).first << ": " << (*j).second << "  ";
    }
    cout << endl;
  }
}

void LoadPitchData(int samples, int levels, MidiFile* m, PitchMap& mMap, string path)
{
  vector<int>    dataPitch;
  vector<double> dataTime;

  int q = 0;
  for (const auto& entry : filesystem::directory_iterator(path))
  {
    if (!entry.is_directory())
    {
      m[q].read(entry.path());
    }
    else
    {
      continue;
    }

    dataPitch.clear();
    dataTime.clear();

    for (int i = 3; i < m[q].getEventCount(0); i++)
    {
      if (m[q].getEvent(0, i).getP0() == 144)
      {
        dataPitch.push_back(m[q].getEvent(0, i).getP1());
        dataTime.push_back(m[q].getTimeInSeconds(0, i));
      }
    }

    for (int i = levels; i < dataPitch.size() - levels; i++)
    {
      mMap[-1][subVec(dataPitch, i - levels, i)][dataPitch[i]]++;
    }
    q++;
  }
}

void LoadPitchData(int samples, int levels, MidiFile* m, PitchMap& mMap, string path, RootMap& root_data)
{
  MidiFile       rootFile;
  vector<int>    dataPitch;
  vector<double> dataTime;
  root_data.clear();

  for (const auto& entry : filesystem::directory_iterator(path + "/Root_Note"))
  {
    rootFile.read(entry.path());
    for (int i = 3; i < rootFile.getEventCount(0); i++)
    {
      if (rootFile.getEvent(0, i).getP0() == 144)
      {
        root_data.push_back(make_pair(rootFile.getTimeInSeconds(0, i), rootFile.getEvent(0, i).getP1()));
      }
    }
    break;
  }
  int q = 0;
  for (const auto& entry : filesystem::directory_iterator(path))
  {
    if (!entry.is_directory())
    {
      m[q].read(entry.path());
    }
    else
    {
      continue;
    }

    dataPitch.clear();
    dataTime.clear();

    for (int i = 3; i < m[q].getEventCount(0); i++)
    {
      if (m[q].getEvent(0, i).getP0() == 144)
      {
        dataPitch.push_back(m[q].getEvent(0, i).getP1());
        dataTime.push_back(m[q].getTimeInSeconds(0, i));
      }
    }

    int rootCounter = 0;

    for (int i = levels; i < dataPitch.size() - levels; i++)
    {
      while (rootCounter < root_data.size() && dataTime[i] > root_data[rootCounter + 1].first)
      {
        rootCounter++;
      }
      mMap[root_data[rootCounter].second][subVec(dataPitch, i - levels, i)][dataPitch[i]]++;
    }
    q++;
  }
}

void LoadRhythmData(int samples, int levels, MidiFile* m, RhythmMap& mMap, string path)
{
  vector<double> data;
  vector<int>    dataIndicies;

  int q = 0;
  for (const auto& entry : fs::directory_iterator(path))
  {
    if (entry.is_directory())
    {
      continue;
    }
    m[q].read(entry.path());
    data.clear();
    dataIndicies.clear();

    for (int i = 3; i < m[q].getEventCount(0); i++)
    {
      if (m[q].getEvent(0, i).getP0() == 144)
      {
        dataIndicies.push_back(i);
      }
    }

    for (int i = 0; i < dataIndicies.size() - 1; i++)
    {
      double t = m[q].getTimeInSeconds(0, dataIndicies[i + 1]) - m[q].getTimeInSeconds(0, dataIndicies[i]);
      if (t > 0.5)
      {
        double tempT = t - 0.5;
        if (fmod(t, 0.125) == 0 && fmod(t, 0.25) != 0)
        {
          data.push_back(-0.125);  // Negative numbers signify a rest
        }
        while (tempT > 0)
        {
          data.push_back(-0.25);  // Negative numbers signify a rest
          tempT -= 0.25;
        }
      }
      else if (t > 0)
      {
        data.push_back(round(t * 8) / 8.0);
      }
    }

    for (int i = levels; i < data.size() - levels; i++)
    {
      mMap[subVec(data, i - levels, i)][data[i]]++;
    }
    q++;
  }
}

template <class T>
T weightedRandomPick(map<T, int> m)
{
  vector<T> list;
  for (typename map<T, int>::iterator i = m.begin(); i != m.end(); i++)
    for (int j = 0; j < (*i).second; j++)
      list.push_back((*i).first);

  typename vector<T>::iterator item = list.begin();
  advance(item, gen_rand_float() * list.size());
  return (T)(*item);
}


void GenerateNewPiece(string in, string out, PitchMap pMap, map<vector<double>, map<double, int>> rMap, int n, RootMap root_data)
{
  MidiFile                       t, s;
  filesystem::directory_iterator a = filesystem::directory_iterator(in);
  while (a->is_directory())
  {
    a++;
  }
  t.read(a->path());
  s.read(a->path());

  double totalTime = t.getFileDurationInTicks();

  for (int q = 0; q < n; q++)
  {
    s.clear();

    map<vector<int>, map<int, int>>::iterator item = pMap[root_data[0].second].begin();
    std::advance(item, gen_rand_float() * (pMap[root_data[0].second].size()));
    vector<int> prevNotes = (*item).first;

    map<vector<double>, map<double, int>>::iterator item2 = rMap.begin();
    std::advance(item2, gen_rand_float() * (rMap.size()));
    vector<double> prevRhythms = (*item2).first;

    double timeCounter = 0;
    int    rootCounter = 0;

    while (timeCounter < totalTime)
    {
      while (rootCounter < root_data.size() - 1 && timeCounter > t.getAbsoluteTickTime(root_data[rootCounter + 1].first))
      {
        rootCounter++;
      }
      while (pMap[root_data[rootCounter].second][prevNotes].size() == 0)
      {
        item = pMap[root_data[rootCounter].second].begin();

        std::advance(item, gen_rand_float() * (pMap[root_data[rootCounter].second].size()));
        prevNotes = (*item).first;
      }

      if (rMap[prevRhythms].size() == 0)
      {
        item2 = rMap.begin();
        std::advance(item2, gen_rand_float() * (rMap.size()));
        prevRhythms = (*item2).first;
      }
      int    newNote   = weightedRandomPick(pMap[root_data[rootCounter].second][prevNotes]);
      double newRhythm = weightedRandomPick(rMap[prevRhythms]);

      for (int j = 0; j < prevNotes.size() - 1; j++)
      {
        prevNotes[j] = prevNotes[j + 1];
      }

      for (int j = 0; j < prevRhythms.size() - 1; j++)
      {
        prevRhythms[j] = prevRhythms[j + 1];
      }

      prevNotes[prevNotes.size() - 1]     = newNote;
      prevRhythms[prevRhythms.size() - 1] = newRhythm;

      if (newRhythm > 0)
      {
        s.addNoteOn(0, timeCounter, 0, newNote, 80);
        s.addNoteOff(0, timeCounter + t.getAbsoluteTickTime(0.125), 0, newNote, 80);
        timeCounter += t.getAbsoluteTickTime(newRhythm);
      }
      else
      {
        timeCounter += t.getAbsoluteTickTime(-newRhythm);
      }
    }

    s.sortTracks();
    s.write(out + +"/Rhythm" + to_string(q) + ".mid");
  }
}

int main(int argc, char** argv)
{
  string readPath  = "/home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/src/midiSamples/";
  string writePath = "/home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/src/creations/";

  string song = "";

  bool rhythm     = false;
  bool root       = false;
  bool useSamples = false;

  int samples;
  int pitchLevels  = 1;
  int rhythmLevels = 1;
  int newSongs     = 1;

  for (int i = 1; i < argc; i++)
  {
    if (argv[i] == string("-song"))
    {
      i++;
      song = string(argv[i]);
    }
    if (argv[i] == string("-rhythm"))
    {
      rhythm = true;
    }
    if (argv[i] == string("-root"))
    {
      root = true;
    }
    if (argv[i] == string("-samples"))
    {
      i++;
      samples    = stoi(argv[i]);
      useSamples = true;
    }
    if (argv[i] == string("-pitchOrder"))
    {
      i++;
      pitchLevels = stoi(argv[i]);
    }
    if (argv[i] == string("-rhythmOrder"))
    {
      i++;
      rhythmLevels = stoi(argv[i]);
    }
    if (argv[i] == string("-newSongs"))
    {
      i++;
      newSongs = stoi(argv[i]);
    }
  }
  filesystem::directory_iterator entry;
  if (song != string(""))
  {
    entry = fs::directory_iterator(readPath + song);
  }
  else
  {
    cout << "Error: No song name passed" << endl;
  }
  if (entry == end(entry))
  {
    cout << "Error: No songs in folder/no folder" << endl;
  }
  if (!useSamples)
  {
    int i = 0;
    while (entry != end(entry))
    {
      entry++;
      i++;
    }
    samples = i;
  }

  MidiFile* m = new MidiFile[samples];

  PitchMap  markovPitchMap;
  RhythmMap markovRhythmMap;
  RootMap   root_data;

  root_data.push_back(make_pair(0.0, -1));

  LoadPitchData(samples, pitchLevels, m, markovPitchMap, readPath + song, root_data);
  LoadRhythmData(samples, rhythmLevels, m, markovRhythmMap, readPath + song);
  GenerateNewPiece(readPath + song, writePath + song, markovPitchMap, markovRhythmMap, newSongs, root_data);
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