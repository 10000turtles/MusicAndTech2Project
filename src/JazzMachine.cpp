// g++ jazzMachine.cpp -lstdc++fs -o jazz
// ./jazz -song NIYS -rhythm -root -samples 6 -pitchOrder 2 -rhythmOrder 3
// -newSongs 1

#include "ArgParser.cpp"
#include "pitchMap.cpp"
#include "rhythmMap.cpp"
#include "rootMap.cpp"
#include "utils.cpp"
#include <experimental/filesystem>
#include <filesystem>
#include <iostream>
#include <list>
#include <random>

using namespace smf;
using namespace std;

// typedef map<int, map<vector<int>, map<int, int>>> PitchMap;
// typedef map<vector<double>, map<double, int>> RhythmMap;
// typedef vector<pair<double, int>> RootMap;

namespace fs = experimental::filesystem;

class jazzMachine {
public:
  pitchMap pitches;
  rhythmMap rhythms;
  rootMap roots;
  Args args;

  jazzMachine() {}

  jazzMachine(Args a) {
    args = Args(a.configPath);
    roots = rootMap(args);
    pitches = pitchMap(args, roots);
    rhythms = rhythmMap(args);
  }

  void GenerateNewPieces();
};

void jazzMachine::GenerateNewPieces() {
  MidiFile t, s;
  fs::directory_iterator a = fs::directory_iterator(args.readPath);
  // while (a->is_directory())
  // {
  //   a++;
  // }
  t.read(a->path());
  s.read(a->path());

  double totalTime = t.getFileDurationInTicks();

  for (int q = 0; q < args.newSamples; q++) {
    s.clear();

    map<vector<int>, map<int, int>>::iterator item =
        pitches.m[roots.notes[0]].begin();
    std::advance(item, gen_rand_float() * (pitches.m[roots.notes[0]].size()));
    vector<int> prevNotes = (*item).first;

    map<vector<double>, map<double, int>>::iterator item2 = rhythms.m.begin();
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

        if (args.voiceLeadingRange == -1) {
          std::advance(item, gen_rand_float() *
                                 (pitches.m[roots.notes[rootCounter]].size()));
          prevNotes = (*item).first;
        } else {
          vector<vector<int>> possibleContinuations;
          while (item != pitches.m[roots.notes[rootCounter]].end()) {
            if (abs((*item).first[(*item).first.size() - 1] -
                    prevNotes[prevNotes.size() - 1]) <=
                args.voiceLeadingRange) {
              if (!abs((*item).first[(*item).first.size() - 1] -
                       prevNotes[prevNotes.size() - 1]) == 0) {
                possibleContinuations.push_back((*item).first);
              }
            }

            item++;
          }
          if (possibleContinuations.size() == 0) {
            item = pitches.m[roots.notes[rootCounter]].begin();
            std::advance(item,
                         gen_rand_float() *
                             (pitches.m[roots.notes[rootCounter]].size()));
            prevNotes = (*item).first;
          } else {
            vector<vector<int>>::iterator newPick =
                possibleContinuations.begin();
            advance(newPick, gen_rand_float() * possibleContinuations.size());
            prevNotes = (*newPick);

            s.addNoteOn(0, timeCounter, 0, prevNotes[prevNotes.size() - 1], 80);
            s.addNoteOff(0, timeCounter + t.getAbsoluteTickTime(0.125), 0,
                         prevNotes[prevNotes.size() - 1], 80);
            timeCounter += t.getAbsoluteTickTime(
                0.125); // Change this to add in rhythmic variation instead of a
                        // 16th note
          }
        }
      }

      if (rhythms.m[prevRhythms].size() == 0) {
        item2 = rhythms.m.begin();
        std::advance(item2, gen_rand_float() * (rhythms.m.size()));
        prevRhythms = (*item2).first;
      }
      int newNote =
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
        s.addNoteOn(0, timeCounter, 0, newNote, 80);
        s.addNoteOff(0, timeCounter + t.getAbsoluteTickTime(0.125), 0, newNote,
                     80);
        timeCounter += t.getAbsoluteTickTime(newRhythm);
      } else {
        timeCounter += t.getAbsoluteTickTime(-newRhythm);
      }
    }

    s.sortTracks();
    s.write(args.writePath + "/Rhythm" + to_string(q) + ".mid");
  }
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