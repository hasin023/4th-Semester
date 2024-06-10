#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>>mst;


int spanningTree(int V, vector<pair<int,int>> adj[])
{
    priority_queue<pair<int,pair<int, int>>, vector<pair<int,pair<int, int>>>, greater<pair<int,pair<int, int>>>> pq;

    vector<int> vis(V, 0);
    vector<int>parent(V);
    pq.push({0,{0, -1}});
    int sum = 0;
    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        int node =  it.second.first;
        int wt =it.first;
        int parent=it.second.second;

        if (vis[node] == 1)
            continue;

        
        // add it to the mst
        if(parent!=-1)
        {
            mst.push_back({parent,node});
        }

        vis[node] = 1;
        sum += wt;
        for (auto it : adj[node])
        {
            int adjNode = it.first;
            int edW = it.second;
            if (!vis[adjNode])
            {
               pq.push({edW,{adjNode,node}});
            }
        }
    }
    return sum;
}

int main()
{

    int V = 5;
    vector<vector<int>> edges = {{0,1,2},{0,3,6},{1,2,3},{1,3,8},{1,4,5},{2,4,7}};

    vector<pair<int,int>>adj[100005];

    for (auto it : edges)
    {
     adj[it[0]].push_back({it[1], it[2]});
    }

    int sum = spanningTree(V, adj);
    cout << "The sum of all the edge weights: " << sum << endl;

  for(auto i:mst)
  {
    cout<<i.first<<" "<<i.second<<endl;
  }
   

    return 0;
}