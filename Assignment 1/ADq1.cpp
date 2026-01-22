#include <iostream>

using namespace std;

bool canDivide(int arr[], int n, int m, int maxOR) {
    int segments = 1;
    int currentOR = 0;
    
    for (int i = 0; i < n; i++) {
        int newOR = currentOR | arr[i];
        
        if (newOR <= maxOR) {
            currentOR = newOR;
        } else {
            segments++;
            currentOR = arr[i];
            if (currentOR > maxOR) return false;
        }
    }
    
    return segments <= m;
}

int findMinMaxOR(int arr[], int n, int m) {
    int high = 0;
    for (int i = 0; i < n; i++) {
        high |= arr[i];
    }
    
    int low = 0;
    int result = high;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (canDivide(arr, n, m, mid)) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    
    return result;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;
    int m = 3;
    
    cout << "Minimum possible maximum OR: " << findMinMaxOR(arr, n, m) << endl;
    
    return 0;
}