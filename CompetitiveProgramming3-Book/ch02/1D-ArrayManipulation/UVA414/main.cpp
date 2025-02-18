#include <bits/stdc++.h>
#include <climits>
#include <cstdio>
#include <strings.h>
#include <vector>

using namespace std;

int main() {
  int n;
  string buffer;

  do {
    cin >> n;
    if (n == 0) break;
    cin.ignore();

    vector<int> gaps(n);
    
    int min_gap = INT_MAX;

    for(int counter = 0; counter < n; counter++) {
      getline(cin, buffer);

      int leftEnd = 0, rightStart = 24;

      while(leftEnd < 25 && buffer[leftEnd] == 'X')
        leftEnd++;

      while(rightStart > 0 && buffer[rightStart] == 'X')
        rightStart--;

      int gap = rightStart - leftEnd + 1;

      gaps[counter] = gap;
      if (gap < min_gap) {
          min_gap = gap;
      }
    }

    int total_void = 0;

    for(int gap : gaps) {
        total_void += gap - min_gap;
    }

    cout << total_void << endl;

  } while(n!=0);

  return 0;
}
