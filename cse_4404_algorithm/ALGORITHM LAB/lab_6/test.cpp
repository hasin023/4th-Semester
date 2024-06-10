#include <iostream>
#include <deque>
using namespace std;

// function to calculate the maximum number in the subarray
void maxOfSubarray(int arr[], int n, int k) {
    // create deque to store indexes of array elements
    deque<int> deque;

    int i;
    // traverse first k elements
    for (i = 0; i < k; ++i) {
        // remove the smaller elements from the rear end
        while (!deque.empty() && arr[i] >= arr[deque.back()]) {
            deque.pop_back();
        }
  
        // add current element at the rear end
        deque.push_back(i);
    }

    // traverse through the rest of the elements
    for (; i < n; ++i) {
        // print the maximum element of the previous window
        cout << arr[deque.front()] << " ";

        // remove elements that are not part of the current window
        while (!deque.empty() && deque.front() <= i - k)
            deque.pop_front();

        // remove the smaller elements from the rear end
        while (!deque.empty() && arr[i] >= arr[deque.back()])
            deque.pop_back();

        // add current element at the rear end
        deque.push_back(i);
    }

    // print the maximum element of last window
    cout << arr[deque.front()];
}

// driver Code
int main() {
    int arr[] = { 11, 3, 9, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    maxOfSubarray(arr, n, k);
    return 0;
}
