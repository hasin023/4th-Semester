#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <iomanip>

using namespace std;

void addHeapProperty(int arr[], int n, int i)
{
    while (true)
    {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[left] > arr[largest])
            largest = left;

        if (right < n && arr[right] > arr[largest])
            largest = right;

        if (largest == i)
            break;

        swap(arr[i], arr[largest]);
        i = largest;
    }
}

void makeHeap(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        addHeapProperty(arr, n, i);
}

void sortHeap(int arr[], int n)
{
    makeHeap(arr, n);

    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        addHeapProperty(arr, i, 0);
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
    sortHeap(arr, n);
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
