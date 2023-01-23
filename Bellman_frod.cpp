#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
const int INF=1e9;
int dis[N];
vector<pair<int,int>>adj_list[N];
/**
4 4

1 2 10
1 3 5
2 3 -12
3 4 4

**/
int main()
{
    int nodes,edges;
    cin>>nodes>>edges;
    for(int i=0; i<edges; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj_list[u].push_back({v,w});
    }
    for(int i=1; i<=nodes; i++)
    {
        dis[i]=INF;
    }
    int src=1;
    dis[src]=0;

    bool negative_cycle=false;

    for(int i=1; i<=nodes; i++)
    {
        for(int node=1; node<=nodes; node++)
        {
            for(pair<int,int>adj_node:adj_list[node])
            {
                int u=node;
                int v=adj_node.first;
                int w=adj_node.second;

                if(dis[u]+w<dis[v])
                {
                    dis[v]=dis[u]+w;
                    if(i==nodes)
                        negative_cycle=true;
                }
            }
        }
    }

    if(negative_cycle)
        cout<<"Cycle exist";
    else
    {
        for(int i=1; i<=nodes; i++)
        {
            cout<<dis[i]<<" ";
        }
    }
    cout<<endl;
    return 0;
}
