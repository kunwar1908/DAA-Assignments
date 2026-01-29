#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    
    vector<int> arr(n);
    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << "Initial Array: ";
    for (int x : arr) cout << x << " ";
    cout << "\nTotal elements: " << n << "\n";
    cout << "Operations to perform: " << (n - 2) << "\n";
    
    for (int op = 1; op <= n - 2; op++) {
        cout << "\n--- OPERATION " << op << " ---\n";
        cout << "Current Array: ";
        for (int x : arr) cout << x << " ";
        cout << " (Size: " << arr.size() << ")\n\n";
        
        vector<pair<int, pair<int, int>>> subarrays;
        vector<int> medians;
        
        cout << "Subarrays of odd size > 2:\n";

        for (int size = 3; size <= arr.size(); size += 2) {
            for (int i = 0; i <= arr.size() - size; i++) {
                vector<int> temp(arr.begin() + i, arr.begin() + i + size);
                sort(temp.begin(), temp.end());
                int median = temp[size / 2];
                
                cout << "  Subarray[" << i << ".." << (i + size - 1) << "]: ";
                for (int j = i; j < i + size; j++) cout << arr[j] << " ";
                cout << "-> Median: " << median << "\n";
                
                medians.push_back(median);
                subarrays.push_back({median, {i, i + size - 1}});
            }
        }
        
        int minMedian = *min_element(medians.begin(), medians.end());
        cout << "\nMedians found: ";
        for (int m : medians) cout << m << " ";
        cout << "\nMinimum Median: " << minMedian << "\n";

        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == minMedian) {
                cout << "Removing first occurrence of " << minMedian << " at index " << i << "\n";
                arr.erase(arr.begin() + i);
                break;
            }
        }
    }

    cout << "Final Array: ";
    long long sum = 0;
    for (int x : arr) {
        cout << x << " ";
        sum += x;
    }
    cout << "\n\nSum of remaining elements: " << sum << "\n";
    
    return 0;
}
