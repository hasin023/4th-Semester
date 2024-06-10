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
    tc
    {
        ll n;
        cin >> n;

        ll count = 0;
        ll count_zero = 0;
        ll x;
        fr(i, n)
        {

            cin >> x;
            if (x == 1)
            {

                count++;
            }
            else if (x == 0)
            {
                count_zero++;
            }
        }
        ll ans = (ll)count * pow(2, count_zero);
        cout << ans << endl;
    }
    return 0;
}