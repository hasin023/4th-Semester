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


pair<int, int> findPeak(vector<vector<int>> &v)
{
    int row = v.size();
    int col = v[0].size();

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            bool isPeak = true;
            if (i > 0)
            {
                if (v[i][j] < v[i - 1][j])
                {
                    isPeak = false;
                }
            }
            if (i < row - 1)
            {
                if (v[i][j] < v[i + 1][j])
                {
                    isPeak = false;
                }

                isPeak= (v[i][j]<v[i+1][j]) ?false:true;
            }
            if (j > 0)
            {
                if (v[i][j] < v[i][j - 1])
                {
                    isPeak = false;
                }
            }
            if (j < col - 1)
            {
                if (v[i][j] < v[i][j + 1])
                {
                    isPeak = false;
                }
            }
            if (isPeak)
            {
                return {i, j};
            }
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