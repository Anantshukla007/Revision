/*Find the number of subarrays such that their maximum is K - 

[8 2 1 3 4 5 1 10] 

K = 3

Output = 3. [3],[1 3],[2 1 3] */


#include<bits.stdc++.h>
using namespace std;

int solve(vector<int>A,int K){
    int n = A.size();
    int ans=0;

    int prevgreater = -1;
    vector<int>nextgre(n,n);
    int nextstop =n;

    for(int i=n-1 ;i>=0;i--){
        if(A[i]>=k){
            nextstop =i;
        }
        if(A[i] == k){
            nextgre[i] =nextstop
        }
    }

    for(int i=0;i<n;i++){

        if(A[i]>k){
            prevgreater = i;
        }
        else if(A[i] == k){
            int L = i- prevgreater-1;
            int R = nextgre[i]-i-1;
            ans += (L+1)*(R+1);
        }

    
    }
    return ans;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> A = {8, 2, 1, 3, 4, 5, 1, 10};
    int K = 3;
    cout << solve(A, K) << "\n";  // prints 3
    return 0;
}