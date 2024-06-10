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

ll dp[4005];

int main()
{
    the_flash;
    ll n, a, b, c;


    cin >> n >> a >> b >> c;
    for (ll i = 0; i <= n; i++)
    {
        dp[i] = INT_MIN;
    }
    dp[0]=0;

    if (a <= n)
        dp[a] = 1;
    if (b <= n)
        dp[b] = 1;
    if (c <= n)
        dp[c] = 1;

    for (ll i = 0; i <= n; i++)
    {
        if (i - a >= 0)
            dp[i] = max(dp[i], dp[i - a] + 1);
        if (i - b >= 0)
            dp[i] = max(dp[i], dp[i - b] + 1);

        if (i - c >= 0)
            dp[i] = max(dp[i], dp[i - c] + 1);
    }

    cout<<dp[n]<<endl;
    return 0;
}