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

void insertionSort(int n, vector<int> &arr)
{
    for (int i = 1; i < n; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        for (; j >= 0; j--)
        {
            if (temp < arr[j])
            {
                arr[j + 1] = arr[j];
            }
            else
            {
                break;
            }
        }
        arr[j + 1] = temp;
    }
}
int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);
     int n;
    n=1000000;
    freopen("C:/Users/Hp/Downloads/random_numbers.txt","r",stdin);
vector<int>v(10000007);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }

   auto start = chrono::high_resolution_clock::now();
    insertionSort(n,v);
  auto end = chrono::high_resolution_clock::now();

    chrono::duration<double>duration = end-start;

    cout<<"taken time :"<<duration.count()*10000<<endl;



    return 0;
}
