#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void breadthFirstSearch(vector<vector<int>> &graph, int startNode)
{
    vector<bool> visited(graph.size(), false);
    queue<int> q;

    visited[startNode] = true;
    q.push(startNode);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int i = 0; i < graph[node].size(); i++)
        {
            if (!visited[graph[node][i]])
            {
                visited[graph[node][i]] = true;
                q.push(graph[node][i]);
            }
        }
    }
}

int main()
{
    vector<vector<int>> graph = {
        {0},
        {2, 7, 9},
        {1, 5},
        {5, 6, 9},
        {7, 9},
        {2, 3, 6},
        {3, 5},
        {1, 4},
        {9},
        {1, 3, 4, 8}

    };

    int startNode;
    cout << "Enter the start node: ";
    cin >> startNode;

    cout << "BFS Traversal: ";
    breadthFirstSearch(graph, startNode);
    cout << endl;

    return 0;
}
