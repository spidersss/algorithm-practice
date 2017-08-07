#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
using namespace std;

const int N = 64+1;

int n;
char area[N][N];
vector<int> nums;
set<string> strs;

bool same_color(int x0, int y0, int x1, int y1)
{
    char color0 = area[x0][y0];
    for (int i = x0; i < x1; i ++)
        for (int j = y0; j < y1; j ++)
            if (area[i][j] != color0) return false;
    return true;
}

int str2num(string s)
{
    int res = 0;
    for (int i = 0; i < s.size(); i++)
        res = res*5 + s[i]-'0';
    return res;
}

void get_nums(int x0, int y0, int x1, int y1, string s)
{
    if (same_color(x0, y0, x1, y1)) {
        if (area[x0][y0] == '1') nums.push_back(str2num(s));
        return;
    }
    int mx = (x0+x1) / 2;
    int my = (y0+y1) / 2;
    get_nums(x0, y0, mx, my, '1'+s);
    get_nums(x0, my, mx, y1, '2'+s);
    get_nums(mx, y0, x1, my, '3'+s);
    get_nums(mx, my, x1, y1, '4'+s);
}

void set_black(int x0, int y0, int x1, int y1)
{
    for (int i = x0; i < x1; i ++)
        for (int j = y0; j < y1; j ++)
            area[i][j] = '*';
}

string num2str(int num)
{
    string s;
    while (num) {
        char tmp = num%5 + '0';
        s = tmp + s;
        num /= 5;
    }
    return s;
}

void set_area(int x0, int y0, int x1, int y1, string s)
{
    if (strs.count(s)) {
        set_black(x0, y0, x1, y1);
        return;
    }
    if (x0 + 1 == x1 && y0 + 1 == y1) return;
    int mx = (x0+x1) / 2;
    int my = (y0+y1) / 2;
    set_area(x0, y0, mx, my, '1'+s);
    set_area(x0, my, mx, y1, '2'+s);
    set_area(mx, y0, x1, my, '3'+s);
    set_area(mx, my, x1, y1, '4'+s);
}

int main(void)
{
    freopen("input.txt", "r", stdin);
    int kase = 0;
    while (scanf("%d", &n) && n) {
        if (kase) printf("\n");
        printf("Image %d\n", ++kase);
        if (n > 0) {
            for (int i = 0; i < n; i++)
                scanf("%s", area[i]);
            nums.clear();
            get_nums(0, 0, n, n, "");
            sort(nums.begin(), nums.end());
            for (int i = 0; i < nums.size(); i++)
                printf("%d%c", nums[i], (i == nums.size()-1 || i % 12 == 11) ? '\n' : ' ');
            printf("Total number of black nodes = %d\n", nums.size());
        } else {
            n = -n;
            strs.clear();
            int x; 
            while (scanf("%d", &x) && x != -1)
                strs.insert(num2str(x));
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    area[i][j] = '.';
                }
                area[i][n] = '\0';
            }
            set_area(0, 0, n, n, "");
            for (int i = 0; i < n; i++)
                printf("%s\n", area[i]);
        }
    }

    return 0;
}
