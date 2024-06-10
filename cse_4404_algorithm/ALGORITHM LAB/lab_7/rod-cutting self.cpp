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

 ll arr[100005];
 ll dp[100005];
ll cutRod(ll arr[], ll size, ll n)
{
    if (n == 0)
    {
        return 0;
    }

    if(dp[n]!=-1)
    {
        return dp[n];
    }
 ll maxi=LONG_LONG_MIN;
    for (ll i = 1; i <= size; i++)
    {
        ll firstCutPrice = arr[i];
         
        if (n - i >= 0)
        {
            ll secondCutPrice = cutRod(arr, size, n - i);
            maxi = max(maxi, firstCutPrice + secondCutPrice);

           
        }
    }
    dp[n]=maxi;
    return maxi;
}
int main()
{
    the_flash;
    ll n, x;
    cin >> x ;
    for(ll i=0;i<=100005;i++)
    {
        dp[i]=-1;
    }
    n=x;
    for (ll i = 1; i <= x; i++)
    {
        cin >> arr[i];
    }

    cout << cutRod(arr, x, n);
    return 0;
}