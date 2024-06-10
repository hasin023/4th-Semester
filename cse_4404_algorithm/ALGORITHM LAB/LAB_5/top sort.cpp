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


void dfs(int node, int vis[], stack<int> &st,
         vector<int> adj[])
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
            dfs(it, vis, st, adj);
    }
    st.push(node);
}


vector<int> topSort(int V, vector<int> adj[])
{
    int vis[V+1] = {0};
    stack<int> st;
    for (int i = 1; i <= V; i++)
    {
        if (!vis[i])
        {
            dfs(i, vis, st, adj);
        }
    }

    vector<int> ans;
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

int main()
{



   

    int n,m;
    cin>>n>>m;

    int x,y;

     vector<int> adj[m];
    while(m--)
    {
        cin>>x>>y;

        adj[x].pb(y);

    }



    vector<int> ans = topSort(n, adj);

    for (auto node : ans)
    {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}