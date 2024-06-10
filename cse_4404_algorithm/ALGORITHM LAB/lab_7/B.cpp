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
#define MAX LONG_MAX
#define tc     int tc; cin>>tc; while(tc--)
#define the_flash ios_base ::sync_with_stdio(0);cin.tie(0);
using namespace std;


int main() {
    int N, K;
   cin >> N >> K;
    
    int h[N];
    for (int i = 0; i < N; ++i) {
        cin >> h[i];
    }
    
    int dp[N];
    dp[0] = 0; 
    
    for (int i = 1; i < N; ++i) {
        dp[i] = INT_MAX;
        for (int j = 1; j <= K && i - j >= 0; ++j) {
            dp[i] = min(dp[i], dp[i - j] +abs(h[i] - h[i - j]));
        }
    }
    
    cout << dp[N - 1] << endl;
    
    return 0;
}