//bismillahir rahmanir rahim
#include<bits/stdc++.h>
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
#define ll long long
const ll inf = 1000000000000000000;
vector<pair<ll, ll>> adj[100005];
 
void dijkstra(ll source, ll node)
{
    map<ll, ll> mp;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    vector<ll> ans(node + 10, inf);
    ans[source] = 0;
    pq.push({0, source}); // weight,source
    while (!pq.empty())
    {
 
        pair<ll,ll>top=pq.top();
        ll parent_weight = top.first;
        ll parent_node = top.second;
        pq.pop();
        for (auto it : adj[parent_node])
        {
            ll child_node = it.first;
            ll child_weight = it.second;
      
            if (ans[child_node] > child_weight + parent_weight) // relaxation
            {
                mp[child_node] = parent_node;
                ans[child_node] = child_weight + parent_weight;
                pq.push({ans[child_node], child_node});
            }
        }
    }
    // print
    ll n = node;
    if (mp[n] == 0)
        cout << -1 << endl;
    else
    {
        vector<ll> final;
        mp[source] = -1;
        while (n != -1)
        {
            final.push_back(n);
            n = mp[n];
        }
        reverse(final);
        for (auto it : final)
            cout << it << " ";
        cout << endl;
    }
}
void solve()
{
    ll source_node, node, edge, a, b, weight, i;
    cin >> node >> edge;
    for (i = 1; i <= edge; i++)
    {
        cin >> a >> b >> weight;
        adj[a].push_back({b, weight});
        adj[b].push_back({a, weight});
    }
    dijkstra(1, node);
}
 
int main()
{
    the_flash;
    ll t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}