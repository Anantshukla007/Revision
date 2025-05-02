/*We are given array of size N ; find the quadruplets such that a[i] < a[j] < a[k] < a[l] and i<j<k<l ; 

N<=1000 


Understanding :- 
A = [ 1 2 3 4 5 ]

Q -> {1 2 3 4}
{1 2 3 5}
{2 3 4 5}
{1 3 4 5}
{1 2 4 5}

Answer = 5 
*/
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll ; 

int main() {
    
    
    int n ; 
    cin>>n ; 
    
    int a[n+1] = {0};
    int p[n+1]={0};
    int s[n+1]={0};
    int i = 1 ; 
    while(i<=n){
        cin>>a[i];
        i++;
    }
    
    int j = 1 ; 
    while(j<=n){
        int i = j - 1 ; 
        while(i>=1){
            if(a[i]<a[j]){
                p[j] = p[j] + 1 ; 
            }
            i--;
        }
        j++;
    }
    
    int k = 1 ; 
    while(k<=n){
        int l = k + 1 ; 
        while(l<=n){
            if(a[k]<a[l]){
                s[k] = s[k] + 1 ; 
            }
            l++;
        }
        k++;
    }
    
    
    int gg = 0 ; 
    j = 1 ; 
    while(j<=n){
        k = j + 1 ; 
        while(k<=n){
            if(a[j]<a[k]){
                gg = gg + p[j]*s[k];
            }
            k++;
        }
        j++;
    }
    
    cout<<gg ; 
    return 0 ; 
}