#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>>edgeList;
vector<int>parent;

int main()
{
    int n,e;
    cin>>n>>e;
    parent.resize(n,-1);
    for(int x:parent)
        cout<<x<<" ";
    cout<<endl<<"Enter node = ";

    while(e--){
        int a,b;
        cin>>a>>b;
        edgeList.push_back({a,b});
    }

    return 0;
}
