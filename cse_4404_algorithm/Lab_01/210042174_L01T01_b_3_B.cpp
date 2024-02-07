#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <iomanip>
using namespace std;

int findMaxInColumn(int **arr, int rows, int midColumn)
{
    int maxElement = arr[0][midColumn];
    int maxRow = 0;

    for (int i = 1; i < rows; i++)
    {
        if (arr[i][midColumn] > maxElement)
        {
            maxElement = arr[i][midColumn];
            maxRow = i;
        }
    }

    return maxRow;
}

int find2DPeak(int **arr, int rows, int cols, int midColumn)
{
    int maxRow = findMaxInColumn(arr, rows, midColumn);

    if ((midColumn == 0 || arr[maxRow][midColumn] >= arr[maxRow][midColumn - 1]) &&
        (midColumn == cols - 1 || arr[maxRow][midColumn] >= arr[maxRow][midColumn + 1]))
    {
        return maxRow;
    }

    if (midColumn > 0 && arr[maxRow][midColumn - 1] > arr[maxRow][midColumn + 1])
    {
        return find2DPeak(arr, rows, cols, midColumn / 2);
    }
    else
    {
        return find2DPeak(arr, rows, cols, midColumn + midColumn / 2);
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
    int peakRow = find2DPeak(arr, n, m, m / 2);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> timeTaken = end - start;

    if (peakRow != -1)
        cout << "Value of the peak point is " << arr[peakRow][m / 2] << endl;
    else
        cout << "No peak found in the 2D array" << endl;

    cout << "Time taken to find the peak point using the Divide and Conquer approach is " << fixed << setprecision(10) << timeTaken.count() << " seconds" << endl;

    for (int i = 0; i < n; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}
