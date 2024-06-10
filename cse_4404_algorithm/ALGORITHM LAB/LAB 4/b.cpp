#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define caseout(n) cout << "Case " << n << ": "

const ll MOD = 1e9+7;//998244353;
const ll INF = 1e18;
const int MAX = 2e5+5;


double dist(ll v, ll s0, double t)
{
    return v*t+s0;
}

double dif(vector<ll> &v, vector<ll> &s0, double t)
{
    double mx = -INF, mn = INF;
    for(int i = 0; i < v.size(); i++)
    {
        mx = max(mx, dist(v[i], s0[i], t));
        mn = min(mn, dist(v[i], s0[i], t));
    }
    return mx-mn;
}

void solve(int tcase)
{
    ll n, k; cin >> n >> k;
    vector<ll> v(n), s0(n);
    for(int i = 0; i < n; i++) cin >> v[i] >> s0[i];

    double l = 0, r = k;
    while(r-l >= 1e-9)
    {
        double ml = l + (r-l)/3;
        double mr = r - (r-l)/3;
        double fl = dif(v, s0, ml);
        double fr = dif(v, s0, mr);
        if(fl < fr) r = mr;
        else l = ml;
    }

    cout << fixed << setprecision(6) << dif(v, s0, l);


    cout << '\n';
}



signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    




    int t = 1;
    // cin >> t;
    for(int tcase = 1; tcase <= t; tcase++) solve(tcase);

    return 0;
}