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

using namespace std;
using namespace smf;

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

string strVec(vector<int> data)
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

void PrintMap(map<vector<int>, map<int, int>> mMap)
{
  for (map<vector<int>, map<int, int>>::iterator i = mMap.begin(); i != mMap.end(); i++)
  {
    cout << strVec((*i).first) << " -> ";
    for (map<int, int>::iterator j = (*i).second.begin(); j != (*i).second.end(); j++)
    {
      cout << (*j).first << ": " << (*j).second << "  ";
    }
    cout << endl;
  }
}

void LoadData(int samples, int levels, MidiFile* m, map<vector<int>, map<int, int>>& mMap, string path)
{
  vector<int> data;
  int         q = 0;
  for (const auto& entry : fs::directory_iterator(path))
  {
    m[q].read(entry.path());
    data.clear();

    for (int i = 3; i < m[q].getEventCount(0); i++)
    {
      if (m[q].getEvent(0, i).getP0() == 144)
        data.push_back(m[q].getEvent(0, i).getP1());
    }

    for (int i = levels; i < data.size() - levels; i++)
    {
      mMap[subVec(data, i - levels, i)][data[i]]++;
    }
    q++;
  }
}

int weightedRandomPick(map<int, int> m)
{
  vector<int> list;
  for (map<int, int>::iterator i = m.begin(); i != m.end(); i++)
    for (int j = 0; j < (*i).second; j++)
      list.push_back((*i).first);

  vector<int>::iterator item = list.begin();
  advance(item, gen_rand_float() * list.size());
  return (int)(*item);
}

void GenerateNewPiece(map<vector<int>, map<int, int>> mMap, string in, string out)
{
  int      q = 0;
  MidiFile t;
  for (const auto& entry : fs::directory_iterator(in))
  {
    t.clear();
    t.read(entry.path());
    map<vector<int>, map<int, int>>::iterator item = mMap.begin();
    std::advance(item, gen_rand_float() * (mMap.size()));
    vector<int> prevNotes = (*item).first;
    list<int>   activeNotes;

    for (int i = 3; i < t.getEventCount(0); i++)
    {
      if (t.getEvent(0, i).getP0() == 144)
      {
        if (mMap[prevNotes].size() == 0)
        {
          item = mMap.begin();
          std::advance(item, gen_rand_float() * (mMap.size()));
          prevNotes = (*item).first;
        }

        int newNote = weightedRandomPick(mMap[prevNotes]);
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

int main(int argc, char** argv)
{
  string readPath  = "/home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/src/midiSamples/FMajor";
  string writePath = "/home/turtles/Documents/Code/School/ARTS4160/MusicAndTech2Project/src/creations/FMajor";
  int    samples   = 10;
  int    levels    = 3;

  MidiFile* m = new MidiFile[samples];

  map<vector<int>, map<int, int>> markovMap;

  LoadData(samples, levels, m, markovMap, readPath);
  PrintMap(markovMap);
  GenerateNewPiece(markovMap, readPath, writePath);
}