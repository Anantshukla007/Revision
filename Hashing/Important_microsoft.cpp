/*-> Given an array of size “N”; find -> find the number of unordered quadruplets (i,j,k,l) such that b[i] + b[j] + b[k] + b[l] = 0 

-> [1 2 3 4 -1 -2 -2] 

-> 3 [1,2,5,6]  [1,2,5,7] [1,3,6,7] 
*/


#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> b(n);
    unordered_map<int, int> y;
    
    // Input array b
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    // First loop to count sums of pairs (k, l)
    for (int k = 2; k < n; k++) {
        for (int l = k + 1; l < n; l++) {
            y[b[k] + b[l]]++;
        }
    }

    long long r = 0;

    // Second loop to count results
    for (int j = 1; j <= n - 3; j++) {
        for (int i = 0; i < j; i++) {
            int u = -(b[i] + b[j]);
            r += y[u];  // count of (k, l) whose sum = u
        }

        for (int j1 = j + 2; j1 < n; j1++) {
            y[b[j + 1] + b[j1]]--;
        }
    }

    cout << r << endl;
    
    return 0;
}
