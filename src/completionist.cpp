#include <iostream>
#include <string>
#include <vector>

#include <fstream>
#include <sstream>
#include <string>

#include "SegmentTree.hpp"
#include "PhraseList.hpp"
#include "suggest.hpp"
using namespace std;

typedef std::vector<phrase_t> pvc_t;

PhraseList pl;
SegmentTree st;

string complete(string inp) {
  string out;
  cout << "Getting suggestions for \"" << inp << "\". \n";
  pvc_t results = suggest(pl, st, inp, 4);
  cout << "Got " << results.size() <<" suggestions.\n";
  for (int i = 0; i < results.size(); ++i) {
    cout << results[i].phrase + "\n";
  }

  return out;
}


int main() {
  ifstream infile("smallwords.txt");
  string line;
  int pcount = 0;

  cout << "Loading phrases from file.\n";

  while (true) {
      if (!getline(infile, line)) break;
      std::vector<string> tokens;
      std::istringstream iss(line);
      string token;
      while(getline(iss, token, '\t')) {
        tokens.push_back(token);
      }
      cout << tokens[1] << " : " << tokens[0] << "\n";
      pl.insert(std::stoi(tokens[1]), tokens[0]);
      pcount++;
  }

  cout << "Loaded " << pcount << " phrases.\n";
  cout << "Sorting words.";

  pl.finish();

  cout << "Constructing Segment Tree.\n";

  vector<uint32_t> weights;
  for (int i = 0; i < pl.pl.size(); ++i) {
    weights.push_back(pl.pl[i].weight);
  }

  cout << "teste";

  st.init(weights);

  cout << "Done.\n";

  string inp;
  string out;
  while (true) {
    cout << "\nQuery: ";
    getline(cin, inp);
    out = complete(inp);
    cout << out;
  }

  return 0;
}
