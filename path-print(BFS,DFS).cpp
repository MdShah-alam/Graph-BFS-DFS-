#include<bits/stdc++.h>
using namespace std;
vector<int> adj[1000];
vector<int>level;
vector<bool>visit;
vector<int>parent;

vector<int> print_path(int d)
{
    vector<int>path;
    int x=d;
    while(x!=-1){
        path.push_back(x);
        x=parent[x];
    }
    reverse(path.begin(),path.end());
    return path;
}

void dfs(int p)
{
    for(int i=0;i<adj[p].size();i++){
        int child=adj[p][i];

        if(level[p]+1<=level[child]){
            level[child]=level[p]+1;
            parent[child]=p;
        }
        if(!visit[child]){
            visit[child]=true;
            dfs(child);
        }
    }
}

vector<int> bfs(int src, int dst)
{
    queue<int>q;
    q.push(src);
    level[src]=0;
    visit[src]=true;
    vector<int>path;

    while(!q.empty()){
        int p=q.front();
        if(p==dst){
            path=print_path(dst);
            return path;
        }
        q.pop();
        for(int i=0;i<adj[p].size();i++){
            int child=adj[p][i];
            if(!visit[child]){
                visit[child]=true;
                q.push(child);
                level[child]=level[p]+1;
                parent[child]=p;
            }
        }
    }
    return path;
}

int main()
{
    int n,e;
    cin>>n>>e;
//    level.resize(n); //for bfs
    level.resize(n,INT_MAX);//for dfs
    visit.resize(n,false);
    parent.resize(n,-1);

    while(e--){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int src , dst;
    cin>>src>>dst;
    level[src]=0;// for dfs
//    vector<int>v=bfs(src,dst;
    dfs(src);
    cout<<level[dst]<<endl;//for dfs
    vector<int>v=print_path(dst);//for dfs
    for(int x:v)
        cout<<x<<" ";
    cout<<endl;

    return 0;
}/**

7 8
1 0
1 2
0 2
2 3
3 4
0 5
5 6
6 4

0 4

10 11
1 0
1 2
0 2
2 3
0 5
5 6
6 4
3 8
0 8
3 9
4 9

0 4

*/
