#include<bits/stdc++.h>
using namespace std;
const int N=100;
int visited[N];
int parent[N];
int level[N];
int matrix[N][N];
int n,m;

void bfs(int src)
{
    queue<int>q;
    q.push(src);
    visited[src]=1;
    level[src]=0;
    parent[src]=-1;

    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        cout<<u<<" ";
        for(int i=1; i<=n; i++)
        {
            if(matrix[u][i]==1)
            {
                if(visited[i]==0)
                {
                    level[i]=level[u]+1;
                    visited[i]=1;
                    parent[i]=u;
                    q.push(i);
                }
            }
        }
    }
}
/**
5 6

1 2
1 3
2 3
2 4
3 5
5 2

*/
int main()
{
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        int u,v;
        cin>>u>>v;
        matrix[u][v]=1;
        matrix[v][u]=1;
    }

    int src_node=1;
    bfs(src_node);
    int dst_node=n;
    cout<<endl;


    if(visited[dst_node]==0)
    {
        cout<<"IMPOSSIBLE";
        return 0;
    }

    cout<<level[dst_node]<<endl;

    vector<int>ans;
    int selected_node=dst_node;

    while(true)
    {
        ans.push_back(selected_node);
        if(selected_node==src_node)
            break;
        selected_node=parent[selected_node];
    }

    reverse(ans.begin(),ans.end());

    for(int node:ans)
    {
        cout<<node<<" ";
    }

    return 0;
}
