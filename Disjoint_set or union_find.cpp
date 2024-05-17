#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>>edgeList;
vector<int>parent;

int find_parent(int x)
{
    if(parent[x]==-1) return x;
    find_parent(parent[x]);
}

void union_operation(int a, int b)
{
    int parentA = find_parent(a);
    int parentB = find_parent(b);
    parent[parentA] = parentB;
}

int main()
{
    int n,e;
    cin>>n>>e;
    parent.resize(n,-1);

    while(e--){
        int a,b;
        cin>>a>>b;
        edgeList.push_back({a,b});
    }

    bool cycle=false;

    for(int i=0;i<edgeList.size();i++){
        pair<int,int>pr = edgeList[i];
        int a,b;
        a=pr.first;
        b=pr.second;
        int parentA=find_parent(a);
        int parentB=find_parent(b);

        if(parentA==parentB){
            cycle=true;
            break;
        }
        parent[parentA] = parentB;
    }

    if(cycle)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;

    return 0;
}
/**

6 4

0 1
4 5
0 2
0 3

*/
