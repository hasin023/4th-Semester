// Recursive C++ program for
// coin change problem.
#include <bits/stdc++.h>
using namespace std;

int dp[4005] ;
int count(int coins[], int n, int sum)
{

    if (sum == 0)
        return 1;

    if (sum < 0)
        return 0;

    if (n <= 0)
        return 0;
    if(dp[sum]!=-1)
    {
        return dp[sum];
    }
    return dp[sum] = count(coins, n, sum - coins[n - 1]) + count(coins, n - 1, sum);
}

int main()
{

    int coins[3];

    int sum = 7;

    cin >> sum;
    for(int i=0;i<=4005;i++)
    {
        dp[i]=-1;
    }
    for (int i = 0; i < 3; i++)
    {
        cin >> coins[i];
    }
    cout << " " << count(coins, 3, sum);

    return 0;
}
