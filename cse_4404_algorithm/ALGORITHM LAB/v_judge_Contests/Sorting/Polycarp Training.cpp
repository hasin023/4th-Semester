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
    the_flash;

    int n;
    cin >> n;
    set<int> s;
    fr(i, n)
    {
        int x;
        cin >> x;
        s.insert(x);
    }

    sort(s);

    for(auto it=s.begin();it!=s.end();it++)
    {
        cout<<*it<<endl;
    }

    return 0;
}
