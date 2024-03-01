#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

struct Edge
{
    int start, end, weight;
};

bool compareEdges(const Edge &a, const Edge &b)
{
    return a.weight < b.weight;
}

int find(int x, vector<int> &parent)
{
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x], parent);
}

void union_sets(int a, int b, vector<int> &parent, vector<int> &rank)
{
    a = find(a, parent);
    b = find(b, parent);
    if (a != b)
    {
        if (rank[a] < rank[b])
            swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b])
            rank[a]++;
    }
}

int MST_Tree(vector<Edge> &edges, int numVertices)
{
    sort(edges.begin(), edges.end(), compareEdges);

    vector<int> parent(numVertices);
    vector<int> rank(numVertices, 0);
    for (int i = 0; i < numVertices; ++i)
    {
        parent[i] = i;
    }

    int totalCost = 0;
    int edgeCount = 0;
    for (const Edge &edge : edges)
    {
        if (find(edge.start, parent) != find(edge.end, parent))
        {
            totalCost += edge.weight;
            union_sets(edge.start, edge.end, parent, rank);
            ++edgeCount;
        }
    }

    if (edgeCount != numVertices - 1)
        return INT_MAX;

    return totalCost;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    for (int i = 0; i < m; ++i)
    {
        cin >> edges[i].start >> edges[i].end >> edges[i].weight;
    }

    int totalCost = MST_Tree(edges, n);

    if (totalCost == INT_MAX)
        cout << "IMPOSSIBLE" << endl;
    else
        cout << totalCost << endl;

    return 0;
}
