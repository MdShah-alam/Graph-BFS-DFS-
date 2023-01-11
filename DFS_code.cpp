#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int visited[N];

vector<int>adj_list[N];

void dfs(int node)
{
    cout<<node<<" ";
    for(int adj_node:adj_list[node])
    {
        if(visited[adj_node]==0)
            dfs(adj_node);
    }
}

/**
1-----2----3----5
      |     |
      |     |
      6-----4

node=6
edge=6

6 6

1 2
2 3
2 6
3 4
3 5
4 6
*/

int main()
{
    int nodes,edges;
    cin>>nodes>>edges;
    for(int i=0;i<edges;i++)
    {
        int u,v;
        cin>>u>>v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    int src=1;
    dfs(src);

    return 0;
}
