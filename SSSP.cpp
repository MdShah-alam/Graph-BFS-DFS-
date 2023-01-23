#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int visited[N];
vector<int>adj_list[N];
int level[N];

void bfs(int src)
{
    visited[src]=1;
    queue<int>q;
    q.push(src);
    level[src]=0;

    while(!q.empty())
    {
        int head=q.front();
        q.pop();
        cout<<head<<" ";
        for(auto i:adj_list[head])
        {
            if(visited[i]==0)
            {
                level[i]=level[head]+1;
                visited[i]=1;
                q.push(i);
            }
        }
    }
}
/**
      5
      |
0-----1----2
     /     |
    /      |
   3       4----6----7

nodes = 8
edges = 7

8 7

0 1
1 5
1 3
1 2
2 4
4 6
6 7

**/
int main()
{
    int nodes , edges;
    cin>>nodes>>edges;
    for(int i=0;i<edges;i++)
    {
        int u,v;
        cin>>u>>v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    int src=0;
    bfs(src);
    cout<<endl;

    for(int i=0;i<nodes;i++)
    {
        cout<<i<<" --> "<<level[i]<<endl;
    }
    return 0;
}
