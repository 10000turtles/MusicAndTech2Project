#ifndef CHORDS
#define CHORDS

#include "utils.cpp"
#include <bits/stdc++.h>
#include <stdio.h>
#include <vector>

using namespace std;

class Chord {
public:
  vector<int> notes;

  Chord(vector<int> notes);

  vector<int> getNotes() { return notes; }
  vector<Chord> getPermutations() { return recursePerms(notes); }
  vector<Chord> recursePerms(vector<int>);
  void add(Chord c);
};

Chord::add(int n) { notes.push_back(n); }

Chord::Chord(vector<int> notes) { this->notes = notes; }
vector<Chord> Chord::recursePerms(vector<int> n) {
  vector<Chord> temp;
  for (long unsigned int i = 0; i < n.size(); i++) {
    temp = concat(
        temp, recursePerms(concat(subVec(n, 0, i), subVec(n, i, n.size()))));
  }
  return temp;
}

string to_string(Chord c) {
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

#endif