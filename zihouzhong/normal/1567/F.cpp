#include <bits/stdc++.h>
using namespace std;

const int maxn = 510;
const int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
int n, m, col[maxn * maxn], ans[maxn][maxn];
char s[maxn][maxn];
vector<int> G[maxn * maxn];

int id(int x, int y) {
    return (x - 1) * m + y;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%s", s[i] + 1);
    }
    auto op = [&](int x, int y) {
        G[x].push_back(y), G[y].push_back(x);
    };
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) if (s[i][j] == 'X') {
            int cnt = 0;
            vector<int> V;
            for (int k = 0; k < 4; k++) {
                int x = i + dx[k], y = j + dy[k];
                if (x && x <= n && y && y <= m && s[x][y] == '.') cnt++, V.push_back(id(x, y));
            }
            if (cnt & 1) puts("NO"), exit(0);
            if (cnt == 2) op(V[0], V[1]);
            if (cnt == 4) op(V[0], V[2]), op(V[2], V[1]), op(V[0], V[3]);
        }
    }
    function<void(int)> dfs = [&](int v) {
        for (int u : G[v]) {
            if (!col[u]) {
                col[u] = 5 - col[v], dfs(u);
            } else if (col[u] != 5 - col[v]) {
                puts("NO"), exit(0);
            }
        }
    };
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) if (s[i][j] == '.') {
            if (!col[id(i, j)]) col[id(i, j)] = 1, dfs(id(i, j));
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i][j] == '.') ans[i][j] = col[id(i, j)];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) if (s[i][j] == 'X') {
            for (int k = 0; k < 4; k++) {
                int x = i + dx[k], y = j + dy[k];
                if (x && x <= n && y && y <= m && s[x][y] == '.') ans[i][j] += ans[x][y];
            }
            assert(!(ans[i][j] % 5));
        }
    }
    puts("YES");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            printf("%d%c", ans[i][j], " \n"[j == m]);
        }
    }
    return 0;
}