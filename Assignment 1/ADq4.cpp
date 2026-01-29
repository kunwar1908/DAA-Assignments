#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k;
    cout << "Enter the number of elements (n): ";
    cin >> n;
    
    cout << "Enter the value of k: ";
    cin >> k;
    
    vector<int> arr(n);
    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << "Array: ";
    for (int x : arr) cout << x << " ";
    cout << "\nn = " << n << ", k = " << k << "\n";
    
    long long specialty = 0;
    
    for (int l = 0; l < n; l++) {
        cout << "Checking A[" << l << "] = " << arr[l] << ":\n";
        bool isSpecial = false;
        
        for (int i = 0; i < n && !isSpecial; i++) {
            for (int j = i; j < n && !isSpecial; j++) {
                int count = 0;
                for (int idx = i; idx <= j; idx++) {
                    if (arr[idx] > arr[l]) {
                        count++;
                    }
                }
                
                if (count == k) {
                    cout << "  Found subarray [" << i << ".." << j << "]: ";
                    for (int idx = i; idx <= j; idx++) {
                        cout << arr[idx] << " ";
                    }
                    cout << "-> " << count << " elements > " << arr[l] << " (SPECIAL!)\n";
                    isSpecial = true;
                }
            }
        }
        
        if (isSpecial) {
            cout << "  Result: A[" << l << "] = " << arr[l] << " is SPECIAL\n";
            specialty += arr[l];
        } else {
            cout << "  Result: A[" << l << "] = " << arr[l] << " is NOT special\n";
        }
        cout << "\n";
    }
    
    cout << "Specialty of the sequence: " << specialty << "\n";
    
    return 0;
}
