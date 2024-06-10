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

vector<vector<int>> dp(3000 + 1, vector<int>(3000 + 1, 0));
void lcs(string a, string b)
{
    int n = a.size();
    int m = b.size();

    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }

    for (int j = 0; j <= m; j++)
    {
        dp[0][j] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    int len = dp[n][m];
    string ans = "";

    for (int i = 0; i < len; i++)
    {
        ans += '$';
    }

    int index = len - 1;
    while (n > 0 && m > 0)
    {
      
        if (a[n - 1] == b[m - 1])
        {
            ans[index] = a[n - 1];
            index--;
            n--;
            m--;
        }
        else if (dp[n - 1][m] > dp[n][m - 1])
        {
            n--;
        }
        else
        {
            m--;
        }
    }

    cout << ans << endl;
}

// void traceback(int i, int j){

//  if(i == 0|| j == 0)return;

//  if(a[i-1] == b[j-1]) {
//  traceback(i-1, j-1);
//  cout << a[i-1];
//  }
// else if( dp[ i ][ j ] > max(dp[ i-1][ j ],dp[ i ][ j-i ] ))
// traceback(i,j-1);
// }
int main()
{
    the_flash;
    string a, b;
    cin >> a >> b;

    lcs(a, b);
    return 0;
}