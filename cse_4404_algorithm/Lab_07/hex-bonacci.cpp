#include <iostream>
#include <vector>

using namespace std;

long long a, b, c, d, e, f;

long long Hexbonacci(long long n)
{
    vector<long long> hexVector(n + 1);
    hexVector[0] = a;
    hexVector[1] = b;
    hexVector[2] = c;
    hexVector[3] = d;
    hexVector[4] = e;
    hexVector[5] = f;

    for (long long i = 6; i <= n; ++i)
    {
        hexVector[i] = (hexVector[i - 1] + hexVector[i - 2] + hexVector[i - 3] + hexVector[i - 4] + hexVector[i - 5] + hexVector[i - 6]) % 10000007;
    }

    return hexVector[n];
}

int main()
{
    long long n, cases;
    cin >> cases;
    for (long long caseno = 1; caseno <= cases; ++caseno)
    {
        cin >> a >> b >> c >> d >> e >> f >> n;
        cout << "Case " << caseno << ": " << Hexbonacci(n) << endl;
    }
    return 0;
}