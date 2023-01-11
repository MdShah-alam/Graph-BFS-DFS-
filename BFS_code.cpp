#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int visited[N];

vector<int>adj_list[N];

void bfs(int src)
{
    queue<int>q;
    visited[src]=1;
    visited[4]=1;
    q.push(src);
    q.push(4);
    while(!q.empty())
    {
        int head=q.front();
        q.pop();
        cout<<head<<" ";
        for(int adj_node: adj_list[head])
        {
            if(visited[adj_node]==0)
            {
                visited[adj_node]=1;
                q.push(adj_node);
            }
        }
    }
}
/**
            7
            |
            |
1-----2-----3----5
      |     |
      |     |
      6-----4

node=6
edge=6
1 2 6 3 4 5
1 4 2 3 6 5
7 7

1 2
2 6
2 3
3 4
3 7
3 5
4 6
*/

int main()
{
    int nodes,edges;
    cin>>nodes>>edges;
    for(int i=0; i<edges; i++)
    {
        int u,v;
        cin>>u>>v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    int src=1;
    bfs(src);

    return 0;
}
