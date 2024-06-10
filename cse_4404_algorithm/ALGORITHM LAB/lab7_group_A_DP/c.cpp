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
ll mod = 1e9 + 7;

int totalPath(int n)
{
}

int main()
{
    the_flash;
    int n;
    cin >> n;
    char grid[n][n];
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }
    dp[0][0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == '*')
            {
                dp[i][j] = 0;
                continue;
            }

            if (i > 0)
            {
                dp[i][j] += dp[i - 1][j] % mod;
            }
            if (j > 0)
            {
                dp[i][j] += dp[i][j - 1] % mod;
            }
        }
    }
    cout << dp[n-1][n-1]%mod << endl;
    return 0;
}