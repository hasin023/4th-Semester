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

ll t;
ll a;
ll b;
ll c;
ll d;
ll e;
ll f;
ll fibo[10005];

int fn( int n ) {
	for (int i = 0; i <= n; i++) {

    	if( i == 0 ) {
			fibo[i] = a;
			continue;
		}
	    if( i == 1 ) {
			fibo[i] = b;
			continue;
		}
    	if( i == 2 ) {
			fibo[i] = c;
			continue;
		}
	    if( i == 3 ) {
			fibo[i] = d;
			continue;
		}
    	if( i == 4 ) {
			fibo[i] = e;
			continue;
		}
	    if( i == 5 ) {
			fibo[i] = f;
			continue;
		}
    	fibo[i] = fibo[i-1] + fibo[i-2] + fibo[i-3] + fibo[i-4] + fibo[i-5] + fibo[i-6];
		fibo[i] = fibo[i] % 10000007;

	}

	return fibo[n];
}

int main()
{


	long long ans,n;

	
	cin >> t;

	for (long long i = 1; i <= t; i++) {
		cin >> a;
		cin >> b;
		cin >> c;
		cin >> d;
		cin >> e;
		cin >> f;
		cin >> n;

		ans = fn(n);
		ans = ans % 10000007;

		cout << "Case "<< i <<": "<< ans << endl;
	}


}

		
