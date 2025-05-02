/*Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

 

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
Example 3:

Input: nums = [1,0,1,2]
Output: 3*/


#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>nums){
    int n = nums.size();
    int ans =0;

    for(int i=0;i<n;i++){
        if(mp[nums[i]==0]){
            mp[nums[i]]++;
        }
    }

    for(int i=0;i<n;i++){
        int val = nums[i];
        if(mp.find(val)!=mp.end() && mp.find(val-1)== mp.end()){
            int curr = val;
            int cnt=0;

            while(mp.find(curr)!=mp.end()){
                mp[curr]--;
                curr++;
                cnt++;
            }
            ans = max(ans,cnt);

        }
        return ans;
    }
}