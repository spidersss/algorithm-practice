#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 52;

typedef pair<char, char> P;

vector<P> pile[N+1];
int pre[N+1], next[N+1];

void init()
{
    for (int i = 1; i <= N; i++) {
        pre[i] = i-1;
        next[i-1] = i;
        pile[i].clear();
    }
    pre[0] = N;
    next[N] = 0;
}

int pre3(int u)
{
    int cnt = 3;
    while (u && cnt) {
        u = pre[u];
        cnt--;
    }
    return u;
}

bool same_top(int u, int v)
{
    P a = pile[u][pile[u].size()-1];
    P b = pile[v][pile[v].size()-1];
    return a.first == b.first || a.second == b.second;
}

void del(int u)
{
    next[pre[u]] = next[u];
    pre[next[u]] = pre[u];
}

void move_top(int u, int v)
{
    int lenu = pile[u].size();
    P a = pile[u][lenu-1];
    pile[v].push_back(a);
    pile[u].resize(lenu-1);
    if (lenu-1 == 0) del(u);
}

int main(void)
{
    char s[3];
    freopen("input1.txt", "r", stdin) ;
    while (scanf("%s", s) && strcmp(s, "#")) {
        init();
        for (int i = 1; i <= N; i++) {
            if (i > 1) scanf("%s", s);
            pile[i].push_back(P(s[0], s[1]));
        }

        while (true) {
            int u = next[0];
            while (u) {
                bool flag = true;
                int v = pre3(u);
                if (v && same_top(u, v)) move_top(u, v);
                else if ((v = pre[u]) && same_top(u, v)) move_top(u, v);
                else flag = false;
                if (flag) break;
                u = next[u];
            }
            if (!u) break;
        }

        vector<int> res;
        int u = next[0];
        while (u) {
            res.push_back(pile[u].size());
            u = next[u];
        }
        if (res.size() == 1) printf("1 pile remaining:");
        else printf("%d piles remaining:", res.size());
        for (int i = 0; i < res.size(); i++)
            printf(" %d", res[i]);
        printf("\n");
    } 

    return 0;
}   
