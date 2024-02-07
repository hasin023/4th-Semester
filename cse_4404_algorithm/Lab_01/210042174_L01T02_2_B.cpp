#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <iomanip>
using namespace std;

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
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

    auto start = chrono::high_resolution_clock::now();
    insertionSort(arr, n);
    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double> duration = end - start;

    cout << "Sorted array : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
    cout << "Time taken : " << fixed << setprecision(10) << duration.count() << " seconds" << endl;

    return 0;
}

// void mergeSort(int arr[], int l, int r)
// {
//     if (l >= r)
//         return;

//     int mid = (l + r) / 2;

//     mergeSort(arr, l, mid);
//     mergeSort(arr, mid + 1, r);

//     int i = l, j = mid + 1, k = 0;
//     int temp[r - l + 1];

//     while (i <= mid && j <= r)
//     {
//         if (arr[i] <= arr[j])
//         {
//             temp[k] = arr[i];
//             i++;
//         }
//         else
//         {
//             temp[k] = arr[j];
//             j++;
//         }

//         k++;
//     }

//     while (i <= mid)
//     {
//         temp[k] = arr[i];
//         i++;
//         k++;
//     }

//     while (j <= r)
//     {
//         temp[k] = arr[j];
//         j++;
//         k++;
//     }

//     for (int i = l; i <= r; i++)
//     {
//         arr[i] = temp[i - l];
//     }
// }
