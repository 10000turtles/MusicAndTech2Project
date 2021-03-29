
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

  jazz.GenerateNewPieces();
}