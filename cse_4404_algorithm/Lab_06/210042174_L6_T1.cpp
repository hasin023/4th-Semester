#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int maxCrossingSum(int arr[], int low, int mid, int high)
{
    bool allNegative = true;
    for (int i = low; i <= high; i++)
    {
        if (arr[i] >= 0)
        {
            allNegative = false;
            break;
        }
    }

    if (allNegative)
    {
        int maxNegative = INT_MIN;
        for (int i = low; i <= high; i++)
        {
            maxNegative = max(maxNegative, arr[i]);
        }
        return maxNegative;
    }

    int leftSum = INT_MIN;
    int sum = 0;
    for (int i = mid; i >= low; i--)
    {
        sum += arr[i];
        leftSum = max(leftSum, sum);
    }

    int rightSum = INT_MIN;
    sum = 0;
    for (int i = mid + 1; i <= high; i++)
    {
        sum += arr[i];
        rightSum = max(rightSum, sum);
    }

    return leftSum + rightSum;
}

int maxSubarraySum(int arr[], int low, int high)
{
    if (low == high)
        return arr[low];

    int mid = (low + high) / 2;

    int leftSum = maxSubarraySum(arr, low, mid);
    int rightSum = maxSubarraySum(arr, mid + 1, high);
    int crossingSum = maxCrossingSum(arr, low, mid, high);

    return max(max(leftSum, rightSum), crossingSum);
}

int main()
{
    int arr[] = {-1, 3, -2, 5, 3, -5, 2, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    int maxSum = maxSubarraySum(arr, 0, n - 1);

    cout << "Maximum subarray sum: " << maxSum << endl;

    return 0;
}