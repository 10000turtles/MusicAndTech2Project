
#include "JazzMachine.cpp"

#include <experimental/filesystem>
#include <filesystem>
#include <iostream>
#include <list>
#include <random>

using namespace smf;
using namespace std;

int main(int argc, char **argv) {
  Args markov_data = Args(string(argv[1]));

  jazzMachine jazz = jazzMachine(markov_data);

  cout << "Finished Jazz creation" << endl;

  jazz.GenerateNewPieces();
}

// int main(int argc, char **argv) {

//   vector<int> a;
//   a.push_back(0);
//   a.push_back(1);
//   a.push_back(2);
//   a.push_back(3);
//   Chord c(a);
//   cout << toString(c) << endl;
//   vector<Chord> q = c.getPermutations();

//   for (int i = 0; i < q.size(); i++) {
//     cout << toString(q[i]) << endl;
//   }
// }