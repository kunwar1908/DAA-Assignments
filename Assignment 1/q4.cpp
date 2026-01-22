#include <iostream>
#include <climits>
using namespace std;

int maxSubarraySum(int arr[], int n) {
    int maxSoFar = INT_MIN;
    int maxEndingHere = 0;
    
    for (int i = 0; i < n; i++) {
        maxEndingHere = maxEndingHere + arr[i];
        
        if (maxSoFar < maxEndingHere)
            maxSoFar = maxEndingHere;
        
        if (maxEndingHere < 0)
            maxEndingHere = 0;
    }
    return maxSoFar;
}

int main() {
    int arr[] = {-2, -5, 6, -2, -3, 1, 5, -6};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Maximum subarray sum: " << maxSubarraySum(arr, n) << endl;
    return 0;
}