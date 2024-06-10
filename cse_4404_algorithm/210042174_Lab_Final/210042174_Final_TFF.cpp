#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string findLongestCommonSubsequence(const string &s, const string &t)
{
    string lcs;
    int i = 0, j = 0;

    while (i < s.length() && j < t.length())
    {
        if (s[i] == t[j])
        {
            lcs += s[i];
            i++;
            j++;
        }
        else if (s[i] < t[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }

    return lcs;
}

int main()
{
    string s;
    string t;
    cin >> s;
    cin >> t;

    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    string lcs = findLongestCommonSubsequence(s, t);
    cout << "Longest Common Subsequence: " << lcs << endl;

    return 0;
}