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
#define N 100000 + 10
#define MAX LONG_MAX
#define tc     \
    int tc;    \
    cin >> tc; \
    while (tc--)
#define the_flash                  \
    ios_base ::sync_with_stdio(0); \
    cin.tie(0);
using namespace std;

void bucketSort(float arr[], int n)
{

    vector<float> b[n];

    for (int i = 0; i < n; i++)
    {

        int bi = n * arr[i];
        b[bi].push_back(arr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        sort(b[i]);
    }

    int index = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < b[i].size(); j++)
        {
            arr[index++] = b[i][j];
        }
    }
}

// float Convert(float arr[], int n)
// {
//     float mx = arr[0];
//     for (int i = 1; i < n; i++)
//     {
//         if (arr[i] > mx)
//             mx = arr[i];
//     }

//     mx += 1;

//     for (int i = 1; i < n; i++)
//     {
//         arr[i] = arr[i] / mx;
//     }

//     return mx;
// }

// void revert(float arr[],int n,float mx)
// {
//     for (int i = 1; i < n; i++)
//     {
//         arr[i] = arr[i] * mx;
//     }
// }
int main()
{
    float arr[] = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    int n = sizeof(arr) / sizeof(arr[0]);
    // float mx=Convert(arr,n);
    bucketSort(arr, n);
    // revert(arr,n,mx);
    cout << "Sorted array is \n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
