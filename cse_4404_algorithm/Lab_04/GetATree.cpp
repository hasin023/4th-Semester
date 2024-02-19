#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> makeTree(vector<vector<int>> &graph, int startNode)
{
    int n = graph.size();
    vector<bool> visited(n, false);
    vector<vector<int>> tree(n);

    queue<int> q;
    q.push(startNode);
    visited[startNode] = true;

    while (!q.empty())
    {
        int currentNode = q.front();
        q.pop();

        for (int neighbor : graph[currentNode])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                q.push(neighbor);
                // tree[currentNode].push_back(neighbor);
                // tree[neighbor].push_back(currentNode);
            }
        }
    }

    return tree;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<vector<int>> tree = makeTree(graph, 0);

    for (int i = 0; i < n; i++)
    {
        for (int neighbor : tree[i])
        {
            cout << neighbor + 1 << " ";
        }
        cout << endl;
    }

    return 0;
}
