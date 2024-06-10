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

    string s;
    cin>>s;

    string p="";
    for(int i=0;i<s.size();i++)
    {   
        if(s[i]=='B' && p.length())
        {
            p.pop_back();
        }
        else if(s[i]=='B' && p.length()==0)
        {

        }
        else{
        p+=s[i];
        }


    }
    cout<<p<<endl;
   
    return 0;
}