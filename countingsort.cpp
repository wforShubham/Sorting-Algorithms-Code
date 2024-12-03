#include <bits/stdc++.h>
using namespace std;

void countingSortWithNegatives(vector<int>& arr) {
    if (arr.empty()) return;

    int max_val = *max_element(arr.begin(), arr.end());
    int min_val = *min_element(arr.begin(), arr.end());

    int range = max_val - min_val + 1;

    vector<int> count(range, 0);

    for (int num : arr) {
        count[num - min_val]++;
    }

    for (int i = 1; i < range; i++) {
        count[i] += count[i - 1];
    }

    vector<int> output(arr.size());
    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[arr[i] - min_val] - 1] = arr[i];
        count[arr[i] - min_val]--;
    }

    arr = output;
}

int main() {
    vector<int> arr = {4, -1, 2, -3, 0, -2, 4, 1};
    countingSortWithNegatives(arr);

    cout << "Sorted Array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
