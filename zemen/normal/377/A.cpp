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
typedef complex <ld> point;

#define NAME "a"
//~ #undef NAME
#ifndef NAME
    #error "Write problem name"
#endif

int n, m, k;
char a[1001][1001];
char used[1001][1001];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void dfs(int x, int y) {
    used[x][y] = 1;
    for (int dir = 0; dir < 4; ++dir) {
        int cx = x + dx[dir];
        int cy = y + dy[dir];
        if (cx < 0 || cx >= n || cy < 0 || cy >= m || a[cx][cy] == '#')
            continue;
        if (used[cx][cy])
            continue;
        dfs(cx, cy);
    }
    if (k) {
        a[x][y] = 'X';
        --k;
    }
}

int main() {
    #ifdef _GEANY
    assert(freopen(NAME ".in", "r", stdin));
    #endif
    scanf("%d%d%d\n", &n, &m, &k);
    for (int i = 0; i < n; ++i)
        gets(a[i]);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (a[i][j] == '.') {
                dfs(i, j);
                for (int x = 0; x < n; ++x)
                    puts(a[x]);
                return 0;
            }
}