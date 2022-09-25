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

#define INF 1000000001
#define INFL 1000000000000000001ll
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

char a[100][100];
int pr[100][100];
ll ans[42][42][42][42];
ll d[42][42][42][42];

int main() {
    #ifdef _GEANY
    assert(freopen(NAME ".in", "r", stdin));
    #endif
    int n, m, q;
    scanf("%d%d%d\n", &n, &m, &q);
    for (int i = 0; i < n; ++i)
        scanf("%s", a[i]);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            a[i][j] -= '0';
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            pr[i + 1][j + 1] = pr[i][j + 1] + pr[i + 1][j] - pr[i][j] + a[i][j];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            for (int x = 1; i + x <= n; ++x)
                for (int y = 1; j + y <= m; ++y) {
                    d[i][j][x][y] = d[i][j][x - 1][y] + d[i][j][x][y - 1] - d[i][j][x - 1][y - 1];
                    if (pr[i + x][j + y] - pr[i][j + y] - pr[i + x][j] + pr[i][j] == 0)
                        ++d[i][j][x][y];
                }
    for (int x = 1; x <= n; ++x)
        for (int y = 1; y <= m; ++y)
            for (int i = 0; i + x <= n; ++i)
                for (int j = 0; j + y <= m; ++j) {
                    ans[i][j][x][y] = ans[i + 1][j][x - 1][y] + ans[i][j + 1][x][y - 1] - ans[i + 1][j + 1][x - 1][y - 1];
                    ans[i][j][x][y] += d[i][j][x][y];
                }
    for (int i = 0; i < q; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        --x1, --y1;
        cout << ans[x1][y1][x2 - x1][y2 - y1] << '\n';
    }
}