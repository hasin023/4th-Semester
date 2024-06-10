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

    vector<int> v(n);

    fr(i, n)
    {
        cin >> v[i];
    }

    int total_stairway = 0;
    int total_stair_cnt = 0;

    vector<int> x;
    for (int i = 0; i < n; i++)
    {
        total_stair_cnt++;
        if (v[i] == 1)
        {
            total_stairway++;

            if(v[i]==1 && i!=0)
            {
                x.pb(total_stair_cnt-1);
                total_stair_cnt=1;
            }
        }

        if(i==n-1 && total_stairway>0)
        {
            x.pb(total_stair_cnt);
        }

    }

    cout << total_stairway << endl;

    fr(i, x.size())
    {
        cout << x[i] << " ";
    }
    return 0;
}