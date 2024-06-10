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
ll dp[109][100009], W, n;
ll a[109], b[109];

ll solve(ll r, ll idx)
{
    if (idx == n)
    {
        return r == 0 ? 0 : 1e12;
    }

    if (dp[idx][r] != -1)
    {
        return dp[idx][r];
    }

    ll ans = solve(r,idx+1);

    if(b[idx]<=r)
    {
        ans=min(ans,a[idx]+solve(r-b[idx],idx+1));
    }


    return dp[idx][r]=ans;
}

ll sol(ll v_max)
{
    for (ll i = v_max; i >= 0; i--)
    {
        if (solve(i, 0) <= W)
        {
            return i;
        }
    }

    return 0;
}
int main()
{
    the_flash;

    ll v_max;
    cin >> n >> W;

    memset(dp, -1, sizeof(dp));

    v_max = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];

        v_max += b[i];
    }


    cout<<sol(v_max)<<endl;
    return 0;
}
