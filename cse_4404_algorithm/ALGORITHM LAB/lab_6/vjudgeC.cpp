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

    ll n, x, y;
    cin >> n >> x >> y;

    ll arr[n + 1];
    ll pref[n + 1];
    arr[0] = 0;
    pref[0] = 0;
    frone(i, n)
    {
        cin >> arr[i];
        pref[i] = arr[i];
    }

    priority_queue<ll> pq;
    for (int i = 1; i <= n; i++)
    {
        pref[i] += pref[i - 1];

        pq.push(pref[i]);
    }

    while(!pq.empty())
    {
        cout<<pq.top()<<endl;
        pq.pop();
    }

    // ll prev_sum = INT_MIN;
    // for (int i = x; i <= y; i++)
    // {
    //     ll firstSum = INT_MIN;
    //     for (int j = 0; j <= n - i; j++)
    //     {

    //         firstSum = max(firstSum, pref[j + i] - pref[j]);
    //     }

    //     prev_sum = max(prev_sum, firstSum);
    // }

    // cout << prev_sum << endl;
    return 0;
}