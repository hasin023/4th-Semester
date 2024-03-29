#include <iostream>
#include <climits>

using namespace std;

long long maxSubarraySum(long long arr[], long long low, long long high, long long a, long long b)
{
    if (low == high)
        return arr[low];

    long long mid = (low + high) / 2;

    long long leftSum = maxSubarraySum(arr, low, mid, a, b);
    long long rightSum = maxSubarraySum(arr, mid + 1, high, a, b);

    long long sum = 0;
    long long leftMax = LLONG_MIN;
    long long rightMax = LLONG_MIN;

    for (long long i = mid; i >= low; i--)
    {
        sum += arr[i];
        leftMax = max(leftMax, sum);
    }

    sum = 0;

    for (long long i = mid + 1; i <= high; i++)
    {
        sum += arr[i];
        rightMax = max(rightMax, sum);
    }

    long long crossingSum = leftMax + rightMax;

    return max({leftSum, rightSum, crossingSum});
}

int main()
{
    long long n, a, b;
    cin >> n >> a >> b;

    long long arr[n];

    for (long long i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    long long maxSum = LLONG_MIN;
    for (long long i = a; i <= b; i++)
    {
        maxSum = max(maxSum, maxSubarraySum(arr, 0, n - 1, i, b));
    }

    cout << maxSum << endl;

    return 0;
}
