#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn = 21;
int G[maxn][maxn], k, maxPoint, ans;
int visit[maxn];

void dfs(int steps, int location, int path[]){
	if(location==k){
		for(int i=0; i<steps-1; i++){
			printf("%d", path[i]);
		}
		printf("%d\n", path[steps-1]);
		ans++;
		return;
	}
	for(int i=2; i<=maxPoint; i++){
		if(G[location][i] && !visit[i]){
			visit[i] = 1;
			path[steps] = i;
			dfs(steps+1, i, path);
			visit[i] = 0;
		}
	}	
}
int main(){
	int u, v, kase = 1;
	while(scanf("%d", &k)!=EOF && k){
		maxPoint = 0;
		memset(G, 0, sizeof(G));
		while(scanf("%d%d", &u, &v) && (u||v)){
			G[u][v] = G[v][u] = 1;
			maxPoint = max(maxPoint, max(u,v));
		}
		ans = 0;
		printf("CASE %d:\n", kase++);
		bool flag = 0;
		for(int i=1; i <= maxPoint; i++)
			if(G[k][i]){
				flag = 1;
				break;
			}
		if(flag){
			memset(visit, 0 , sizeof(visit));
			int path[maxn] = {1};
			dfs(1, 1, path);
		}
		printf("There are %d routes from the firestation to streetcorner %d.\n", ans, k);
		
	}
	
	return 0;
}
