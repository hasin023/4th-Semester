// bismillahir rahmanir rahim
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define fr(i, n) for (int i = 0; i < n; i++)
#define frone(i, n) for (int i = 1; i <= n; i++)
#define reverse(s) reverse(s.begin(), s.end())
#define MAX LONG_MAX
#define tc     \
    int tc;    \
    cin >> tc; \
    while (tc--)
#define the_flash                  \
    ios_base ::sync_with_stdio(0); \
    cin.tie(0);
using namespace std;
#define f first
#define s second
typedef pair<int, int> pii;
typedef pair<int, pii> edge;
const int maxN = 1e5 + 1;
const int maxM = 2e5 + 1;

int N, M, a, b, c, ds[maxN];
long long sum;
edge edges[maxM];

int find(int u)
{
    if (ds[u] < 0)
        return u;
    ds[u] = find(ds[u]);
    return ds[u];
}

bool merge(int u, int v)
{
    u = find(u);
    v = find(v);
    if (u == v)
        return false;
    if (ds[u] < ds[v])
        swap(u, v);
    ds[v] += ds[u];
    ds[u] = v;
    return true;
}

int main()
{
    cin>>N>>M;
    fill(ds + 1, ds + N + 1, -1);
    for (int i = 0; i < M; i++)
    {
        scanf("%d %d %d", &a, &b, &c);
        edges[i] = {c, {a, b}};
    }
    sort(edges, edges + M);

    for (int i = 0; i < M; i++)
    {
        edge e = edges[i];
        if (merge(e.s.f, e.s.s))
        {
            sum += e.f;
            N--;
        }
    }

    if (N == 1)
       cout<<sum<<endl;
    else
        cout<<"IMPOSSIBLE"<<endl;
}