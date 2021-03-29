#ifndef AAA
#define AAA

#include <experimental/filesystem>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

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
#endif