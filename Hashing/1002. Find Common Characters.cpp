/*Given a string array words, return an array of all characters that show up in all strings within the words (including duplicates). You may return the answer in any order.

 

Example 1:

Input: words = ["bella","label","roller"]
Output: ["e","l","l"]
Example 2:

Input: words = ["cool","lock","cook"]
Output: ["c","o"]
 */

#include<bits/stdc++.h>
using namespace std;

vector<string>commonchars(vector<string>&words){
    vector<string>result;

    vector<string>minfreq(26,INT_MAX);

    for(auto word:words){
        vector<int>freq(26,0);
        for(char:word){
            freq[c-'a']++;
        }

        for(int i=0;i<26;i++){
            minfreq[i] = min(minfreq[i,freq[i]]);

        }
    }

    for(int i=0;i<26,i++){
        while(minfreq>0){
            result.push_back(string,1,i+'a');
            minfreq[i]--;
        }
    }
    return result;
}