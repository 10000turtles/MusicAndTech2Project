#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class Args
{
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

  Args(string c)
  {
    configPath        = c;
    voiceLeadingRange = -1;
    ifstream f(configPath);
    string   temp;
    while (f >> temp)
    {
      if (temp == string("-song"))
      {
        f >> temp;
        song = string(temp);
      }
      if (temp == string("-rhythm"))
      {
        rhythm = true;
      }
      if (temp == string("-root"))
      {
        root = true;
      }
      if (temp == string("-samples"))
      {
        f >> temp;
        samples    = stoi(temp);
        useSamples = true;
      }
      if (temp == string("-pitchOrder"))
      {
        f >> temp;
        pitchOrder = stoi(temp);
      }
      if (temp == string("-rhythmOrder"))
      {
        f >> temp;
        rhythmOrder = stoi(temp);
      }
      if (temp == string("-newSongs"))
      {
        f >> temp;
        newSamples = stoi(temp);
      }
      if (temp == string("-readPath"))
      {
        f >> temp;
        readPath = string(temp);
      }
      if (temp == string("-writePath"))
      {
        f >> temp;
        writePath = string(temp);
      }
      if (temp == string("-voiceLeading"))
      {
        f >> temp;
        voiceLeadingRange = stoi(temp);
      }
    }
  }
};