#include <bits/stdc++.h>
using namespace std;

int findPeak(int arr[], int n)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;

        if ((mid == 0 || arr[mid - 1] <= arr[mid]) && (mid == n - 1 || arr[mid + 1] <= arr[mid]))
            return arr[mid];

        if (mid > 0 && arr[mid - 1] >= arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
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
