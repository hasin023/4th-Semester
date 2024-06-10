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

int findMaxIndex(vector<vector<int>> &v, int n, int m, int col)
{
    int maxVal = -1;
    int index = -1;

    for (int i = 0; i < n; i++)
    {
        if (v[i][col] > maxVal)
        {
            maxVal = v[i][col];
            index = i;
        }
    }

    return index;
}

pair<int, int> findPeak(vector<vector<int>> v)
{
    int row = v.size();
    int col = v[0].size();

    int low = 0, high = col - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        int maxRowIndex = findMaxIndex(v, row, col, mid);
        int left = mid - 1 >= 0 ? v[maxRowIndex][mid - 1] : -1;
        int right = mid + 1 < col ? v[maxRowIndex][mid + 1] : -1;
.
        if (v[maxRowIndex][mid] >= left and v[maxRowIndex][mid] >= right)
        {
            return {maxRowIndex, mid};
        }
        else if (v[maxRowIndex][mid] < left)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return {-1, -1};
}
int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);

    vector<vector<int>> v;

    int row, col;
    cin >> row >> col;
    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < row; i++)
    {
        vector<int> temp;
        for (int j = 0; j < col; j++)
        {
            
            temp.push_back(j*(i+1)+1);
        }
        v.push_back(temp);
    }

    auto it = findPeak(v);

    cout << it.first << " " << it.second << endl;
  auto end = chrono::high_resolution_clock::now();

    chrono::duration<double>duration = end-start;

    cout<<"Taken Time :"<<duration.count()*10000<<endl;
    return 0;
}