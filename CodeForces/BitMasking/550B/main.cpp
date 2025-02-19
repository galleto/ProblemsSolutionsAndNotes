#include <bits/stdc++.h>
#include <cstdlib>

using namespace std;

int numberOfWays(const vector<int>& difficulties, int* l, int* r, int* x) {
    size_t n = difficulties.size();
    int possible_solutions = 0;

    for(int mask = 0; mask < (1 << n); mask++) {
        if(mask & (mask-1)) continue;

        vector<int> solution;
        int sum = 0;

        for(int i=0; i<n; i++) {
            if(mask & (1 << i)) {
                solution.push_back(difficulties[i]);
            }
        }


        if( sum >= *l && 
            sum <= *r &&
            (abs(solution[0] - solution[solution.size() - 1])) >= *x
        ) {
            possible_solutions++;
        }
    }

    return possible_solutions;
}

int main() {
    int n, l, r, x;
    scanf("%d %d %d %d", &n, &l, &r, &x);

    vector<int> difficulties(n);

    for(int i=0; i<n; i++) {
        int input;
        scanf("%d", &input);

        difficulties[i] = input;
    }

    sort(difficulties.begin(), difficulties.end());

    int result = numberOfWays(difficulties, &l, &r, &x);
    printf("%d", result);
    return 0;
}
