#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
const long long INF=1e18;
vector<pair<int,int>>adj_list[N];
long long dis[N];
int parent[N];
/**
4 5

1 2 1
2 4 1
3 1 1
4 1 -3
4 3 -2
*/
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj_list[u].push_back({v,w});
    }

    for(int i=1; i<=n; i++)
    {
        dis[i]=INF;
    }

    bool negative_cycle=false;
    int last_updated_node=-1;

    for(int i=1; i<=n; i++)
    {
        for(int node=1; node<=n; node++)
        {
            for(pair<int,int>adj_entry:adj_list[node])
            {
                int u=node;
                int v=adj_entry.first;
                int w=adj_entry.second;
                if(dis[u]+w<dis[v])
                {
                    dis[v]=dis[u]+w;
                    parent[v]=u;
                    if(i==n)
                    {
                        last_updated_node=v;
                        negative_cycle=true;
                    }
                }
            }
        }
    }

    if(negative_cycle)
    {
        cout<<"YES"<<endl;
        int selected_node=last_updated_node;
        for(int i=1;i<n;i++)
        {
            selected_node=parent[selected_node];
        }
        int first_node=selected_node;
        vector<int>cycle;
        cycle.push_back(selected_node);
        while(true)
        {
            selected_node=parent[selected_node];
            cycle.push_back(selected_node);
            if(selected_node==first_node)
                break;
        }
        cout<<cycle.size()<<endl;
        reverse(cycle.begin(),cycle.end());
        for(int node:cycle)
            cout<<node<<" ";
    }
    else
        cout<<"NO";
    cout<<endl;
    return 0;
}
