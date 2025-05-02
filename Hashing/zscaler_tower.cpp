/*Alex has n piles of boxes with varying heights. In each step, Alex can remove any number of boxes from the tallest pile to reduce its height to match the next tallest pile. Determine the minimum number of steps required to make all piles equal in height.
Example
n-3
boxesin Piles = [5,2,1]*/


#include<iostream>
#include<map>
#include<vector>
int main(){
    int n;
    cin>>n;
    vector<int>b(n+1);
    map<int,int>mp;

    for(int i=1;i<=n;i++){
        cin>>b[i];
    }

    for(auto x:b){
        mp[x]++;

    }

    vector<pair<int,int>>g;

    for(auto u:mp){
        g.push_back({u.first,u.second});

    }

    int size = g.size();
    int step =0;

    for(int i=size-1;i>=1;i--){
        g[i-1].second += g[i].second;
        step += g[i].second;
        g[i].second = 0;
    }

    cout<<step<<endl;
    return 0;
}