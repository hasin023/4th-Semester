// Hasin Mahtab Alvee
// 210042174

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int strength, numDragons;
    cin >> strength >> numDragons;

    vector<pair<int, int>> dragons;

    for (int i = 0; i < numDragons; ++i)
    {
        int dragonStrength, dragonBonus;
        cin >> dragonStrength >> dragonBonus;
        dragons.push_back({dragonStrength, dragonBonus});
    }

    make_heap(dragons.begin(), dragons.end());
    sort_heap(dragons.begin(), dragons.end());

    for (int i = 0; i < numDragons; ++i)
    {
        if (strength > dragons[i].first)
        {
            strength += dragons[i].second;
        }
        else
        {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;

    return 0;
}
