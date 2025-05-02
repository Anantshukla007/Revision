/*Explanation:-> Given an array of zeros and ones ; find the number of subarrays which have this property :->


(number of zeroes)
—---------------------    =    x / y 
(number of ones)

N = 7 
A ->[1 0 1 1 1 1 1]
X/Y = ½ 
Output -> [1 0 1] ;  X = 1 ; Y = 2 
[0 1 1] ; X = 1 ; Y = 2 
Ans is 2 . 
*/


#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> A(N);
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    ll X, Y;
    cin >> X >> Y;

    // cnt[T] = how many prefixes have transformed value T
    unordered_map<ll,ll> cnt;
    cnt.reserve(N*2);
    cnt[0] = 1;   // the empty prefix has T=0

    ll Z = 0, O = 0;    // running counts of zeros and ones
    ll T = 0;           // current transformed prefix value
    ll answer = 0;

    for(int i = 0; i < N; i++){
        if (A[i] == 0) {
            Z++;
        } else {
            O++;
        }
        // compute T_i = Y*Z_i - X*O_i
        T = Y * Z - X * O;

        // any previous prefix j with same T  ➞ subarray (j+1..i) works
        answer += cnt[T];

        // record this prefix
        cnt[T]++;
    }

    cout << answer << "\n";
    return 0;
}
