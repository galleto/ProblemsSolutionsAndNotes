#include <climits>
#include <cstdio>
#include <vector>

using namespace std;

vector<int> prefixSum(const vector<int>& original) {
    vector<int> prefixArr(original.size() + 1, 0);

    for(int i=0; i<original.size(); i++)
        prefixArr[i+1] = original[i] + prefixArr[i];

    return prefixArr;
}

int minSubArrSum(const vector<int>& original, int k) {
    int min = INT_MAX;
    int j = 0;

    vector<int> prefix = prefixSum(original);

    for(int i=0; (i + k) < prefix.size(); i++) {
        int result = prefix[i + k] - prefix[i];
        if(result < min) {
            min = result;
            j = i;
        }
    }

    return j+1;
}

int main() {
    int n, k;

    scanf("%d %d", &n, &k);

    vector<int> arr(n);

    for(int ni=0; ni < n; ni++) {
        int input;
        scanf("%d", &input);
        arr[ni] = input;
    }

    int j = minSubArrSum(arr, k);

    printf("%d\n", j);

    return 0;
}
