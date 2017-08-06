#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
int dir[8][2]={{2,-1},{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2}};     //八个方向
int map[10][10];
struct node
{
    int x,y,count;
}now, next;
int main()
{
    
    char c_1,c_2;
    int r1,r2,c1,c2;
    while(cin>>c_1>>r1>>c_2>>r2)
    {
        c1=c_1-'a'+1;                 
        c2=c_2-'a'+1;
        memset(map, 0, sizeof(map));    //地图清零，以便记录马是否到过
        map[c1][r1]=1;
        now.x=c1;now.y=r1;now.count=0;
        queue<node> d;
        d.push(now);
        while(!d.empty())           //BFS
        {
            next=d.front();
            d.pop();
            if(next.x==c2&&next.y==r2)break;//到达终点 
            for(int i=0;i<8;i++)
            {
                now.x=next.x+dir[i][0];
                now.y=next.y+dir[i][1];
                if(now.x<1||now.x>8||now.y<1||now.y>8)continue; //超过棋盘 
                if(map[now.x][now.y]==1)continue;//已走过 
                map[now.x][now.y]=1;
                now.count=next.count+1;
                d.push(now);
            }
        }
        printf("To get from %c%d to %c%d takes %d knight moves.\n",c_1,r1,c_2,r2,next.count);
    }
    return 0;
}
