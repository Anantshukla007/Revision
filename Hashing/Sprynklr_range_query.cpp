/*You are given a string s consisting of lowercase English letters. You will be given q queries. Each query is a pair of integers (l, r) representing a substring of s (1-indexed).

For each query, you are to compute the total number of contiguous substrings within the substring s[l..r] that consist of only one unique character.*/



#include <iostream>
#include <vector>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.length();

    int q;
    cin >> q;

    vector<vector<int>> pre(n + 1, vector<int>(26, 0));

    for (int i = 0; i < n; i++) {
        int e = s[i] - 'a';
        for (int j = 0; j < 26; j++) {
            pre[i + 1][j] = (e == j) + pre[i][j];
        }
    }

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        int ans = 0;

        for (int j = 0; j < 26; j++) {
            int num = pre[r][j] - pre[l - 1][j];
            ans += num * (num + 1) / 2;
        }

        cout << ans << endl;
    }

    return 0;
}
