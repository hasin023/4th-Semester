#include <bits/stdc++.h>
using namespace std;

int findPeak(int arr[], int n)
{
    if (n == 1)
        return arr[0];
    if (arr[0] >= arr[1])
        return arr[0];
    if (arr[n - 1] >= arr[n - 2])
        return arr[n - 1];

    for (int i = 1; i < n - 1; i++)
    {
        if (arr[i] >= arr[i - 1] && arr[i] >= arr[i + 1])
            return arr[i];
    }

    return -1;
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    srand(time(0));

    int arr[n];
    cout << "Inserting random values in the Array..." << endl;
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 200;
    }
    cout << endl;

    auto start = chrono::high_resolution_clock::now();
    int peakValue = findPeak(arr, n);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> timeTaken = end - start;

    if (peakValue != -1)
    {
        cout << "Value of the peak point is " << peakValue << endl;
        cout << "Time taken to find the peak point is " << fixed << setprecision(10) << timeTaken.count() << " seconds" << endl;
    }
    else
        cout << "No peak found in the array";

    return 0;
}
