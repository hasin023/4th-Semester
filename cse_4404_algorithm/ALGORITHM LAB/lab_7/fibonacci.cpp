//bismillahir rahmanir rahim
#include<bits/stdc++.h>
#define F first
#define S second
#define ll long long
#define pb push_back
#define sort(s) sort(s.begin(),s.end())
#define sortarr(a) sort(a, a+n)
#define fr(i,n) for(int i=0;i<n;i++)
#define frone(i,n) for(int i=1;i<=n;i++)
#define reverse(s) reverse(s.begin(),s.end())
#define N 100000+10
#define MAX LONG_MAX
#define tc     int tc; cin>>tc; while(tc--)
#define the_flash ios_base ::sync_with_stdio(0);cin.tie(0);
using namespace std;
int fibo[10000];

int fib(int n)
{
    if(n==1 || n==0) 
    {
        return 1;
    }

    if(fibo[n]!=0)
    {
        return fibo[n];
    }

   fibo[n]= fib(n-1)+fib(n-2);
   return fibo[n];
}

int main()
{
the_flash;
fibo[0]=1;
fibo[1]=1;
    cout<<fib(8)<<endl;

return 0;
}