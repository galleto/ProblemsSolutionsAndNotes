#include <bits/stdc++.h>
#include <vector>

using namespace std;

void lock_combination(const vector<int>& combinations) {
    size_t n = combinations.size();

    for(int mask = 0; mask < (1 << n); mask++) {
        int total = 0;

        for(int i = 0; i < n; i++) {
            if(mask & (1 << i)) {
                total -= combinations[i];
            } else {
                total += combinations[i];
            }
        }

        if(total % 360 == 0) {
            printf("YES\n");
            return;
        }
    }

    printf("NO\n");
}

int main() {
    int size;
    scanf("%d", &size);
    vector<int> combinations(size);

    for(int i=0; i<size; i++) {
        int input;
        scanf("%d", &input);
        combinations[i] = input;
    }

    lock_combination(combinations);

    return 0;
}
