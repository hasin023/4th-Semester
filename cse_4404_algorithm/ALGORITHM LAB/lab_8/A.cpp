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

int knapsack(int maxWeight, vector<pair<int,int>> &items)
{
    int n = items.size();
    vector<vector<int>> dp(n + 1, vector<int>(maxWeight + 1, 0));

    for (int i = 1; i <= n; ++i)
    {
        for (int w = 1; w <= maxWeight; ++w)
        {
            if (items[i - 1].second <= w)
            {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - items[i - 1].second] + items[i - 1].first);
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][maxWeight];
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int N;
        cin >> N;

        vector<pair<int,int>> items(N);
        for (int i = 0; i < N; ++i)
        {
            cin >> items[i].first >> items[i].second;
        }

        int G;
        cin >> G;

        int totalValue = 0;
        for (int i = 0; i < G; ++i)
        {
            int cap;
            cin >> cap;
            totalValue += knapsack(cap, items);
        }

        cout << totalValue << endl;
    }

    return 0;
}