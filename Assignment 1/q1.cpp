#include <iostream>
#include <vector>
using namespace std;

int binarySearch(const vector<int>& arr, int key) {
    int low = 0;
    int high = arr.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) return mid;
        else if (arr[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int main(){
    vector<int> sorted_arr = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int key = 23;
    cout << "Sorted Array: "; for (int v: sorted_arr) cout<<v<<" "; cout<<"\n";
    int idx = binarySearch(sorted_arr, key);
    if (idx!=-1) cout<<"Element "<<key<<" found at index: "<<idx<<"\n"; else cout<<"Not found\n";
    return 0;
}
