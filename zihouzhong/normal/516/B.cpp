#include <bits/stdc++.h>
using namespace std;

const int maxn = 2010;
const int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
int n, m, lnk[maxn][maxn];
char s[maxn][maxn];
bool vis[maxn][maxn], inq[maxn][maxn];
queue<pair<int, int>> Q;

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%s", s[i] + 1);
        for (int j = 1; j <= m; j++) {
            if (s[i][j] == '*') vis[i][j] = 1;
        }
    }
    auto upd = [&](int i, int j) {
        if (i < 1 || i > n || j < 1 || j > m || inq[i][j]) return;
        int d = 0;
        for (int k = 0; k < 4; k++) {
            int x = i + dx[k], y = j + dy[k];
            if (!x || x > n || !y || y > m || vis[x][y]) continue;
            lnk[i][j] = k, d++;
        }
        if (d == 1) Q.emplace(i, j), inq[i][j] = 1;
    };
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!vis[i][j]) upd(i, j);
        }
    }
    while (!Q.empty()) {
        int x = Q.front().first, y = Q.front().second; Q.pop();
        if (vis[x][y]) continue;
        int d = 0;
        for (int k = 0; k < 4; k++) {
            int i = x + dx[k], j = y + dy[k];
            if (i && i <= n && j && j <= m && !vis[i][j]) lnk[x][y] = k, d++;
        }
        if (d ^ 1) puts("Not unique"), exit(0);
        int _x = x + dx[lnk[x][y]], _y = y + dy[lnk[x][y]];
        vis[x][y] = vis[_x][_y] = 1;
        s[x][y] = "v^><"[lnk[x][y]], s[_x][_y] = "^v<>"[lnk[x][y]];
        for (int k = 0; k < 4; k++) {
            upd(x + dx[k], y + dy[k]);
            upd(_x + dx[k], _y + dy[k]);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!vis[i][j]) puts("Not unique"), exit(0);
        }
    }
    for (int i = 1; i <= n; i++) {
        printf("%s\n", s[i] + 1);
    }
    return 0;
}