
#include "rootMap.cpp"
#include "utils.cpp"
#include <experimental/filesystem>
#include <vector>

using namespace smf;
using namespace std;

namespace fs = experimental::filesystem;

class pitchMap {

public:
  MidiFile file;
  map<int, map<vector<int>, map<vector<int>, int>>> m;

  pitchMap() {}

  pitchMap(Args a, rootMap r) {
    vector<vector<int>> dataPitch;
    vector<double> dataTime;
    for (const auto &entry : fs::directory_iterator(a.readPath + a.song)) {
      cout << entry.path() << endl;
      if (entry.path() == a.readPath + a.song + string("/Root_Note"))
        continue;
      file.read(entry.path());
      dataPitch.clear();
      dataTime.clear();

      double prevTime = 0.0;
      vector<int> newChord;

      for (int i = 3; i < file.getEventCount(0); i++) {
        if (file.getEvent(0, i).getP0() == 144) {
          if (file.getEvent(0, i).getP0() - prevTime == 0.0) {
            newChord.push_back(file.getEvent(0, i).getP1());
          } else {
            dataPitch.push_back(newChord);
            dataTime.push_back(prevTime);
            newChord.clear();
          }

          prevTime = file.getTimeInSeconds(0, i);
        }
      }

      int rootCounter = 0;
      // Needs a re-write

      // for (int i = a.pitchOrder; i < dataPitch.size(); i++) {
      //   while ((rootCounter < ((int)r.notes.size() - 1)) &&
      //          dataTime[i] > r.times[rootCounter + 1]) {
      //     rootCounter++;
      //   }
      //   m[r.notes[rootCounter]][subVec(dataPitch, i - a.pitchOrder, i)]
      //    [dataPitch[i]]++;
      // for(int j = 0;j < newGenOctaves;j++){
      // m[r.notes[rootCounter]][subVec(dataPitch, i - a.pitchOrder, i)]
      //    [dataPitch[i]]++; // Up the octave
      // m[r.notes[rootCounter]][subVec(dataPitch, i - a.pitchOrder, i)]
      //    [dataPitch[i]]++;}// Down the octave
      // }
    }
  }
};
