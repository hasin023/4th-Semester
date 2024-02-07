#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <iomanip>
using namespace std;

int find2DPeak(int **arr, int rows, int cols)
{
    int midColumn = cols / 2;

    int currentRow = 0;
    for (int i = 1; i < rows; i++)
    {
        if (arr[i][midColumn] > arr[currentRow][midColumn])
        {
            currentRow = i;
        }
    }

    int currentCol = midColumn;

    while (true)
    {
        bool isPeak = true;

        // Left
        if (currentCol > 0 && arr[currentRow][currentCol] < arr[currentRow][currentCol - 1])
            isPeak = false;

        // Right
        if (currentCol < cols - 1 && arr[currentRow][currentCol] < arr[currentRow][currentCol + 1])
            isPeak = false;

        // Top
        if (currentRow > 0 && arr[currentRow][currentCol] < arr[currentRow - 1][currentCol])
            isPeak = false;

        // Bottom
        if (currentRow < rows - 1 && arr[currentRow][currentCol] < arr[currentRow + 1][currentCol])
            isPeak = false;

        if (isPeak)
            return currentRow;

        // Move to the neighboring element with the larger value
        if (currentCol > 0 && arr[currentRow][currentCol - 1] > arr[currentRow][currentCol + 1])
        {
            currentCol--;
        }
        else if (currentCol < cols - 1)
        {
            currentCol++;
        }
    }
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
    int peakRow = find2DPeak(arr, n, m);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> timeTaken = end - start;

    if (peakRow != -1)
        cout << "Value of the peak point is " << arr[peakRow][m / 2] << endl;
    else
        cout << "No peak found in the 2D array" << endl;

    cout << "Time taken to find the peak point using the greedy approach is " << fixed << setprecision(10) << timeTaken.count() << " seconds" << endl;

    for (int i = 0; i < n; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}
