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

    int n;
    cin >> n;
    vector<int>v(n);

    fr(i, n)
    {
        cin >> v[i];
    }

    sort(v.begin(),v.end());

    int mini = abs(v[1]-v[0]);
    vector<pair<int,int>>mini_ind;
    fr(i, n-1)
    {
        if(abs(v[i]-v[i+1])<=mini)
        {
            mini=abs(v[i]-v[i+1]);
        }
        
    }

    fr(i,n-1)
    {
          if(abs(v[i]-v[i+1])==mini)
        {
            cout<<v[i]<<" "<<v[i+1]<<" ";
        }
    }
    
    return 0;
}