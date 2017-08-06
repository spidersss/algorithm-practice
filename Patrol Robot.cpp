#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};     //4个方向
const int maxn = 25; 
int map[maxn][maxn];
int map_walk[maxn][maxn];
struct node
{
    int x,y,count;
}now, next;
int main()
{
    
    int m, n;
    int flag;
    memset(map, 0, sizeof(map)) ;
    memset(map_walk, 0, sizeof(map_walk));
    cin>>m>>n;
    for(int i = 1; i <= m; i++){
    	for(int j = 1; j <= n; j++){
    	cin>>flag;
		map[i][j] = flag;
		//cout<<map[i][j]<<" ";
		}
		//cout<<"\n";
	}
    map_walk[1][1]=-1;
    now.x=1;now.y=1;now.count=0;
    queue<node> d;
    d.push(now);
    while(!d.empty())           //BFS
    {
        next=d.front();
        d.pop();
        if(next.x==n&&next.y==m)break;//到达终点 
        for(int i=0;i<4;i++)
        {
            now.x=next.x+dir[i][0];
            now.y=next.y+dir[i][1];
            if(now.x<1||now.x>n||now.y<1||now.y>m)continue; //超出地图 
            if(map_walk[now.y][now.x]==-1)continue;//已走过 
            if(map[next.y][next.x] == 1 && map[now.y][now.x] == 1) continue;
            map_walk[now.y][now.x]=-1;
            now.count=next.count+1;
            d.push(now);
        }
    }
    /*for(int i = 1 ; i <= m; i++){
    	for( int j = 1;  j <= n; j++){
    	cout<<map_walk[i][j]<<" ";
		}
		cout<<"\n";
	}*/
    printf("It takes %d moves from the begin to the end.\n",next.count);
    return 0;
}
