#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <string.h>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <complex>
#include <cassert>

using namespace std;

#define INF __INT_MAX__
#define INFL __LONG_LONG_MAX__
#define pb push_back
#define fi first
#define se second
#define mp make_pair

typedef long long ll;
typedef long double ld;
typedef complex <double> point;

#define NAME "b"
//~ #undef NAME
#ifndef NAME
    #error "Write problem name"
#endif

char s[1001];
char t[1001];
int to[201][201];
int p[201][201];
int cnt[201][201];

int main() {
    #ifdef _GEANY
    assert(freopen(NAME ".in", "r", stdin));
    #endif
    int nn, mm;
    scanf("%d%d\n", &nn, &mm);
    gets(s);
    gets(t);
    int n = strlen(s);
    int m = strlen(t);
    for (int i = 0; i < n; ++i)
        s[i + n] = s[i];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            for (int k = i + 1; k <= 2 * n; ++k)
                if (s[k] == t[j] || k == 2 * n) {
                    if (k >= n)
                        to[i][j] = k - n;
                    else
                        to[i][j] = k;
                    break;
                }
    int x = 0;
    int y = (s[0] == t[0]) % m;
    p[x][y] = 1;
    cnt[x][y] = (s[0] == t[0] && m == 1);
    int per = 1;
    int c = cnt[x][y];
    char flag = 0;
    while (1) {
        int t = to[x % n][y];
        if (t == n) {
            cout << c / mm << '\n';
            return 0;
        }
        if (t <= x)
            ++per;
        if (per > nn) {
            cout << c / mm << '\n';
            return 0;
        }
        int ty = y + 1;
        if (ty >= m) {
            ++c;
            ty = 0;
        }
        if (p[t][ty] && !flag) {
            flag = 1;
            int pl = per - p[t][ty];
            int dc = c - cnt[t][ty];
            while (per + pl <= nn) {
                per += pl;
                c += dc;
            }
        }
        x = t;
        y = ty;
        p[x][y] = per;
        cnt[x][y] = c;
    }
}