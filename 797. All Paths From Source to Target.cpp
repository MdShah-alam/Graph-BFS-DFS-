#include<bits/stdc++.h>
using namespace std;
vector<bool>visit;

void bfs(vector<vector<int>>graph,int src)
{
    queue<int>q;
    visit[src]=true;
    q.push(src);

    while(!q.empty()){
         int p=q.front();
         q.pop();
         cout<<p<<" ";
         for(int i=0;i<graph[p].size();i++){
            int child=graph[p][i];
            if(!visit[child]){
                visit[child]=true;
                q.push(child);
            }
         }
    }
}

void dfs(vector<vector<int>>&graph,vector<vector<int>>&result,vector<int>&v,int u)
{
    v.push_back(u);
    if(u==graph.size()-1)
        result.push_back(v);
    else{
        for(int x:graph[u])
            dfs(graph,result,v,x);
    }
    v.pop_back();
}

 vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph)
 {
     vector<vector<int>>result;
     vector<int>path;
     dfs(graph,result,path ,0);
     return result;
 }

int main()
{
    int n;
    cin>>n;
    vector<vector<int>>vv;
    visit.resize(n,false);

    for(int i=0;i<n;i++){
        cout<<"How many node connected with "<<i<<" : ";
        int e;
        cin>>e;
        vector<int>v;
        for(int j=0;j<e;j++){
            int a;
            cin>>a;
            if(a==-1) continue;
            v.push_back(a);
        }
        vv.push_back(v);
    }
//    bfs(vv,0);

    vector<vector<int>>v=allPathsSourceTarget(vv);

    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++)
            cout<<v[i][j]<<" ";
        cout<<endl;
    }

    return 0;
}

/**

4
2
1 2
1
3
1
3
1
-1

*/
