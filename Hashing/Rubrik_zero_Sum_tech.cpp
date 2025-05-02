/*> You are given an array of size “N” and two integers “x” and “y” 
-> Array only consists of integers “x” and “y”
-> Find the count of subarrays which have equal number of “x” and “y” 
*/



#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int main(){
    int n,x,y;
    cin>>n>>x>>y;
    vector<int>b(n);

    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    int count =0;
    unordered_map<int,int>mp;
    mp[0] =1;
    int cx=0;
    int cy=0;
    for(int i=1;i<=n;i++){
        if(b[i]==x){
            cx++;
        }
        else{
            cy++;
        }
        int d = cx-cy;
        count += mp[d];
        mp[d]++;
    }
    cout<<count<<endl;
    return 0;

}



///follow up with three or more elments


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countValidSubarrays(int n, int x, int y, int z, int w, int b) {
        int count = 0;  // Count of valid subarrays
        map<tuple<int, int, int, int>, int> freq;  // Frequency map to store counts of (d1, d2, d3, d4)
        freq[{0, 0, 0, 0}] = 1;  // Base case: (d1, d2, d3, d4) has been achieved once

        int cx = 0, cy = 0, cz = 0, cw = 0, cb = 0;  // Counters for x, y, z, w, b

        for (int i = 0; i < n; i++) {
            int val;
            cin >> val;  // Taking input for each element of the array

            // Update counters based on the value
            if (val == x) cx++;
            else if (val == y) cy++;
            else if (val == z) cz++;
            else if (val == w) cw++;
            else if (val == b) cb++;

            // Compute differences
            int d1 = cy - cx;  // First condition difference
            int d2 = cz - cy;  // Second condition difference
            int d3 = cw - cz;  // Third condition difference
            int d4 = cb - cw;  // Fourth condition difference

            // Increment count based on how many times (d1, d2, d3, d4) was achieved
            count += freq[{d1, d2, d3, d4}];

            // Update frequency of (d1, d2, d3, d4)
            freq[{d1, d2, d3, d4}]++;
        }

        return count;
    }
};

int main() {
    int n, x, y, z, w, b;
    cin >> n >> x >> y >> z >> w >> b;  // Input the size and the distinct integers
    Solution sol;
    cout << sol.countValidSubarrays(n, x, y, z, w, b) << endl;  // Output the result
    return 0;
}

