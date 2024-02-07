#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> readInputValues(int n)
{
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    return v;
}

bool isSorted(const vector<int> &v)
{
    return is_sorted(v.begin(), v.end());
}

void reversePortion(vector<int> &v, vector<int>::reverse_iterator r2, vector<int>::iterator r1)
{
    reverse(r2, make_reverse_iterator(r1));
}

void printResult(const vector<int> &v, vector<int>::iterator r1, vector<int>::reverse_iterator r2)
{
    int n = v.size();
    if (isSorted(v))
    {
        cout << "yes\n"
             << (r1 - v.begin() + 1) << ' ' << (n - (r2 - v.rbegin()));
    }
    else
    {
        cout << "no";
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> v = readInputValues(n);

    vector<int>::iterator r1 = is_sorted_until(v.begin(), v.end()) - 1;
    if (r1 == (v.end() - 1))
    {
        cout << "yes\n1 1";
    }
    else
    {
        vector<int>::reverse_iterator r2 = is_sorted_until(v.rbegin(), v.rend(), [](int a, int b)
                                                           { return a > b; }) -
                                           1;
        reversePortion(v, r2, r1);
        printResult(v, r1, r2);
    }
}