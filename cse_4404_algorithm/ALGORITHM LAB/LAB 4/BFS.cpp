//bismillahir rahmanir rahim
#include<bits/stdc++.h>
#define F first
#define S second
#define ll long long
#define pb push_back
#define sort(s) sort(s.begin(),s.end())
#define sortarr(a) sort(a, a+n)
#define fr(i,n) for(int i=0;i<n;i++)
#define frone(i,n) for(int i=1;i<=n;i++)
#define reverse(s) reverse(s.begin(),s.end())
#define N 100000+10
#define MAX LONG_MAX
#define tc     int tc; cin>>tc; while(tc--)
#define the_flash ios_base ::sync_with_stdio(0);cin.tie(0);
using namespace std;

class Graph {


	int V;

	vector<list<int> > adj;

public:

	Graph(int V);

	void addEdge(int v, int w);

	void BFS(int s);
};

Graph::Graph(int V)
{
	this->V = V;
	adj.resize(V);
}

void Graph::addEdge(int v, int w)
{
		adj[v].push_back(w);
        adj[w].push_back(v);
}

void Graph::BFS(int s)
{

	vector<bool> visited;
	visited.resize(V, false);

		list<int> queue;


	visited[s] = true;
	queue.push_back(s);

	while (!queue.empty()) {


		s = queue.front();
		cout << s << " ";
		queue.pop_front();


		for (auto adjacent : adj[s]) {
			if (!visited[adjacent]) {
				visited[adjacent] = true;
				queue.push_back(adjacent);
			}
		}
	}
}


int main()
{
	
	Graph g(4);
	g.addEdge(0, 1);
	// g.addEdge(0, 2);
	// g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);

	g.BFS(2);

	return 0;
}
