// bismillahir rahmanir rahim
#include <bits/stdc++.h>
#define F first
#define S second
#define ll long long
#define pb push_back
#define sort(s) sort(s.begin(), s.end())
#define sortarr(a) sort(a, a + n)
#define fr(i, n) for (int i = 0; i < n; i++)
#define frone(i, n) for (int i = 1; i <= n; i++)
#define reverse(s) reverse(s.begin(), s.end())
#define N 100000 + 10
#define MAX LONG_MAX
#define tc     \
    int tc;    \
    cin >> tc; \
    while (tc--)
#define the_flash                  \
    ios_base ::sync_with_stdio(0); \
    cin.tie(0);
using namespace std;

ll maxCrossingSum(ll arr[], ll l, ll m, ll h) { 

    ll sum = 0; 
    ll left_sum = INT_MIN; 
    for (ll i = m; i >= l; i--) { 
        sum = sum + arr[i]; 
        if (sum > left_sum) 
            left_sum = sum; 
    } 
  

    sum = 0; 
    ll right_sum = INT_MIN; 
    for (ll i = m; i <= h; i++) { 
        sum = sum + arr[i]; 
        if (sum > right_sum) 
            right_sum = sum; 
    } 
  

    return max({left_sum + right_sum - arr[m], left_sum, right_sum}); 
} 
  

ll maxSubArraySum(ll arr[], ll l, ll h) { 
 
    if (l > h) 
        return INT_MIN; 

    if (l == h) 
        return arr[l]; 

    ll m = (l + h) / 2; 
  

    return max({maxSubArraySum(arr, l, m - 1), 
               maxSubArraySum(arr, m + 1, h), 
               maxCrossingSum(arr, l, m, h)}); 
} 
  
int main()
{
    the_flash;

    ll n;
    cin>>n;

    ll arr[n];

    fr(i,n)
    {
        cin>>arr[i];
    }

    cout<<(long long)maxSubArraySum(arr,0,n-1)<<endl;
    return 0;
}