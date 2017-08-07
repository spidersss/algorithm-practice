#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int NP = 100;
const int NT = 100;

struct Node {
    int k;
    struct Node *next;
};

int np, nt, nf;
int p[NP], p1[NP], t[NT][NP];

int main()
{
    int kase = 0;
    while (scanf("%d", &np) && np) {
        for (int i = 1; i <= np; i++)
          scanf("%d", &p[i]);
        scanf("%d", &nt);
        memset(t, 0, sizeof(t));
        for (int i = 1; i <= nt; i++) {
            int j;
            while (scanf("%d", &j) && j) {
                if (j > 0) t[i][j]++;
                else t[i][-j]--;
            }
        }
        scanf("%d", &nf);

        int f = 1;
        for (; f <= nf; f++) {
            int i;
            for (i = 1; i <= nt; i++) {
                int j;
                for (j = 1; j <= np; j++) {
                    p1[j] = p[j]+t[i][j];
                    if (p1[j] < 0) break;
                }
                if (j > np) {
                    memcpy(p, p1, sizeof(p1));
                    break;
                }
            }
            if (i > nt) break;
        }

        if (f > nf) printf("Case %d: still live ", ++kase);
        else printf("Case %d: dead ", ++kase);
        printf("after %d transitions\nPlaces with tokens:", f-1);
        for (int i = 1; i <= np; i++)
            if (p[i] > 0) printf(" %d (%d)", i, p[i]);
        printf("\n\n");
    }

    return 0;
}
