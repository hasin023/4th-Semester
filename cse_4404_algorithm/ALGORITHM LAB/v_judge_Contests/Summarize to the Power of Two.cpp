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

int main()
{
    int n, res=0;
    cin >> n;
    vector<int> a(n);
    map<int, int> mp;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        mp[a[i]]++;
    }
    for (int i = 0; i < n; ++i)
    {
        bool check = false;
        for (int j = 0; j < 31; ++j)
        {
            int x = (1 << j) - a[i];
            if (mp.count(x) && (mp[x] > 1 || mp[x] == 1 && x != a[i]))
            {
                check = true;
            }
        }
        if (!check)
        {
            res++;
        }
    }
    cout << res;
}