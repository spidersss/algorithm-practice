# include<iostream>
# include<cstdio>
# include<cstring>
# include<algorithm>
using namespace std;
 
int vis[10];
char mp[8][15],p1[8][15];
 
bool judge()
{
    for(int i=0;i<5;++i)
        for(int j=0;j<9;++j)
            if(mp[i][j]!=p1[i][j])
                return false;
    return true;
}
 
bool dfs(int step)
{
    if(judge())
        return true;
 
    if(step>=6)
        return false;
 
    char p2[6][10];
    for(int i=0;i<5;++i)
        for(int j=0;j<9;++j)
            p2[i][j]=p1[i][j];
 
    for(int i=0;i<9;++i){
        if(vis[i])
            continue;
 
        vis[i]=1;
        int r=i/3,c=2*(i%3)+1;
        p1[r][c]=p1[r][c+2]=p1[r+2][c]=p1[r+2][c+2]='_';
        p1[r+1][c-1]=p1[r+2][c-1]=p1[r+1][c+3]=p1[r+2][c+3]='|';
        p1[r+1][c]=p1[r+1][c+1]=p1[r+1][c+2]=p1[r+2][c+1]=' ';
 
        if(dfs(step+1))
            return true;
 
        vis[i]=0;
        for(int i=0;i<5;++i)
            for(int j=0;j<9;++j)
                p1[i][j]=p2[i][j];
    }
 
    return false;
}
 
int main()
{
    int cas=0;
    while(1)
    {
        for(int i=0;i<5;++i){
            gets(mp[i]);
            if(mp[i][0]=='0')
                return 0;
        }
        printf("Case %d: ",++cas);
 
        for(int i=0;i<5;++i)
            for(int j=0;j<9;++j)
                p1[i][j]=' ';
 
        memset(vis,0,sizeof(vis));
        if(dfs(0))
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
