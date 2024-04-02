#include <iostream>

using namespace std;

int getFibonacci(int n)
{
    int fibArray[n + 2];
    fibArray[0] = 0;
    fibArray[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        fibArray[i] = fibArray[i - 1] + fibArray[i - 2];
    }

    return fibArray[n];
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Fibonacci of " << n << " is " << getFibonacci(n) << endl;
    return 0;
}