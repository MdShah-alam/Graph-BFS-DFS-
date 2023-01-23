#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int visited[N];
vector<int>adj_list[N];
/**

4 4

1 3
2 1
2 4
3 4

**/

bool cycle_detected(int node)
{
    visited[node]=1;
    for(int adj_node:adj_list[node])
    {
        /**
        - visited[adj_node]=0 -> unexplored node | apply cycle_detected()
        - visited[adj_node]=1 -> " paused " node | cycle detected
        - visited[adj_node]=2 -> " done " node | continue
        **/
        if(visited[adj_node]==0)
        {
            bool get_cycle=cycle_detected(adj_node);
            if(get_cycle)
                return true;
        }
        else if(visited[adj_node]==1)
            return true;
    }
    visited[node]=2;
    return false;
}

int main()
{
    int nodes,edges;
    cin>>nodes>>edges;
    for(int i=1;i<=edges;i++)
    {
        int u,v;
        cin>>u>>v;
        adj_list[u].push_back(v);
    }

    bool cycle=false;
    for(int i=1;i<=nodes;i++)
    {
        if(visited[i]==0)
        {
            bool get_cycle=cycle_detected(i);
            if(get_cycle)
            {
                cycle=true;
                break;
            }
        }
    }
    if(cycle)
        cout<<"cycle exist ."<<endl;
    else
        cout<<"cycle not exist ."<<endl;
    return 0;
}
