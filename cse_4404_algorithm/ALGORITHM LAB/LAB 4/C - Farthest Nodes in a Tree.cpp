#include <bits/stdc++.h>
using namespace std;

bool vis[30000];
int dis[30000];

vector<int>Graph[30000];
vector<int>weight[30000];

void reset(int n)
{
    for( int i = 0 ; i < n ; i++ )
    {
        vis[i] = 0;
        dis[i] = 0;
    }
}
void bfs(int a,int n)
{
    queue<int>q;

    vis[a] = 1;
    q.push(a);

    while(!q.empty())
    {
        int top;
        top = q.front();
        q.pop();

        for(int i=0; i<Graph[top].size(); i++)
        {
            int var = Graph[top][i];

            if(!vis[var])
            {
                vis[var] = 1;
                dis[var] = dis[top] + weight[top][i]; // dis[ node ] is the node's distance from source.
                q.push(var);
            }
        }
    }
}



int main()
{
    int t,cs=0;
    cin>>t;
    while(t--)
    {
        int n,u,v,cost; 
        scanf("%d",&n);

        for( int i = 0 ; i < n ; i++ )
        {
            Graph[i].clear();
            weight[i].clear();
        }


        for( int i = 0; i < n-1 ; i++ )
        {
            scanf("%d %d %d",&u,&v,&cost);

            Graph[u].push_back(v);         
            Graph[v].push_back(u);

            weight[u].push_back(cost);      
            weight[v].push_back(cost);
        }

        int max_distance=-1,first_node;

        reset(n);


        bfs(0,n);

        for(int i = 0; i < n; i++)
        {
            if(dis[i]>max_distance)
            {
                max_distance = dis[i];
                first_node=i;
            }
        }
        reset(n);
        int ans=0;

        bfs(first_node,n);

        for(int i=0; i<n; i++)
        {
            if(dis[i]>ans)
            {
                ans = dis[i];
            }
        }
        printf("Case %d: %d\n",++cs,ans);

    }
    return 0;
}
