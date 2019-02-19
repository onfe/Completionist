#include <iostream>
#include <string>
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
