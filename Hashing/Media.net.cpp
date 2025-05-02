/*Maximum Sum Selection

You are given an integer array A of size N. Your task is to select exactly B elements from either the left end or the right end of the array A in order to maximize the sum of the selected elements.

Here are the details of the problem:

You are given an integer array A of size N where 1 <= N <= 10^5.
You need to select exactly B elements from either the left end or the right end of the array A.
The goal is to find and return the maximum possible sum of elements you can pick.

Input:

An integer array A of size N where each element A[i] satisfies -103 <= A[i] <= 103.
An integer B where 1 <= B <= N.
Output:

An integer representing the maximum possible sum of selected elements.

[5, -2, 3, 1, 2], 3 -> 8
*/

#include <bits/stdc++.h>
using namespace std;

int fun(vector<int>& A, int B) {
    int n = A.size();
    vector<int> suff(n + 1, 0); // suff[i] = sum of A[i] to A[n-1]

    // Build suffix sum array
    for (int i = n - 1; i >= 0; --i) {
        suff[i] = A[i] + suff[i + 1];
    }

    int prefSum = 0;
    int ans = suff[n - B]; // Take last B elements initially

    // Try taking i+1 elements from front and remaining from back
    for (int i = 0; i < B; ++i) {
        prefSum += A[i];
        int suffSum = suff[n - B + i + 1];
        ans = max(ans, prefSum + suffSum);
    }
    return ans;
}

int solve(vector<int>& A, int B) {
    return fun(A, B);
}

int main() {
    vector<int> A = {5, -2, 3, 1, 2};
    int B = 3;
    cout << solve(A, B); // Output: 8
    return 0;
}
