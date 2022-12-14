#include <iostream>
#include <cstring>
#include <utility>
#include <vector>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <complex>
#include <array>
#include <ctime>
#include <cassert>
#include <set>
#include <iomanip>
#include <random>
#include <cstdlib>
#include <chrono>
using namespace std;

int e[100001], nxt[100001], g[100001];
int tot = 1;
void add(int u, int v) {
    e[tot] = v; nxt[tot] = g[u]; g[u] = tot ++;
}
int cnt = 0;
int dfn[101], low[101], idx, stk[101];
int top, belong[101];
bool mark[101];
int na[101][101];
int n;
vector<int> E[101];
void dfs(int x) {
    dfn[x] = low[x] = ++ idx;
    stk[++ top] = x;
    for (int i = g[x]; i; i = nxt[i]) {
        if (!dfn[e[i]]) {
            dfs(e[i]);
            low[x] = min(low[x], low[e[i]]);
        }
        else if (!mark[e[i]]) low[x] = min(low[x], dfn[e[i]]);
    }
    if (low[x] == dfn[x]) {
        ++ cnt;
        int tmp;
        do { tmp = stk[top --]; mark[tmp] = true; E[cnt].push_back(tmp); belong[tmp] = cnt; } while (tmp != x);
    }
}

vector<int> ee[101];
int N;
int GRID[101][101][101];
int WALL = 100;
void out() {
    cout << N << " " << N << " " << N << endl;
    for (int z = N; z >= 1; cout << "\n", z--) {
        for (int x = 1; x <= N; cout << "\n", x++) {
            for (int y = 1; y <= N; y++) {
                if (GRID[z][x][y] == WALL) cout << "#";
                else if (GRID[z][x][y] == 0) cout << ".";
                else cout << GRID[z][x][y];
            }
        }
    }
}

int label[101];
bool vis1[101];
vector<int> topo;
void topoSort(int u) {
    vis1[u] = true;
    for (int v: ee[u]) if (!vis1[v]) {
        topoSort(v);
    }
    topo.push_back(u);
    label[u] = topo.size();
}

void solve() {
    N = 2 * topo.size() + 10;
    for (int z = 1; z <= N; z++) {
        for (int x = 1; x <= 2; x++) {
            for (int y = 1; y <= N; y++) {
                GRID[z][x][y] = WALL;
            }
        }
        for (int y = 2; y <= z; y += 2) {
            GRID[z][1][y] = 0;
        }
    }
    for (int t: topo) {
        int z = label[t];
        for (int x = 3; x <= N; x++) {
            for (int y = 1; y <= N; y++) {
                GRID[2 * z - 1][x][y] = WALL;
            }
        }
        int dy = 1;
        for (int v: E[t]) {
            GRID[2 * z][3][dy++] = v;
        }
        for (int vt: ee[t]) {
            GRID[2 * z][2][vt * 2] = 0;
        }
        GRID[2 * z][2][z * 2] = 0;
    }
}
int oud[101];

int main( ) {
    int d;
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++) {
            scanf("%d", &d);
            if (d) add(i, j);
        }
    for (int i = 1; i <= n; i ++)
        if (!dfn[i]) dfs(i);
    for (int i = 1; i <= n; i ++)
        for (int j = g[i]; j; j = nxt[j]) {
            if (belong[i] == belong[e[j]]) continue;
            na[belong[i]][belong[e[j]]] = true;
        }
//    for (int i = 1; i <= cnt; puts(""), i ++) {
//        printf("%d: ", i);
//        for (int j = 0; j < (int )E[i].size(); j ++)
////            printf("%d ", E[i][j]);
//    }
    for (int i = 1; i <= cnt; i ++)
        for (int j = 1; j <= cnt; j ++)
            if (na[i][j]) {
                ee[i].push_back(j);
                oud[i]++;
//                printf("%d -> %d\n", j, i);
            }
//    for (int i = 1; i <= cnt; i ++) if (oud[i] == 0) ee[cnt + 1].push_back(i);
//    N = 40;
//    dfs(cnt + 1, 1, N, 1, N);
//    out();
    for (int i = 1; i <= cnt; i++) if (!vis1[i]) {
        topoSort(i);
    }
    solve();
    out();
    return 0;
}