#include<cstdio>  
#include<cstring>  
const int N=20;  
char s1[N], s2[N], ans[N];//s1[N],s2[N]�ֱ�Ϊ����������������  
void build(int n, char* s1, char* s2, char* s)  
{  
    if(n <= 0) return;  
    int p = strchr(s2, s1[0]) - s2;//�ҵ�������λ��  
    build(p, s1+1, s2, s);//�ݹ鹹���������ĺ������  
    build(n-p-1, s1+p+1, s2+p+1, s+p);//�ݹ鹹���������ĺ������  
    s[n-1] = s1[0];//�Ѹ������ӵ����  
}  
int main()  
{  
    while(scanf("%s%s",s1, s2) == 2)  
    {  
        int n= strlen(s1);  
        build(n, s1,s2, ans);  
        ans[n] = '\0';  //ĩβ��0 
        printf("%s\n",ans);  
        return 0;  
    }  
}  
