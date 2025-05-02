/*Understanding :- We will give you a string ; for each char in the string tell us how many times is it appearing in all the substrings of original string ; once you have calculated it -> answer is the char with highest frequency if multiple char have highest frequency then print the smallest char 



s = “abca”

a = 10
b = 7 
c = 7 

ans =a*/


#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>> s;
    int n =s.size();

    unordered_map<char,int>mp;

    for(int i=0;i<n;i++){
        int x =i;
        int y = n-i-1;
        mp[s[i]] = mp[s[i]] +x*y + x+y+1;

    }

    char answer ;
    int max =0;
    for(auto u : k){
        if frequency = u.second;
        if(frequency > max){
            max = frequency;
            answer = u.first;
        }
    }
    cout<<answer<<endl;
    return 0;
}