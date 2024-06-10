//bismillahir rahmanir rahim
#include<bits/stdc++.h>
#include<time.h>
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


int findPeak(int arr[], int n)
{
    if (n == 1)
    {
        return arr[0];
    }
    if (arr[0] >= arr[1])
    {
        return arr[0];
    }
    if (arr[n - 2] <= arr[n - 1])
    {
        return arr[n - 1];
    }

    int low = 1, high = n - 2;
    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] >= arr[mid - 1] and arr[mid] >= arr[mid + 1])
        {
            return arr[mid];
        }
        else if (arr[mid] >= arr[mid - 1]) 
        {
            low = mid + 1;
        }
        else 
        {
            high = mid - 1;
        }
    }

    return -1;
}

int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    
    auto start = chrono::high_resolution_clock::now();

    for (int i = 0; i < n; i++)
    {
        arr[i]=i+1;
    }

    cout << findPeak(arr, n) << endl;
  
    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double>duration = end-start;

    cout<<"Taken Time :"<<duration.count()*10000<<endl;
    return 0;
}