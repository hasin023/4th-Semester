#include <iostream>
#include <climits>

using namespace std;

long long maxCrossingSum(long long arr[], long long low, long long mid, long long high)
{
    bool allNegative = true;
    for (long long i = low; i <= high; i++)
    {
        if (arr[i] >= 0)
        {
            allNegative = false;
            break;
        }
    }

    if (allNegative)
    {
        long long maxNegative = INT_MIN;
        for (long long i = low; i <= high; i++)
        {
            if (arr[i] > maxNegative)
            {
                maxNegative = arr[i];
            }
        }
        return maxNegative;
    }

    long long leftSum = INT_MIN;
    long long sum = 0;
    for (long long i = mid; i >= low; i--)
    {
        sum += arr[i];
        if (sum > leftSum)
            leftSum = sum;
    }

    long long rightSum = INT_MIN;
    sum = 0;
    for (long long i = mid + 1; i <= high; i++)
    {
        sum += arr[i];
        if (sum > rightSum)
            rightSum = sum;
    }

    return leftSum + rightSum;
}

long long maxSubarraySum(long long arr[], long long low, long long high)
{
    if (low == high)
        return arr[low];

    long long mid = (low + high) / 2;

    long long leftSum = maxSubarraySum(arr, low, mid);
    long long rightSum = maxSubarraySum(arr, mid + 1, high);
    long long crossingSum = maxCrossingSum(arr, low, mid, high);

    return max(max(leftSum, rightSum), crossingSum);
}

int main()
{
    // long long arr[] = {-1, 3, -2, 5, 3, -5, 2, 2}; // -1 3 -2 5 3 -5 2 2
    long long n;
    cin >> n;

    long long arr[n];

    for (long long i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    long long maxSum = maxSubarraySum(arr, 0, n - 1);

    cout << maxSum << endl;

    return 0;
}