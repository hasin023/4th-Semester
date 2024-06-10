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
    cin>>n;

    vector<int>v(n);

    fr(i,n)
    {
        cin>>v[i];
    }

    sort(v);

    int cnt=0;
    fr(i,n-1)
    {
        if(i%2==0)
        cnt+=(v[i+1]-v[i]);
    }

    cout<<cnt<<endl;
    return 0;
}