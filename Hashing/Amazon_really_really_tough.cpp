/*Problem Statement
You are given an array 'A' of 'N' positive integers. The function F(X,Y) is defined as the number obtained by concatenating the decimal representations of X and Y. For example, F(300,90) = 30090 and F(1,1001) = 11001.
Your task is to find the sum of all possible values of F(Ai, Aj) for all pairs (i, j) such that 1 si<js N. In other words, compute the sum F(A1,A2)+F(A1,A3)++ F(A2,A3) + F(A2,A4)+...+F(AN-1,AN).
Since the answer can be very large, return the answer modulo 998244353.
Input Format
The first line of input contains a single integer N.
The second line of input contains N space separated integers representing the array A.
Output Format
Cosutac.in
Print a single Integer representing the final sum modulo 998244353
Sample Testcase #0
Testcase Input
3 3 14 15
Testcase Output
2044*/



#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// We’ll take all answers modulo this prime
static const int MOD = 998244353;

// (This function isn’t actually used in the final code, but would compute
//  a^e mod MOD in O(log e) time if you needed it.)
int modexp(ll a, ll e = 1, int mod = MOD) {
    ll r = 1 % mod, x = a % mod;
    while (e) {
        if (e & 1) r = (r * x) % mod;
        x = (x * x) % mod;
        e >>= 1;
    }
    return int(r);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    // 1) Read input size
    int N;
    cin >> N;
    
    // 2) Read the array A[0..N-1]
    vector<ll> A(N);
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }

    // 3) Precompute pow10[d] = 10^d mod MOD for d = 0..19
    //    (We only need up to ~19–20 digits for typical 64-bit inputs.)
    vector<int> pow10(20);
    pow10[0] = 1;
    for(int d = 1; d < (int)pow10.size(); d++){
        pow10[d] = int((pow10[d-1] * 10LL) % MOD);
    }

    // 4) prefix_sum will hold (A[0] + A[1] + ... + A[j-1]) % MOD
    ll prefix_sum = 0;
    // 5) answer accumulates the final result % MOD
    ll answer = 0;

    // 6) Process each j from 0..N-1, treating A[j] as the second element
    //    in all pairs (i<j).  We add two contributions:
    //    a) Sum of A[i] * 10^{len(A[j])} for each i<j
    //    b) Sum of A[j] for each i<j
    for(int j = 0; j < N; j++){
        // 6a) Compute digit-length d of A[j]
        int d = 0;
        ll t = A[j];
        do {
            d++;
            t /= 10;
        } while(t);

        // 6b) Add all front‐contributions: (sum over i<j of A[i]) * 10^d
        answer = (answer + prefix_sum * pow10[d]) % MOD;

        // 6c) Add all back‐contributions: A[j] * (number of i<j) = A[j] * j
        answer = (answer + (A[j] % MOD) * j) % MOD;

        // 6d) Now include A[j] into prefix_sum for future iterations
        prefix_sum = (prefix_sum + A[j]) % MOD;
    }

    // 7) Output the final answer
    cout << answer << "\n";
    return 0;
}



| Step | j  | A[j] | d = digits(A[j]) | prefix_sum (before) | pow10[d] | add front = prefix_sum*10^d | add back = A[j]*j | answer (cum.) | prefix_sum (after) |
|:----:|:--:|:----:|:----------------:|:-------------------:|:---------:|:----------------------------:|:-----------------:|:-------------:|:------------------:|
| init | —  |  —   |        —         |          0          |     —     |              —               |         —         |      0        |         —          |
| j=0  | 0  |  3   |        1         |          0          |    10¹=10 |       0 × 10 = 0             |    3 × 0 = 0      |      0        |   0 + 3 = 3       |
| j=1  | 1  | 14   |        2         |          3          |   10²=100 |       3 × 100 = 300          |   14 × 1 = 14     |   0 + 300 + 14 = 314 | 3 + 14 = 17     |
| j=2  | 2  | 15   |        2         |         17          |   100     |      17 × 100 = 1700         |   15 × 2 = 30     | 314 + 1700 + 30 = 2044 | 17 + 15 = 32  |