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

void countSort(int arr[], int n, int exp)
{

    int output[n];
    int i, count[10] = {0};

    for (i = 0; i < n; i++)
    {
        count[(arr[i] / exp) % 10]++;
    }
    for (i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    for (i = n - 1; i >= 0; i--)
    {
        output[--count[(arr[i] / exp) % 10]] = arr[i];
    }

    for (i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}

void radixsort(int arr[], int n)
{

    int mx = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > mx)
            mx = arr[i];
    }
    for (int exp = 1; mx / exp > 0; exp *= 10)
    {
        countSort(arr, n, exp);
    }
}

int main()
{
    int arr[] = {543, 986, 217, 65, 329};
    int n = sizeof(arr) / sizeof(arr[0]);

    radixsort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
