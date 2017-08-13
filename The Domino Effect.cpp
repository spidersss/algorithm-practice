#include <stdio.h>
#include <string.h>
#define ms(a) memset(a,0,sizeof(a))
const int maxn = 10;
int pips[maxn][maxn],bone[maxn][maxn];
int table[maxn][maxn];
int dx[] = {0,1};
int dy[] = {1,0};
int visit[30],ans;
bool input(){
    for(int i=0;i<7;i++)
            for(int j=0;j<8;j++) if(scanf("%d",&pips[i][j]) != 1) return false;
    return true;
}
void init(){//�������ı�񱣴浽�����
    int num = 1;
    for(int i=0;i<7;i++)
        for(int j=i;j<7;j++)
            table[i][j] = table[j][i] = num++;
}
void put(int a[][maxn]){
    for(int i=0;i<7;i++){
        for(int j=0;j<8;j++) printf("%4d",a[i][j]);printf("\n");
    }printf("\n");
}
void dfs(int x,int y,int steps){
    if(steps == 28){//��28������ȫ�������ʱ˵���ź���
        ans++;put(bone);
        return;
    }
    if(y == 8){//����
        x++;y = 0;
    }
    if(bone[x][y]) dfs(x,y+1,steps);//����λ�ñ��ʱ���еݹ���һλ��
    else{
        for(int i=0;i<2;i++){//����λ�ã��º���
            int tx = x + dx[i], ty = y + dy[i];
            if(tx >= 7 || ty >= 8 || bone[tx][ty]) continue;//������Χ���λ���б����
            int tem = table[pips[x][y]][pips[tx][ty]];//����һλ�õ�pips���·����ҷ��Ķ�Ӧ��bone�ҵ�
            if(visit[tem]) continue;//�Ƿ�˱��ʹ�ù�

            visit[tem] = 1;bone[x][y] = bone[tx][ty] = tem;//����λ�÷�������
            dfs(x,y+1,steps+1);//�ƶ�һ�����
            bone[x][y] = bone[tx][ty] = 0;visit[tem] = 0;//����
        }
    }
}
int main()
{
    int kcase = 0;
    init();
    while(input()){
        if(kcase) printf("\n\n\n");
        printf("Layout #%d:\n\n",++kcase);
        put(pips);
        printf("Maps resulting from layout #%d are:\n\n",kcase);
        ms(visit);ms(bone);ans = 0;
        dfs(0,0,0);
        printf("There are %d solution(s) for layout #%d.\n",ans,kcase);
    }
    return 0;
}

