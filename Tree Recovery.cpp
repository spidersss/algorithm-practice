#include<cstdio>  
#include<cstring>  
const int N=20;  
char s1[N], s2[N], ans[N];//s1[N],s2[N]分别为先序和中序遍历序列  
void build(int n, char* s1, char* s2, char* s)  
{  
    if(n <= 0) return;  
    int p = strchr(s2, s1[0]) - s2;//找到根结点的位置  
    build(p, s1+1, s2, s);//递归构造左子树的后序遍历  
    build(n-p-1, s1+p+1, s2+p+1, s+p);//递归构造右子树的后序遍历  
    s[n-1] = s1[0];//把根结点添加到最后  
}  
int main()  
{  
    while(scanf("%s%s",s1, s2) == 2)  
    {  
        int n= strlen(s1);  
        build(n, s1,s2, ans);  
        ans[n] = '\0';  //末尾置0 
        printf("%s\n",ans);  
        return 0;  
    }  
}  
