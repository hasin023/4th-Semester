#include <iostream>
#include <climits>
using namespace std;

int cutRod(const int price[], int n)
{
    int valueArray[n + 1];
    valueArray[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        int maxVal = INT_MIN;
        for (int j = 0; j < i; j++)
        {
            maxVal = max(maxVal, price[j] + valueArray[i - j - 1]);
        }
        valueArray[i] = maxVal;
    }

    return valueArray[n];
}

// valueArray[0] = 0
// valueArray[1] = max (MIN_INT, 3 + valueArray[0]) = 3
// valueArray[2] = max (max(MIN_INT, 3 + valueArray[1]), max(MIN_INT, 5 + valueArray[0])) = 6

int main()
{
    int price[] = {3, 5, 8, 9, 10, 17, 17, 20};
    int length = sizeof(price) / sizeof(price[0]);
    cout << "Maximum Obtainable Value is " << cutRod(price, length) << endl;
    return 0;
}
