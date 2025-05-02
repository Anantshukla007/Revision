/*Understanding :-> Given an array of size “N”; find a subset from an array with a particular property and the sum of that subset should be maximum possible. 

-> all adjacent elements should follow this.-> 

(s[1],s[2],...........s[m]) -> s[2] - s[1] = position[2] - position[1] 
S[3]-s[2] = position[3] - position[2].
*/


#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;


int main(){
    
    ll n ; 
    cin>>n;
    unordered_map <ll,ll> kk ;
    for(ll i=1;i<=n;i++){
        ll yy;
        cin>>yy;
        kk[yy-i] = kk[yy-i] + yy ; 
    }
    ll v = 0 ; 
    for(auto itr = kk.begin();itr!=kk.end();++itr){
        cout<<itr->first<<" "<<itr->second;
        v = max(v,itr->second);
        cout<<'\n';
    }
    cout<<v ; 
    
    return 0;
}