/*Given an array find the number of good subarrays.
Good subarray is an array such that when it is removed rest of the array is strictly increasing
-> [1 2 3 405]
-> [0]; [0,5]; [40]; [405]; [340]; [3405]; [2340]; [23405]; [12340]; [123
4]
-> 10*/



#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 1) Read input size N and array A[1..N].
    int N;
    cin >> N;
    vector<long long> A(N+2);
    for(int i = 1; i <= N; i++){
        cin >> A[i];
    }
    // Put sentinels at ends to simplify edge‐cases:
    // A[0] = −∞, A[N+1] = +∞
    A[0]   = LLONG_MIN;
    A[N+1] = LLONG_MAX;

    // 2) Build prefix‐good and suffix‐good boolean arrays:
    //    prefix_good[i]  = true if A[1..i] is strictly increasing
    //    suffix_good[i]  = true if A[i..N] is strictly increasing
    vector<bool> prefix_good(N+2, false),
                 suffix_good(N+2, false);

    prefix_good[0] = true;  // empty prefix is vacuously good
    for(int i = 1; i <= N; i++){
        prefix_good[i] = prefix_good[i-1] && (A[i-1] < A[i]);
    }

    suffix_good[N+1] = true;  // empty suffix is vacuously good
    for(int i = N; i >= 1; i--){
        suffix_good[i] = suffix_good[i+1] && (A[i] < A[i+1]);
    }

    // 3) Now enumerate all subarrays [L..R].  Check:
    //    - prefix_good[L-1]      (the left piece is ok)
    //    - suffix_good[R+1]      (the right piece is ok)
    //    - A[L-1] < A[R+1]       (they connect in increasing order)
    long long count = 0;
    for(int L = 1; L <= N; L++){
        // If the prefix up to L−1 already fails, no need to try bigger R:
        if (!prefix_good[L-1]) break;
        for(int R = L; R <= N; R++){
            if (!suffix_good[R+1]) break;
            if (A[L-1] < A[R+1]) {
                count++;
            }
        }
    }

    cout << count << "\n";
    return 0;
}
