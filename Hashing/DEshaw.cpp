/*Understanding : We are given an array B of size “N”; Divide the array into 4 continuous parts such that g = part1 -part2 +part3 -part4 is maximized. 

Any part is allowed to be empty as well ; but collectively they should cover the whole array 
*/


#include <bits/stdc++.h>

using namespace std;
typedef long long int ll ; 
int main() {
    
    ll n;
    cin>>n;
    ll b[n+1]={0};
    ll tot = 0 ; 
    ll i = 1 ; 
    while(i<=n){
        cin>>b[i];
        tot+=b[i];
        i++;
    }
    
    ll p[n+5]={0};
    
    i = 1 ; 
    while(i<=n){
        //prefix can start  must be a contiguous subarray that ends exactly at your first cut.
        p[i] = min(b[i],b[i]+p[i-1]);
        
        i++;
    }
    
    ll s[n+5]={0};
    i = n ; ll sum = 0 ; 
    while(i>=1){
        sum = sum + b[i];
        s[i] = min(sum,s[i+1]);// the suffix at any cost shall alwas end at the last element 
        i--;
    }
    
    i = 0 ;
    ll t = 0 ; ll d = 1e18;
    while(i<=n){
        
        ll v = min(t,p[i]) + min(s[i+1],t);
        d = min(d,v);
        
        i++;
    }
    cout<<tot-2*d;
    //cout<<d;
    
    return 0 ;
    
}



/***Understanding the code logic**

The user posted C++ code to divide an array into four parts, maximizing the value of `g = part1 - part2 + part3 - part4`. The focus is on understanding "2\*d" in the final calculation and the use of prefix and suffix sums.

The `p[i]` represents the minimal subarray sum up to index `i`, and `s[i]` represents the minimal subarray sum from index `i` to the end. The code builds these sums iteratively, possibly calculating alternating minimal subarrays.

**Breaking down the calculation logic**

The variable `v = min(0, p[i]) + min(s[i+1], 0)` helps evaluate the minimal possible sum of two subarrays. By definition, `p[i]` is the minimum sum of a prefix (which is ≤ 0), and `s[i+1]` is the minimum sum of a suffix (also ≤ 0). The goal is to minimize the sum of certain contiguous subarrays (segments 2 and 4), which is then used in computing the maximum alternating sum `g`. Essentially, maximizing `g` is equivalent to minimizing the sum of specific segments.

**Clarifying subarray logic**

In this approach, part2 and part4 are non-overlapping subarrays that aim to minimize the sum when combined. At each partition boundary `i`, the code calculates the minimal subarray sum for both part2 (ending at `i`) and part4 (starting at `i+1`). This approach combines a prefix minimal sum (`p[i]`) and a suffix minimal sum (`s[i+1]`). The goal is to minimize the combined sum of these segments, which contributes to maximizing the alternating sum `g`. The transformation `g = total - 2*d` is derived from minimizing the sums of part2 and part4.


Thought for 14 seconds


Let’s unpack the two pieces you’re asking about:

---

## 1. Why `tot – 2*d`?

You want to maximize

$$
g \;=\; \underbrace{S_1}_{\sum\text{(part1)}} 
        \;-\;\underbrace{S_2}_{\sum\text{(part2)}} 
        \;+\;\underbrace{S_3}_{\sum\text{(part3)}}
        \;-\;\underbrace{S_4}_{\sum\text{(part4)}}.
$$

But if you let

$$
T = S_1 + S_2 + S_3 + S_4
$$

be the total sum of the entire array (which your code calls `tot`), then a little algebra shows

$$
\begin{aligned}
g
&= S_1 - S_2 + S_3 - S_4
\\
&= (S_1 + S_2 + S_3 + S_4)
  \;-\;2\,(S_2+S_4)
\\
&= T \;-\; 2\,(S_2+S_4).
\end{aligned}
$$

Since $T = \text{tot}$ is fixed, **maximizing** $g$ is equivalent to **minimizing**

$$
d \;=\; S_2 + S_4.
$$

Hence, once you’ve found the minimum possible sum of part2 + part4 (that’s your `d`), you plug it in:

```cpp
answer = tot - 2*d;
```

---

## 2. How the “suffix‐sum” array `s[i]` works

Part 4 is the *last* segment, so it must be a contiguous suffix ending at index $n$.  We want to know, for each possible cut‐point $i$, what the *smallest* suffix‐sum we can choose that **starts at or after** $i$.  We also allow part 4 to be empty (i.e.\ sum = 0) if every suffix is positive.

Your code does this in two steps:

1. **Scan from right to left** maintaining

   ```cpp
   sum = B[i] + sum;        // running total of B[i..n]
   s[i] = min( sum, s[i+1] );
   ```

   * `sum` is literally $\sum_{j=i}^n B[j]$, the sum of the suffix that *begins* at i.
   * `s[i+1]` is “the best (i.e. smallest) suffix‐sum we’ve seen so far starting at ≥ i+1.”
   * Taking `min(sum, s[i+1])` then gives

     $$
       s[i] \;=\; \min\bigl(\sum_{j=i}^n B[j],\; \text{best suffix from }i+1\text{ onward}\bigr),
     $$

     which is precisely “the minimum sum of any suffix that starts at or after i.”

2. Later, when you choose a boundary at $i$, you use

   ```cpp
   min( s[i+1], 0LL )
   ```

   i.e. if every suffix starting at ≥ i+1 is *positive*, you’d rather take an empty part4 (sum = 0) than pay a positive cost.  Otherwise you pick the most‐negative suffix (to reduce $d=S_2+S_4$).

---

### Putting it all together

1. **Prefix pass** builds

   ```cpp
   p[i] = min( b[i], b[i] + p[i-1] );
   ```

   so that `p[i]` is the *most negative* (or zero) contiguous subarray sum *ending at* i—i.e.\ your choice for part 2 if you cut just after i.

2. **Suffix pass** builds

   ```cpp
   s[i] = min( sum_of_b[i..n],  s[i+1] );
   ```

   so that `s[i]` is the *most negative* (or zero) contiguous suffix starting *at or after* i—i.e.\ your choice for part 4 if you cut just before i.

3. You try **every** cut between i and i+1, compute

   $$
     d_i 
     = \underbrace{\min(p[i],\,0)}_{\text{best part2 ending at }i}
     \;+\;
     \underbrace{\min(s[i+1],\,0)}_{\text{best part4 starting at }i+1}},
   $$

   keep the global minimum $d=\min_i d_i$, and then return

   $$
     \boxed{ g_{\max} \;=\;\text{tot} \;-\; 2\,d }.
   $$

I hope this clarifies both the algebraic “2⋅d” step and the suffix‐sum logic! Let me know if you’d like any more detail on a particular line.
*/