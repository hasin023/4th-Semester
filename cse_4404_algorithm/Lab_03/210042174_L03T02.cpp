#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <iomanip>
using namespace std;

void countingSort(int arr[], int size, int maxVal)
{
    int count[maxVal + 1] = {0};

    for (int i = 0; i < size; i++)
    {
        count[arr[i]]++;
    }

    int index = 0;
    for (int i = 0; i <= maxVal; i++)
    {
        while (count[i] > 0)
        {
            arr[index++] = i;
            count[i]--;
        }
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter the number of elements in the array : ";
    cin >> n;

    srand(time(0));

    int *arr = new int[n];

    cout << "Inserting random values in the array..." << endl;
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 500;
    }

    cout << "Sorting the array..." << endl;

    int maxVal = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > maxVal)
        {
            maxVal = arr[i];
        }
    }

    auto start = chrono::high_resolution_clock::now();
    countingSort(arr, n, maxVal);
    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double> duration = end - start;

    cout << "Sorted array: ";
    printArray(arr, n);

    cout << endl;
    cout << "Time taken : " << fixed << setprecision(10) << duration.count() << " seconds" << endl;

    return 0;
}