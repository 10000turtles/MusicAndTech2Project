
#include "utils.cpp"
#include <experimental/filesystem>
#include <map>
#include <vector>

using namespace smf;
using namespace std;

namespace fs = experimental::filesystem;

class rhythmMap {
public:
  double QUARTER_NOTE = 0.5;
  double EIGHTH_NOTE = 0.25;
  double SIXTEENTH_NOTE = 0.125;
  MidiFile file;
  map<vector<double>, map<double, int>> m;

  rhythmMap() {}
  rhythmMap(Args a) {

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
          if (fmod(t, SIXTEENTH_NOTE) == 0 && fmod(t, EIGHTH_NOTE) != 0) {
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
