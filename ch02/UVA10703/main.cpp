#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main() {
  int w, h, n;
  string buffer;

  while(getline(cin, buffer)) {
    istringstream stream(buffer);
    stream >> w >> h >> n;

    if(w == 0 && h == 0 && n == 0) break;

    vector<vector<bool> > matrix(h, vector<bool>(w, false));

    for(int c = 0; c < n; c++) {
      stream.clear();
      getline(cin, buffer);
      stream.str(buffer);

      int x1, y1, x2, y2;

      stream >> x1 >> y1 >> x2 >> y2;

      // Normalize coordinates
      int startX = min(x1, x2) - 1;  // Convert to 0-based index
      int endX = max(x1, x2);        // Exclusive bound
      int startY = min(y1, y2) - 1;  // Convert to 0-based index
      int endY = max(y1, y2);        // Exclusive bound

      cout << "Processing rectangle: " << startX << " " << endX  << endl;

      // Mark the rectangle
      for(int i = startY; i < endY; i++) {
        for(int j = startX; j < endX; j++) {
          matrix[i][j] = true;
        }
      }
    }

    int emptySpots = 0;

    for(int i = 0; i < h; i++) {
      for(int j = 0; j < w; j++) {
        if(!matrix[i][j]) {
          emptySpots++;
        }
      }
    }

    if(emptySpots == 0) {
      cout << "There is no empty spots.\n";
    } else if (emptySpots == 1) {
      cout << "There is one empty spot.\n";
    } else {
      cout << "There are " << emptySpots << " empty spots.\n";
    }
  }

  return 0;
}
