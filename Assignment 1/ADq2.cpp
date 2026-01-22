#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int maxGoodSubsequence(vector<int>& arr) {
    int n = arr.size();
    sort(arr.begin(), arr.end());

    int maxLen = 0;
    int left = 0;
    
    for (int right = 0; right < n; right++) {
        while (arr[right] - arr[left] > 10) {
            left++;
        }
        maxLen = max(maxLen, right - left + 1);
    }
    
    return maxLen;
}

int main() {
    vector<int> arr1 = {1, 2, 8, 16, 3, 5};
    cout << "Array: ";
    for (int x : arr1) cout << x << " ";
    cout << "\nMax good subsequence length: " 
         << maxGoodSubsequence(arr1) << endl;
    return 0;
}
