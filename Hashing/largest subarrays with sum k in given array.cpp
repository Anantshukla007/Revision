//Find count of shortest/largest subarrays with sum k in given array
#include<iostream>
#include<vector>
#include<unordered_map>
#include<climits>

using namespace std;

pair<int,int>solve(int n,int k, vector<int>arr){
    unordered_map<int,int>mp;
    unordered_map<int,int>mp2
    ;

    mp[0] =0;
    int psum =0;
    int maxlength = 0;
    int minlength = INT_MAX;

    for(int j =1;j<=n;++j){
        psum +=arr[j-1];
        int x = psum-k;

        if(mp.find(x)!=mp.end()){
            int i= mp[x]+1;
            int currlength = j-i+1;

            if(currlength > maxlength){
                maxlength = currlength
            }
        }
        if(mp2.find(x)!=mp2.end()){
            int i= mp2[x]+1;
            int currlength = j-i+1;
            if(currlength<minlength){
                minlength = currlength
            }
        }
        if(mp.find(psum)==mp.end()){
            mp[psum] = j;
        }
        mp2[psum] = j;
    }

    return {maxlength,minlength};
}


int count(int n, int k, vector<int>arr,int targ){
    if(targ==0) return 0;

    int count =0;
    int windowsum =0;
    for(int j=0;j<targ;j++){
        windowsum += arr[j];
    }
    if(windowsum ==k){
        count++;
    }

    for(int j = targ;j<n;j++){
        windowsum += arr[j]-arr[j-targ];
        if(windowsum == k){
            count++;
        }
    }
    return count;
}



int main() {
    int n = 6;
    int k = 5;
    vector<int> arr = {1, 2, 3, 4, 2, 5};
 
    auto [maxLength, minLength] = findSubarraySizes(n, k, arr);
    int maxCount = countSubarraysWithLength(n, k, arr, maxLength);
    int minCount = countSubarraysWithLength(n, k, arr, minLength);
 
    cout << "Max Length: " << maxLength << " Count: " << maxCount << endl;
    cout << "Min Length: " << minLength << " Count: " << minCount << endl;
 
    return 0;
}