#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void depthFirstSearch(vector<vector<int>> &graph, int startNode)
{
    vector<bool> visited(graph.size(), false);
    stack<int> s;

    visited[startNode] = true;
    s.push(startNode);

    while (!s.empty())
    {
        int node = s.top();
        s.pop();
        cout << node << " ";

        for (int i = 0; i < graph[node].size(); i++)
        {
            if (!visited[graph[node][i]])
            {
                visited[graph[node][i]] = true;
                s.push(graph[node][i]);
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

    cout << "DFS Traversal: ";
    depthFirstSearch(graph, startNode);
    cout << endl;

    return 0;
}