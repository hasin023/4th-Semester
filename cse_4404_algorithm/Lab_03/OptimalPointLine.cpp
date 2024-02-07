#include <iostream>
#include <algorithm>

using namespace std;

int findOptimalPoint(int coordinates[], int n)
{
    sort(coordinates, coordinates + n);
    int median_index = (n - 1) / 2;
    return coordinates[median_index];
}

int main()
{
    int n;
    cin >> n;

    int coordinates[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> coordinates[i];
    }

    int optimal_point = findOptimalPoint(coordinates, n);

    cout << optimal_point << endl;

    return 0;
}
