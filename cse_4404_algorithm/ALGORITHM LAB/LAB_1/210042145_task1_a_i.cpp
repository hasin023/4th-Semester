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
int arr[10000007];
using namespace std;


int peakFind(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if ((i == 0 or arr[i - 1] <= arr[i]) and (i == n - 1 or arr[i] >= arr[i + 1]))
        {
            return arr[i];
        }
    }
}

int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

       auto start = chrono::high_resolution_clock::now();
    for(int i=0;i<n;i++)
    {
       arr[i]=i+1;
    }

    cout<<peakFind(arr,n)<<endl;
      
    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double>duration = end-start;

    cout<<"Taken Time :"<<duration.count()*10000<<" ms"<<endl;

    return 0;
}