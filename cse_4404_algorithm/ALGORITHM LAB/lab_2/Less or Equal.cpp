// bismillahir rahmanir rahim
#include <bits/stdc++.h>
#define F first
#define S second
#define ll long long
#define pb push_back
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

    int n, k;
    cin >> n >> k;

    int v[n+1];
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }

    sort(v+1,v+n+1);

//   for(int i=1;i<=n;i++)
//   {
//     cout<<v[i]<<" ";
//   }
//   cout<<endl;
    if (k == 0)
    {
        if (v[1] == 1)
        {
            cout << -1 << endl;
            return 0;
        }
        else
        {
            cout << v[1] - 1 << endl;
            return 0;
        }
    }

    if (v[k] != v[k + 1])
    {
        cout << v[k] << endl;
    }
    else
    {
        cout << -1 << endl;
    }

    return 0;
}