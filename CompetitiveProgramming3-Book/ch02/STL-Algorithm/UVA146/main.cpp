#include <algorithm>
#include <bits/stdc++.h>
#include <string>

using namespace std;

int main() {
  string buffer;

  while(getline(cin, buffer) && buffer != "#") {
    if (next_permutation(buffer.begin(), buffer.end())) {
      cout << buffer << endl;
    } else {
      cout << "No Successor" << endl;
    }
  }

  return 0;
}
