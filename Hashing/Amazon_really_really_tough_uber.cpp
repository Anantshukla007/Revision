/*Given an array of positive integersa, your task is to calculate the sum of every possible a[i]a[j], where a[i]a[j] is the concatenation of the string representations of a[i] and a[j] respectively.
Example
a = [10, 2] , the output should be solution(a) 1344.
a[0][0] = 10。10=1010,
a[0] * a[1] = 10 * 2 = 102
a[1] * a[0] = 2 * 10 = 210
a[1] * a[1] = 2 * 2 = 22
So the sum is equal to 1010102 210+ 22 1344.
For a = [8] the output should be solution(a) = 88.
There is only one number in a, and a[0] * a[0] = 8 * 8 = 88 so the answer is 88.
For a= [1, 2, 3], the output should be solution(a) 198.*/



#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    // Speed up I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 1) Read the number of elements
    int N;
    cin >> N;

    // 2) Read the array a[0..N-1]
    vector<ll> a(N);
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }

    // 3) Precompute powers of 10: pow10[d] = 10^d
    //    We only need up to about 19–20 digits for 64-bit integers.
    vector<ll> pow10(20);
    pow10[0] = 1;
    for(int d = 1; d < 20; d++){
        pow10[d] = pow10[d - 1] * 10LL;
    }

    // 4) Compute sumA = ∑_{i=0..N-1} a[i]
    //    We'll use this twice below.
    ll sumA = 0;
    for(ll x : a){
        sumA += x;
    }
    // At this point: sumA = a[0] + a[1] + ... + a[N-1]

    // 5) Compute sumPow10 = ∑_{j=0..N-1} 10^{len(a[j])}
    //    For each element, count its decimal digits d, then add pow10[d].
    ll sumPow10 = 0;
    for(ll x : a){
        // Count the number of digits in x
        int d = 0;
        ll t = x;
        do {
            d++;
            t /= 10;
        } while(t > 0);

        // Add 10^d to our running total
        sumPow10 += pow10[d];
    }
    // Now sumPow10 = 10^{len(a[0])} + 10^{len(a[1])} + ... + 10^{len(a[N-1])}

    // 6) Combine the two parts:
    //
    //    We want:
    //      ∑_{i,j} F(a[i],a[j])
    //    = ∑_{i,j} (a[i]*10^{len(a[j])} + a[j])
    //    = ( ∑_i a[i] ) * ( ∑_j 10^{len(a[j])} )
    //      + ∑_j a[j] * (number of i's, which is N)
    //
    //    That simplifies to:
    //      sumA * sumPow10   +   N * sumA
    //
    ll answer = sumA * sumPow10     // the "front" contributions
                  + (ll)N * sumA;  // the "back" contributions

    // 7) Output the result
    cout << answer << "\n";
    return 0;
}



| j | a[j] | sumA (after) | digits d | pow10[d] | sumPow10 (after) |
|:-:|:----:|:------------:|:--------:|:--------:|:----------------:|
| 0 | 1    | 1            | 1        | 10       | 10               |
| 1 | 2    | 3            | 1        | 10       | 20               |
| 2 | 3    | 6            | 1        | 10       | 30               |


answer = sumA * sumPow10 + N * sumA
       = 6 × 30      + 3 × 6
       = 180 + 18
       = 198
