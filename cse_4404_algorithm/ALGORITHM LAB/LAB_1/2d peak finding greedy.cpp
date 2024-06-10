
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
#define N 100000+10
#define MAX LONG_MAX
#define INF INT_MAX
#define tc     int tc; cin>>tc; while(tc--)
#define the_flash ios_base ::sync_with_stdio(0);cin.tie(0);
using namespace std;
int find_peak(vector<vector<ll>> v, int n, int m)
{
    int sn = n / 2, sm = m / 2;
    int rs = -INF, ls = -INF, us = -INF, ds = -INF;

    if (sn - 1 >= 0)
        ls = v[sn - 1][sm];
    if (sn + 1 < n)                                                         
        rs = v[sn + 1][sm];
    if (sm - 1 >= 0)
        us = v[sn][sm - 1];
    if (sm + 1 < m)
        ds = v[sn][sm + 1];

    int mx = max({ls, rs, us, ds});
    if (v[sn][sm] >= mx)
        return v[sn][sm];

    if (mx == ls)
        return find_peak(v, sn - 1, sm);
    else if (mx == rs)
        return find_peak(v, sn + 1, sm);
    else if (mx == us)
        return find_peak(v, sn, sm - 1);
    else
        return find_peak(v, sn, sm + 1);
}
int main()
{
the_flash;

return 0;
}
