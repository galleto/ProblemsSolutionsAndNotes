#include <bits/stdc++.h>
#include <cstdio>
#include <ostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int main() {
  int n, r;

  scanf("%d %d", &n, &r);
  cin.ignore();

  int counter = 0;
  string buffer;
  string digits = "0123456789";

  map<string, vector<int>> arrays;

  string arrayName;

  while(counter < n) {
    // read N arrays
    getline(cin, buffer);
    int indexUntilWhitespace = buffer.find(' ');
    arrayName = buffer.substr(0, indexUntilWhitespace);

    int indexUntilNumberLowerBound = buffer.find_first_of(digits);
    int indexUntilNumberUpperBound = buffer.find(' ', indexUntilNumberLowerBound);

    int BaseAddress = stoi(buffer.substr(indexUntilNumberLowerBound, indexUntilNumberUpperBound));

    indexUntilNumberLowerBound = indexUntilNumberUpperBound + 1;
    indexUntilNumberUpperBound = buffer.find(' ', indexUntilNumberLowerBound);

    int B = stoi(buffer.substr(indexUntilNumberLowerBound, indexUntilNumberUpperBound));

    indexUntilNumberLowerBound = indexUntilNumberUpperBound + 1;
    indexUntilNumberUpperBound = buffer.find(' ', indexUntilNumberLowerBound);

    int D = stoi(buffer.substr(indexUntilNumberLowerBound, indexUntilNumberUpperBound));

    int innerCounter = 0;

    vector<pair<int, int>> bounds(D);

    while(innerCounter < D) {
      indexUntilNumberLowerBound = indexUntilNumberUpperBound + 1;
      indexUntilNumberUpperBound = buffer.find(' ', indexUntilNumberLowerBound);

      int lower = stoi(buffer.substr(indexUntilNumberLowerBound, indexUntilNumberUpperBound));

      indexUntilNumberLowerBound = indexUntilNumberUpperBound + 1;
      indexUntilNumberUpperBound = buffer.find(' ', indexUntilNumberLowerBound);

      int upper = stoi(buffer.substr(indexUntilNumberLowerBound, indexUntilNumberUpperBound));

      bounds[innerCounter] = (make_pair(lower, upper));

      innerCounter++;
    }

    vector<int> constants(D+1);

    constants[D] = B;

    for(int i=constants.size() - 2; i >= 1; i--) {
      constants[i] = constants[i+1] * (bounds[i].second - bounds[i].first + 1);
    }

    int c0 = BaseAddress;

    for(int i=1; i<constants.size(); i++) {
      c0 -= constants[i] * bounds[i-1].first;
    }

    constants[0] = c0;

    arrays[arrayName] = constants;
    
    counter++;
  }

  counter = 0;

  while(counter < r) {
    getline(cin, buffer);
    int indexUntilWhitespace = buffer.find(' ');
    arrayName = buffer.substr(0, indexUntilWhitespace);

    int size = arrays[arrayName].size();
    vector<int> indexes(size);

    int innerCounter = 0;

    int indexUntilNumberLowerBound = buffer.find_first_of(digits);
    int indexUntilNumberUpperBound = buffer.find(' ', indexUntilNumberLowerBound);

    int index = stoi(buffer.substr(indexUntilNumberLowerBound, indexUntilNumberUpperBound));

    indexes[innerCounter] = index;
    innerCounter++;

    while(innerCounter < size-1) {
      indexUntilNumberLowerBound = indexUntilNumberUpperBound + 1;
      indexUntilNumberUpperBound = buffer.find(' ', indexUntilNumberLowerBound);
      string input = buffer.substr(indexUntilNumberLowerBound, indexUntilNumberUpperBound);
      index = stoi(input);
      indexes[innerCounter] = index;
      innerCounter++;
    }

    cout << arrayName << "[";
    int sum = 0;
    sum += arrays[arrayName][0];

    for(int i=0; i < indexes.size()-1; i++) {
      if (i == indexes.size() - 2) {
        cout << indexes[i];
      } else {
        cout << indexes[i] << ", ";
      }

      sum += indexes[i] * arrays[arrayName][i+1];
    }

    cout << "] = ";
    cout << sum << endl;

    counter++;
  }

  return 0;
}
