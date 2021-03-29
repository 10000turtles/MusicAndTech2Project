#ifndef Root
#define Root
#include "ArgParser.cpp"
#include "utils.cpp"
#include <experimental/filesystem>
#include <vector>

using namespace smf;
using namespace std;

namespace fs = experimental::filesystem;

class rootMap {
public:
  vector<int> notes;
  vector<double> times;
  MidiFile file;

  rootMap() {
    notes.push_back(-1);
    times.push_back(0.0);
  }
  rootMap(Args a) {
    if (a.root) {
      for (const auto &entry :
           fs::directory_iterator(a.readPath + a.song + "/Root_Note")) {
        file.read(entry.path());
        for (int i = 3; i < file.getEventCount(0); i++) {
          if (file.getEvent(0, i).getP0() == 144) {
            times.push_back(file.getTimeInSeconds(0, i));
            notes.push_back(file.getEvent(0, i).getP1());
          }
        }
        break;
      }
    } else {
      rootMap();
    }
    cout << "Root Map end" << endl;
  }
};
#endif