#include <bits/stdc++.h>
#include <cstdlib>

using namespace std;

int numberOfWays(vector<int>& difficulties, int* l, int* r, int* x) {
    size_t n = difficulties.size();
    int possible_solutions = 0;
    sort(difficulties.begin(), difficulties.end());

    for(int mask = 0; mask < (1 << n); mask++) {
        if(!(mask && (mask & (mask-1)))) continue;

        vector<int> solution;
        int sum = 0;

        for(int i=0; i<n; i++) {
            if(mask & (1 << i)) {
                sum += difficulties[i];
                solution.push_back(difficulties[i]);
            }
        }

        if( sum >= *l && 
            sum <= *r &&
            (solution[solution.size() - 1] - solution[0]) >= *x
        ) {
            possible_solutions+=1;
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

    int result = numberOfWays(difficulties, &l, &r, &x);
    printf("%d", result);
    return 0;
}
