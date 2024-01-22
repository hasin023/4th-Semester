#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <iomanip>
using namespace std;

int find2DPeak(int **arr, int rows, int cols, int mid)
{
    for (int i = 0; i < rows; i++)
    {
        bool isPeak = true;

        // Left
        if (mid > 0 && arr[i][mid] < arr[i][mid - 1])
            isPeak = false;

        // Right
        if (mid < cols - 1 && arr[i][mid] < arr[i][mid + 1])
            isPeak = false;

        // Top
        if (i > 0 && arr[i][mid] < arr[i - 1][mid])
            isPeak = false;

        // Bottom
        if (i < rows - 1 && arr[i][mid] < arr[i + 1][mid])
            isPeak = false;

        if (isPeak)
            return i;
    }

    return -1;
}

int main()
{
    int n, m;
    cout << "Enter the number of rows for the 2D Array : ";
    cin >> n;

    cout << "Enter the number of columns for the 2D Array : ";
    cin >> m;

    srand(time(0));

    int **arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[m];
    }

    cout << "Inserting random values in the 2D Array..." << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            arr[i][j] = rand() % 100;
        }
    }
    cout << endl;

    auto start = chrono::high_resolution_clock::now();
    int peakRow = find2DPeak(arr, n, m, m / 2);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> timeTaken = end - start;

    if (peakRow != -1)
        cout << "Value of the peak point is " << arr[peakRow][m / 2] << endl;
    else
        cout << "No peak found in the 2D array" << endl;

    cout << "Time taken to find the peak point is " << fixed << setprecision(10) << timeTaken.count() << " seconds" << endl;

    for (int i = 0; i < n; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}
