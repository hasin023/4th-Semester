//bismillahir rahmanir rahim
#include<bits/stdc++.h>
#define F first
#define S second
#define ll long long
#define pb push_back
#define sort(s) sort(s.begin(),s.end())
#define sortarr(a) sort(a, a+n)
#define fr(i,n) for(int i=0;i<n;i++)
#define frone(i,n) for(int i=1;i<=n;i++)
#define reverse(s) reverse(s.begin(),s.end())
#define MAX LONG_MAX
#define tc     int tc; cin>>tc; while(tc--)
#define the_flash ios_base ::sync_with_stdio(0);cin.tie(0);
using namespace std;
#define MAXN 1000001
#define MOD 1000000007

int DP[MAXN], n;

int compute(int x)
{
    if (DP[x] != 0)
    {
        return DP[x];
    }
    for (int i = 1; i <= 6; i++)
    {
        if (x - i >= 0)
        {
            DP[x] += compute(x - i);
            DP[x] %= MOD;
        }
    }
    return DP[x];
}

int main()
{
    cin >> n;
    memset(DP, 0, sizeof(DP));
    DP[0] = 1;
    cout << compute(n) << endl;
}