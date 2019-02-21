#include <iostream>
#include <string>
#include "SegmentTree.hpp"
#include "PhraseList.hpp"
#include "suggest.hpp"
using namespace std;

string complete(string inp) {
  return inp;
}


int main()
{
    string inp;
    string out;
    cout << "Query: ";
    getline(cin, inp);
    out = complete(inp);
    cout << out;
    return 0;
}
