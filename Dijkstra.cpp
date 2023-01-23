#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
const int INF=1e9;
vector<pair<int,int>>adj_list[N];
int nodes,edges;
int dis[N],visited[N];

void dijkstra(int src)
{
    for(int i=1;i<=nodes;i++){
        dis[i]=INF;
    }
    dis[src]=0;
    for(int i=0;i<nodes;i++){
        int selected_node=-1;
        for(int j=1;j<=nodes;j++){
            if(visited[j]==1) continue;
            if(selected_node == -1 || dis[selected_node]>dis[j]){
                selected_node=j;
            }
        }
        visited[selected_node]=1;
        for(auto adj_entry:adj_list[selected_node]){
            int adj_node=adj_entry.first;
            int edge_cost=adj_entry.second;

            if((dis[selected_node]+edge_cost)<dis[adj_node]){
                dis[adj_node]=dis[selected_node]+edge_cost;
            }
        }
    }
}
/**
6 8

1 2 4
1 3 4
2 3 2
3 4 3
3 5 1
3 6 6
5 6 3
4 6 2

*/
int main()
{
    cin>>nodes>>edges;
    for(int i=0;i<edges;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj_list[u].push_back({v,w});
        adj_list[v].push_back({u,w});
    }
    int src=1;
    dijkstra(src);

    for(int i=1;i<=nodes;i++){
        cout<<dis[i]<<" ";
    }
    cout<<endl;
    return 0;
}
