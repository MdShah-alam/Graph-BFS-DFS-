#include<bits/stdc++.h>
using namespace std;
const int N=1002;
int maze[N][N]={0};
int visited[N][N]={0};
int level[N][N];
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};
int n,m;

bool is_inside(pair<int,int>coord)
{
    int x=coord.first;
    int y=coord.second;
    if(x>=0 && x<n && y>=0 && y<m)
        return true;
    return false;
}

void bfs(pair<int,int>src)
{
    queue<pair<int,int>>q;
    visited[src.first][src.second]=1;
    level[src.first][src.second]=0;
    q.push(src);

    while(!q.empty()){
        pair<int,int>parent=q.front();
        q.pop();
        int x=parent.first;
        int y=parent.second;

        for(int i=0;i<4;i++){
            int new_x=x+dx[i];
            int new_y=y+dy[i];

            pair<int,int>adj_node={new_x,new_y};

            if(is_inside(adj_node)&& maze[new_x][new_y]!=-1 && visited[new_x][new_y]==0){
                visited[new_x][new_y]=1;
                level[new_x][new_y]=level[x][y]+1;
                q.push(adj_node);
            }
        }
    }

}

int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            level[i][j]=-1;
        }
    }
    pair<int,int>src,dst;
    for(int i=0;i<n;i++){
        string input;
        cin>>input;
        for(int j=0;j<m;j++){
            if(input[j]=='#')
                maze[i][j]=-1;
            else if(input[j]=='A'){
                src={i,j};
            }
            else if(input[j]=='B'){
                dst={i,j};
            }
        }
    }

    bfs(src);

    if(level[dst.first][dst.second])
        cout<<"Yes"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}
/**

5 8
########
#.A#...#
#.##.#B#
#......#
########

*/
