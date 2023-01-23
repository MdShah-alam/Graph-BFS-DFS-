#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int visited[N];
vector<int>adj_list[N];
stack<int>st;

/**

5 3

1 2
3 2
4 5

**/

void dfs(int node)
{
    visited[node]=1;
    for(int adj_node:adj_list[node])
    {
        if(visited[adj_node]==0)
            dfs(adj_node);
    }
    st.push(node);
}

int main()
{
    int nodes , edges;
    cin>>nodes>>edges;
    for(int i=1;i<=edges ; i++)
    {
        int u,v;
        cin>>u>>v;
        adj_list[u].push_back(v);
    }

    for(int i=1;i<=nodes;i++)
    {
        if(visited[i]==0)
            dfs(i);
    }

    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
    return 0;
}
