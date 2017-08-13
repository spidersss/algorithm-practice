#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;

const char tow[] = "ensw";
const int dir[4][2] = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};

typedef pair<int, int> P;

int n, k;
int G[250][250];
const int OFF = 105;
set<P> block;
int path_count;
vector<int> path;

void found_path()
{
    for (int i = 0; i < path.size(); i++)
      printf("%c", tow[path[i]]);
    printf("\n");
    path_count++;
}

void dfs(P p)
{
    if (path.size() == n) {
        if (p == P(0, 0))
          found_path();
        return;
    }

    int m = path.size();
    for (int i = 0; i < 4; i++) {
        if (m && (path[m-1]+1)%4/2 == (i+1)%4/2) continue;
        P p1 = p;
        bool flag = true;
        for (int j = 1; j <= m+1; j++) {
            p1.first += dir[i][0];
            p1.second += dir[i][1];
            int x = p1.first, y = p1.second;
            if (abs(x) > OFF || abs(y) > OFF || G[p1.first+OFF][p1.second+OFF] == -1) {flag = false; break;}
        }
        if (flag && G[p1.first+OFF][p1.second+OFF] != 1) {
            path.push_back(i);
            G[p1.first+OFF][p1.second+OFF] = 1;
            dfs(p1);
            G[p1.first+OFF][p1.second+OFF] = 0;
            path.resize(m);
        }
    }
}

int main()
{
    int kase;
    scanf("%d", &kase);
    for (int t = 1; t <= kase; t++) {
        scanf("%d%d", &n, &k);
        int x, y;
        memset(G, 0, sizeof(G));
        for (int i = 0; i < k; i++) {
            scanf("%d%d", &x, &y);
            G[x+OFF][y+OFF] = -1;
        }

        path_count = 0;
        path.clear();
        dfs(P(0, 0));
        printf("Found %d golygon(s).\n\n", path_count);
    }

    return 0;
}
