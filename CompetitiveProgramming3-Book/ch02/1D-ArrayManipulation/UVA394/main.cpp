#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

int main() {
    int n, r;
    cin >> n >> r;
    cin.ignore(); // Ignore the newline after reading r

    map<string, vector<int>> arrays;

    for (int i = 0; i < n; ++i) {
        string line;
        getline(cin, line);
        istringstream iss(line);
        
        string name;
        int baseAddress, elementSize, dimensions;
        iss >> name >> baseAddress >> elementSize >> dimensions;
        
        vector<pair<int, int>> bounds(dimensions);
        for (int d = 0; d < dimensions; ++d) {
            int lower, upper;
            iss >> lower >> upper;
            bounds[d] = make_pair(lower, upper);
        }
        
        vector<int> constants(dimensions + 1);
        constants[dimensions] = elementSize; // CD is the element size
        
        for (int d = dimensions - 1; d >= 1; --d) {
            constants[d] = constants[d + 1] * (bounds[d].second - bounds[d].first + 1);
        }
        
        int c0 = baseAddress;
        for (int d = 1; d <= dimensions; ++d) {
            c0 -= constants[d] * bounds[d - 1].first;
        }
        constants[0] = c0;
        
        arrays[name] = constants;
    }

    for (int i = 0; i < r; ++i) {
        string line;
        getline(cin, line);
        istringstream iss(line);
        
        string name;
        iss >> name;
        
        vector<int> indexes;
        int idx;
        while (iss >> idx) {
            indexes.push_back(idx);
        }
        
        const vector<int>& constants = arrays[name];
        int sum = constants[0];
        for (size_t j = 0; j < indexes.size(); ++j) {
            sum += constants[j + 1] * indexes[j];
        }
        
        cout << name << "[";
        for (size_t j = 0; j < indexes.size(); ++j) {
            if (j > 0) {
                cout << ", ";
            }
            cout << indexes[j];
        }
        cout << "] = " << sum << endl;
    }

    return 0;
}
