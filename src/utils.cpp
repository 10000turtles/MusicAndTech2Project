#ifndef Midi
#define Midi
#include "Binasc.cpp"
#include "MidiEvent.cpp"
#include "MidiEventList.cpp"
#include "MidiFile.cpp"
#include "MidiMessage.cpp"
#include "Options.cpp"
#endif

#ifndef A
#define A

#include <random>

using namespace std;

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

template <class T> T weightedRandomPick(map<T, int> m) {
  vector<T> list;
  for (typename map<T, int>::iterator i = m.begin(); i != m.end(); i++)
    for (int j = 0; j < (*i).second; j++)
      list.push_back((*i).first);

  typename vector<T>::iterator item = list.begin();
  advance(item, gen_rand_float() * list.size());
  return (T)(*item);
}
#endif