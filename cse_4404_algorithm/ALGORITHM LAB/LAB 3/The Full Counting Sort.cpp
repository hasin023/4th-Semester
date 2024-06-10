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
#define MAX LONG_MAX
#define tc     \
    int tc;    \
    cin >> tc; \
    while (tc--)
#define the_flash                  \
    ios_base ::sync_with_stdio(0); \
    cin.tie(0);
using namespace std;
vector<string> countSort(vector<pair<int, string>> &inputArray, int mid)
{

    int N = inputArray.size();

    int M = 0;

    for (int i = 0; i < N; i++)
        M = max(M, inputArray[i].first);

    vector<int> countArray(M + 1, 0);

    for (int i = 0; i < N; i++)
        countArray[inputArray[i].first]++;

    for (int i = 1; i <= M; i++)
        countArray[i] += countArray[i - 1];

    vector<string> outputArray(N);

    for (int i = N - 1; i >= 0; i--)

    {
        if (i >= mid)
        {
            outputArray[countArray[inputArray[i].first] - 1] = inputArray[i].second;
        }
        else
        {
             outputArray[countArray[inputArray[i].first] - 1] ="-";
        }
        countArray[inputArray[i].first]--;
    }

    return outputArray;
}
int main()
{
    the_flash;
    int n;
    cin >> n;

    vector<pair<int, string>> v;
    int a;
    string s;
    for (int i = 0; i < n; i++)
    {

        cin >> a >> s;

        v.push_back({a, s});
    }

    int mid = ceil(n / 2);

    // for (int i = 0; i < n; i++)
    // {

    //     cout<<v[i].first<<" "<<v[i].second<<endl;
    // }
    vector<string> output = countSort(v,mid);

    fr(i, n)
    {
        
            cout << output[i] << " ";
    }
    return 0;
}
