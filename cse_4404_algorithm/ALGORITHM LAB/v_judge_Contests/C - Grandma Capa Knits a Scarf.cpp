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
        int n;
        cin >> n;
        string s;
        cin >> s;

        int st=0;
        int end=n-1;

        int pali=0;
        while(st>end)
        {
            if(s[st]!=s[end])
            {
                if(s[st+1]==s[end-1] && st+1<n  && end-1>=0)
                {
                    st++;
                }
                else {
                    end--;
            }
            }
            else if(s[st]==s[end])
            {
                st++;
                end--;
                pali+=2;
            }
        }

        cout<<n-pali<<endl;
    }
    return 0;
}