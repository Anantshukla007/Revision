/*Problem Restatement
We have a permutation arr[1..n] of the numbers 
1
1 through 
𝑛
n.

We consider every contiguous subarray of arr, compute its MEX, then collect all those MEX values into one big list, sort them, and ask: what is the 
𝑘
k-th smallest MEX in that list?

Equivalently, we want to know which integer 
𝑀
M is the first integer for which the total number of subarrays whose MEX is 
≤
𝑀
≤M is at least 
𝑘
k. (Because sorting all the MEXes and picking the 
𝑘
k-th is exactly that.)*/


Input:
    arr = [3, 2, 1, 4],   n = 4,   k = 5
    Positions: kk[1]=3, kk[2]=2, kk[3]=1, kk[4]=4

We will compute answer[m] = #subarrays with MEX = m,
then accumulate c += answer[m] until c >= k.

-------------------------------------------------------------------------------
m = 1:
  “Required set” is empty ⇒ subarray must simply avoid “1”.

  pos1 = kk[1] = 3
  # subarrays entirely left of index 3:
      L,R ∈ {1,2}  ⇒  (2·3)/2 = 3
      (these are [3], [2], [3,2])

  # subarrays entirely right of index 3:
      L,R ∈ {4}    ⇒  (1·2)/2 = 1
      (this is [4])

  answer[1] = 3 + 1 = 4
  c = 4   (still < k=5, continue)

  Window [left..right] ← [3..3]   (we’ll cover value 1 going forward)

-------------------------------------------------------------------------------
m = 2:
  “Required set” = {1}.  Current window covers index 3.
  pos2 = kk[2] = 2

  Since pos2 < left, we do:
    x = left - pos2 - 1 = 3 - 2 - 1 = 0
    y = n - right      = 4 - 3     = 1
    answer[2] = (x+1)*(y+1) = 1 * 2 = 2

  These two subarrays both cover [2..3] = {positions of 2 and 1}
  but exclude pos2=2—i.e. left end must be 3, right end 3 or 4:
     [1], [1,4]

  c = 4 + 2 = 6   (now ≥ k=5 → stop)

Answer = m = 2
-------------------------------------------------------------------------------

Sorted list of all 10 subarray‑MEXes (for verification):
 [1,1,1,1,2,2,3,3,4,5]  ⇒ 5th element = 2.




 #include<bits/stdc++.h>
 using namespace std ; 
 typedef long long int ll ;
 
 int main(){
     ll n;
     cin>>n;
     ll b[n+1]={0};
     map<ll,ll> kk ; 
     ll i = 1;
     while(i<=n){
         cin>>b[i];
         kk[b[i]] = i ; 
         i = i + 1 ;
     }
     //cout<<kk[1];
     //cout<<'\n';
     ll k;
     cin>>k ; 
     ll answer[n+5]={0};
     ll left = kk[1];
     ll right = kk[1];
     ll n1 = left - 1 ;
     ll n2 = n - right;
     //cout<<n1<<" "<<n2;
     //cout<<'\n';
     answer[1] = (n1*(n1+1)/2) + (n2*(n2+1)/2) ;
     i = 2; 
     while(i<=n){
     ll id = kk[i] ; 
     if(left>id && right>id){
         ll x = left - id - 1; 
         ll y = n - right ; 
         answer[i] = (x+1)*(y+1);
     }
     else if(left<id && right<id){
         ll x = left - 1; 
         ll y = id - right - 1 ; 
         answer[i] = (x+1)*(y+1);
     }
     else{
         
     }
     
     left = min(left,id);
     right = max(right,id);
     i++;
 }
 
 answer[n+1] = 1 ; 
 
 ll c = 0 ; 
 ll TopG = 0 ; 
 i = 1 ; 
 while(i<=n+1){
     
     //cout<<i<<" "<<answer[i];
     //cout<<'\n';
     
     c = c + answer[i];
     
     if(c<k){
         
     }
     else{
         TopG = i ;
         i = n + 5; 
         break;
     }
 
     
     i = i + 1 ;  
 }
 
 
 cout<<(TopG);
 return 0;
 }
 /*
 4
 3 2 1 4 
 5
 
 */
 