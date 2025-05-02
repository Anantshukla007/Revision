/*Understanding - For each string at index “i” you have to print the sum of matching characters of string “i” with string - “i+1” “i+2” “i+3” “i+4” “i+5” …… and so on. 

Sample Input - 

N = 5 
[bbz,
zaz,
aaa,
zaa,
zzz] 

O/P - [2,5,2,1,0]
*/

#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    std::vector<int> matchingCnt(int n, std::vector<std::string>& X) {
        std::vector<std::vector<int>> g(200000 + 5, std::vector<int>(28, 0));
        std::vector<int> p(n, 0);

        for (int i = n - 1; i >= 0; i--) {
            std::string u = X[i];
            int c = 0;
            int d = u.size();
            for (int j = 0; j < d; j++) { // j --> column number
                int y = int(u[j]) - 97;
                c = c + g[j][y]; // g[j][y] --> tells you the frequency of y in col "j"
                g[j][y] = g[j][y] + 1;
            }
            p[i] = c;
        }

        return p;
    }
};

int main() {
    Solution sol;
    int n = 3;
    std::vector<std::string> X = {"abc", "ade", "abc"};
    std::vector<int> result = sol.matchingCnt(n, X);

    for (int i = 0; i < n; ++i) {
        std::cout << result[i] << " ";
    }

    return 0;
}
