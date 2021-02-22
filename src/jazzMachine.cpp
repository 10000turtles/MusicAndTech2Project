// g++ jazzMachine.cpp -lstdc++fs -o jazz

#include "Binasc.cpp"
#include "MidiEvent.cpp"
#include "MidiEventList.cpp"
#include "MidiFile.cpp"
#include "MidiMessage.cpp"
#include "Options.cpp"
#include <experimental/filesystem>
#include <iostream>
#include <list>
#include <random>

using namespace smf;
using namespace std;


namespace fs = experimental::filesystem;

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

void LoadPitchData(int samples, int levels, MidiFile* m, map<vector<int>, map<int, int>>& mMap, string path)
{
  vector<int> data;

  int q = 0;
  for (const auto& entry : fs::directory_iterator(path))
  {
    m[q].read(entry.path());
    data.clear();

    for (int i = 3; i < m[q].getEventCount(0); i++)
    {
      if (m[q].getEvent(0, i).getP0() == 144)
      {
        data.push_back(m[q].getEvent(0, i).getP1());
      }
    }

    for (int i = levels; i < data.size() - levels; i++)
    {
      mMap[subVec(data, i - levels, i)][data[i]]++;
    }
    q++;
  }
}

void LoadRhythmData(int samples, int levels, MidiFile* m, map<vector<double>, map<double, int>>& mMap, string path)
{
  vector<double> data;
  vector<int>    dataIndicies;

  int q = 0;
  for (const auto& entry : fs::directory_iterator(path))
  {
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

void GenerateNewPiece(string in, string out, map<vector<int>, map<int, int>> pMap)
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
  }
}

void GenerateNewPiece(string in, string out, map<vector<int>, map<int, int>> pMap, map<vector<double>, map<double, int>> rMap, int n)
{
  MidiFile               t, s;
  fs::directory_iterator a = fs::directory_iterator(in);
  t.read(a->path());
  s.read(a->path());

  double totalTime = t.getFileDurationInTicks();
  for (int q = 0; q < n; q++)
  {
    s.clear();

    map<vector<int>, map<int, int>>::iterator item = pMap.begin();
    std::advance(item, gen_rand_float() * (pMap.size()));

    vector<int> prevNotes = (*item).first;

    map<vector<double>, map<double, int>>::iterator item2 = rMap.begin();
    std::advance(item2, gen_rand_float() * (rMap.size()));

    vector<double> prevRhythms = (*item2).first;

    double timeCounter = 0;

    while (timeCounter < totalTime)
    {
      if (pMap[prevNotes].size() == 0)
      {
        item = pMap.begin();
        std::advance(item, gen_rand_float() * (pMap.size()));
        prevNotes = (*item).first;
      }

      if (rMap[prevRhythms].size() == 0)
      {
        item2 = rMap.begin();
        std::advance(item2, gen_rand_float() * (rMap.size()));
        prevRhythms = (*item2).first;
      }

      int    newNote   = weightedRandomPick(pMap[prevNotes]);
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
    s.write(out + "/Rhythm" + to_string(q) + ".mid");
  }
}

int main(int argc, char** argv)
{
  string readPath  = "/home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/src/midiSamples/ReadyWednesday";
  string writePath = "/home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/src/creations/ReadyWednesday";
  int    samples   = 10;

  int pitchLevels  = 3;
  int rhythmLevels = 2;

  int numNewCompositions = 10;

  MidiFile* m = new MidiFile[samples];

  map<vector<int>, map<int, int>> markovPitchMap;

  map<vector<double>, map<double, int>> markovRhythmMap;

  LoadPitchData(samples, pitchLevels, m, markovPitchMap, readPath);
  LoadRhythmData(samples, rhythmLevels, m, markovRhythmMap, readPath);

  // PrintMap(markovPitchMap);
  // cout << endl;
  // PrintMap(markovRhythmMap);
  // cout << endl;


  GenerateNewPiece(readPath, writePath, markovPitchMap);
  GenerateNewPiece(readPath, writePath, markovPitchMap, markovRhythmMap, numNewCompositions);
}