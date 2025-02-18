#include <bits/stdc++.h>

using namespace std;

bool lock_combination(const vector<int>& combinaciones, size_t index, int acumulado) {
    if (index == combinaciones.size()) {
        // Check if the total rotation is a multiple of 360
        return (acumulado % 360 == 0);
    }

    // Try adding the current angle (clockwise rotation)
    if (lock_combination(combinaciones, index + 1, acumulado + combinaciones[index])) {
        return true;
    }

    // Try subtracting the current angle (counterclockwise rotation)
    if (lock_combination(combinaciones, index + 1, acumulado - combinaciones[index])) {
        return true;
    }

    // If neither works, return false
    return false;
}

int main() {
    int size;
    scanf("%d", &size);
    cin.ignore();

    vector<int> combinaciones(size);

    for(int i=0; i<size; i++) {
        int buffer;
        scanf("%d", &buffer);
        cin.ignore();
        combinaciones[i] = buffer;
    }

    bool result = lock_combination(combinaciones, 0, 0);

    if (result) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}
