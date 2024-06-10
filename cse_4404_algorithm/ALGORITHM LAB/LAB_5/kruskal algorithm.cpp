// C++ program for the above approach 
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

class DSU { 
	int* parent; 
	int* rank; 

public: 
	DSU(int n) 
	{ 
		parent = new int[n]; 
		rank = new int[n]; 

		for (int i = 0; i < n; i++) { 
			parent[i] = -1; 
			rank[i] = 1; 
		} 
	} 


	int find(int i) 
	{ 
		if (parent[i] == -1) 
			return i; 

		return parent[i] = find(parent[i]); 
	} 


	void unite(int x, int y) 
	{ 
		int s1 = find(x); 
		int s2 = find(y); 

		if (s1 != s2) { 
			if (rank[s1] < rank[s2]) { 
				parent[s1] = s2; 
			} 
			else if (rank[s1] > rank[s2]) { 
				parent[s2] = s1; 
			} 
			else { 
				parent[s2] = s1; 
				rank[s1] += 1; 
			} 
		} 
	} 
}; 

class Graph { 
	vector<vector<int> > edgelist; 
	int V; 

public: 
	Graph(int V) { this->V = V; } 

	void addEdge(int x, int y, int w) 
	{ 
		edgelist.push_back({ w, x, y }); 
	} 

	void kruskals_mst() 
	{ 

		sort(edgelist); 


		DSU s(V); 
		int ans = 0; 
	
		for (auto edge : edgelist) { 
			int w = edge[0]; 
			int x = edge[1]; 
			int y = edge[2]; 


			if (s.find(x) != s.find(y)) { 
				s.unite(x, y); 
				ans += w; 

                char a=x+'A';
                char b=(char) y+'A';

				cout << a << "  " << b << "  " << w 
					<< endl; 
			} 
		} 
		cout << "Minimum Cost " << ans; 
	} 
}; 


int main() 
{ 

    int n;
    cin>>n;
	Graph g(n); 
    char a,b;
    int w;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b>>w;

        g.addEdge((int)a-'A',(int)b-'A',w);
    }


	g.kruskals_mst(); 

	return 0; 
}
