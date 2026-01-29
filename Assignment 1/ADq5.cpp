#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int t;
    cout << "Enter number of test cases: ";
    cin >> t;
    
    while (t--) {
        long long n, h, w;
        cout << "\nEnter N (number of rectangles), H (height), W (width): ";
        cin >> n >> h >> w;
        
        cout << "\n========================================\n";
        cout << "Test Case: N = " << n << " rectangles, H = " << h << ", W = " << w << "\n";
        cout << "========================================\n";
        
        long long minSquare = LLONG_MAX;
        long long bestRows = 1, bestCols = n;
        
        cout << "\nTrying different row-column arrangements:\n";

        for (long long rows = 1; rows <= n; rows++) {
            long long cols = (n + rows - 1) / rows;

            long long widthNeeded = cols * w;
            long long heightNeeded = rows * h;

            long long squareSide = max(widthNeeded, heightNeeded);
            
            cout << "  Rows: " << rows << ", Cols: " << cols << " -> ";
            cout << "Width: " << widthNeeded << ", Height: " << heightNeeded << " -> ";
            cout << "Square Side: " << squareSide << "\n";
            
            if (squareSide < minSquare) {
                minSquare = squareSide;
                bestRows = rows;
                bestCols = cols;
            }
        }
        
        cout << "\n--- RESULT ---\n";
        cout << "Best arrangement: " << bestRows << " rows × " << bestCols << " columns\n";
        cout << "Width needed: " << bestCols * w << "\n";
        cout << "Height needed: " << bestRows * h << "\n";
        cout << "Minimum square side length: " << minSquare << "\n";
        cout << "Square area: " << minSquare * minSquare << "\n";
    }
    
    return 0;
}
