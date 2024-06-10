// DFS algorithm in C++

// bismillahir rahmanir rahim
#include <bits/stdc++.h>
#define F first
#define S second
#define ll long long
#define pb push_back
#define sort(s) sort(s.begin(), s.end())
#define sortarr(a) sort(a, a + n)
#define fr(i, n) for (int i = 0; i < n; i++)
#define frone(i, n) for (int i = 1; i <= n; i++)
#define reverse(s) reverse(s.begin(), s.end())
#define N 100000 + 10
#define MAX LONG_MAX
#define tc     \
    int tc;    \
    cin >> tc; \
    while (tc--)
#define the_flash                  \
    ios_base ::sync_with_stdio(0); \
    cin.tie(0);
using namespace std;

class Graph
{
    int numVertices;
    list<int> *adjLists;
    bool *visited;

public:
    Graph(int V);
    void addEdge(int src, int dest);
    void DFS(int vertex);
};

Graph::Graph(int vertices)
{
    numVertices = vertices;
    adjLists = new list<int>[vertices];
    visited = new bool[vertices];
}

void Graph::addEdge(int src, int dest)
{
    adjLists[src].push_front(dest);
    adjLists[dest].push_front(src);
}

void Graph::DFS(int vertex)
{
    visited[vertex] = true;
    list<int> &adjList = adjLists[vertex];

    cout << vertex << " ";

    list<int>::iterator i;
    for (i = adjList.begin(); i != adjList.end(); ++i)
        if (!visited[*i])
        {
            DFS(*i);
        }
}

int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);

    g.DFS(1);

    return 0;
}