/*P0 :-> Find the sum of all subarrays which are in Arithmetic Progression! Each array element is also an Arithmetic Progression!

Difference should only be 0 or 1 

[5 8 8 10 11 12] 
*/


#include <iostream>
#include <vector>

using namespace std;

int sum_of_arithmetic_subarrays(vector<int>& b, int n) {
    int w = 0;  // sum of all array elements
    for (int i = 1; i <= n; ++i) {
        w += b[i];
    }

    int v = 0;
    int c = 0;
    int prv = 0;
    int answer = 0;

    for (int i = 1; i <= n; ++i) {
        if (i == 1) {
            v = v + b[i];
            prv = b[i];
        } else {
            if (b[i] - b[i - 1] == 1) {
                c = c + 1;
                v = prv + b[i] * (c + 1);
                prv = v;
            } else {
                v =  b[i];
                c = 0;
                prv = b[i];
            }
        }
        //cout<<v;
        //cout<<'\n';
        answer = answer + v;  // sum of all valid subarrays ending at index i
    }
    
    // Reset variables for the second loop
    v = 0;
    c = 0;
    prv = 0;

    for (int i = 1; i <= n; ++i) {
        if (i == 1) {
            v = v + b[i];
            prv = b[i];
        } else {
            if (b[i] - b[i - 1] == 0) {
                c = c + 1;
                v = prv + b[i] * (c + 1);
                prv = v;
            } else {
                v = b[i];
                c = 0;
                prv = b[i];
            }
        }
        //cout<<v;
        //cout<<'\n';
        answer = answer + v;  // sum of all valid subarrays ending at index i
    }
    answer = answer - w; 
    return answer;
}

int main() {
    int n;
    cin >> n;  // size of array b
    vector<int> b(n + 1);  // array b

    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
    }

    int result = sum_of_arithmetic_subarrays(b, n);
    cout << result << endl;

    return 0;
}
