#include <bits/stdc++.h>
#define ll long long
using namespace std;

void countSort(int arr[], int n)
{
    int maxi = arr[0];
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, arr[i]);
    }

    int count[maxi+1] = {0};

    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }

    for (int i = 1; i <= maxi; i++)
    {
        count[i] += count[i - 1];
    }

    int output[n];

    for (int i = n - 1; i >= 0; i--)
    {
        output[--count[arr[i]]] = arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}

int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    countSort(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}