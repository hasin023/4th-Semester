// Edges
// D->E = 1;
// G->I = 1;
// A->B = 2;
// C->D = 2;
// C->H = 2;
// E->I = 2;
// A->G = 3;
// G->H = 3;
// B->C = 4;
// H->I = 4;
// B->G = 6;
// E->F = 6;
// A->F = 7;
// D->H = 8;

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Edge
{
    int start, end, weight;
};

void MST_Tree(vector<Edge> &edges, int numVertices)
{
    vector<Edge> minimumTree;
    vector<bool> visited(numVertices, false);

    int startingVertex = 0;
    visited[startingVertex] = true;

    while (minimumTree.size() < numVertices - 1)
    {
        int minWeight = INT_MAX;
        Edge minEdge;

        for (const Edge &edge : edges)
        {
            if (visited[edge.start] && !visited[edge.end] && edge.weight < minWeight)
            {
                minWeight = edge.weight;
                minEdge = edge;
            }
        }

        visited[minEdge.end] = true;
        minimumTree.push_back(minEdge);
    }

    cout << "Minimum Spanning Tree:" << endl;
    for (const auto &edge : minimumTree)
    {
        cout << edge.start << " -> " << edge.end << " : " << edge.weight << endl;
    }
}

int main()
{
    vector<Edge> edges = {
        {3, 4, 1},
        {6, 8, 1},
        {0, 1, 2},
        {2, 3, 2},
        {2, 7, 2},
        {4, 8, 2},
        {0, 6, 3},
        {6, 7, 3},
        {1, 2, 4},
        {7, 8, 4},
        {1, 6, 6},
        {4, 5, 6},
        {0, 5, 7},
        {3, 7, 8}};

    MST_Tree(edges, 9);

    return 0;
}