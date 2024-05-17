#include<bits/stdc++.h>
using namespace std;

bool iCycle(int V, vector<int> adj[])
{
    vector<int>p;
    p.resize(V,-1);
    queue<int>q;
    q.push(0);
    p[0]=0;

    while(!q.empty()){
        int parent=q.front();
        q.pop();
        p[parent]=1;

        for(int i=0;i<adj[parent].size();i++){
            int child=adj[parent][i];
            if(p[child]==0)
                return true;
            if(p[child]!=1){
                q.push(child);
                p[child]=0;
            }
        }
    }
    return false;
}

bool detect(int src, vector<int>adj[],vector<int>vis)
{
    queue<pair<int,int>>pr;
    pr.push({src,-1});
    vis[src]=1;

    while(!pr.empty()){
        int node=pr.front().first;
        int parent=pr.front().second;
        pr.pop();

        for(auto adjnode:adj[node]){
            if(!vis[adjnode]){
                vis[adjnode]=1;
                pr.push({adjnode,node});
            }
            else if(parent!=adjnode)
                return true;
        }
    }
    return false;
}

bool isCycle(int V, vector<int> adj[])
{
    vector<int >vis;
    vis.resize(V,0);
    for(int i=0;i<V;i++){
        if(!vis[i]){
            if(detect(i,adj,vis)) return true;
        }
    }
    return false;
}

int main()
{
    int n,e;
    cin>>n>>e;
    vector<int>adj[n];

    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cout<<isCycle(n,adj)<<endl;
    return 0;
}
/**

5 5

0 1
0 2
2 3
2 4
3 4

*/
