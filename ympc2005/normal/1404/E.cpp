#include <bits/stdc++.h>
using namespace std;

const int N = 205, M = N*N<<1;

int n, m, id[N][N][2], tot, S, T, h[M], cnt = 1, ans, d[M], cur[M];

char s[N][N];

struct Edge {
    int to, next, w;
} e[M<<3];

void add_(int u, int v, int w) {
    e[++cnt] = (Edge) {v, h[u], w};
    h[u] = cnt;

    if (!(cnt&1)) {
        add_(v, u, 0);
    }
}

bool bfs_() {
    for (int i = 1; i <= tot; i++) {
        d[i] = 0;
        cur[i] = h[i];
    }

    queue <int> q;
    q.push(S), d[S] = 1;

    while (!q.empty()) {
        int u = q.front(); q.pop();

        for (int v, i = h[u]; i; i = e[i].next) {
            v = e[i].to;

            if (e[i].w && !d[v]) {
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }

    return d[T];
}

int dfs_(int u, int lim) {
    if (!lim || u == T) {
        return lim;
    }

    int flow = 0, f;

    for (int v, &i = cur[u]; i; i = e[i].next) {
        v = e[i].to;

        if (d[v] == d[u] + 1 && (f = dfs_(v, min(lim, e[i].w)))) {
            flow += f, lim -= f;
            e[i].w -= f, e[i^1].w += f;

            if (!lim) {
                break;
            }
        }
    }

    return flow;
}

int main() {
    scanf("%d%d", &n, &m);

    S = ++tot, T = ++tot;

    for (int i = 1; i <= n; i++) {
        scanf("%s", s[i] + 1);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < m; j++) {
            if (s[i][j] == '#' && s[i][j + 1] == '#') {
                id[i][j][0] = ++tot;
                add_(S, tot, 1);
            }
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i][j] == '#' && s[i + 1][j] == '#') {
                id[i][j][1] = ++tot;
                add_(tot, T, 1);

                if (id[i][j][0]) {
                    add_(id[i][j][0], tot, 1e9);
                }

                if (id[i][j - 1][0]) {
                    add_(id[i][j - 1][0], tot, 1e9);
                }

                if (id[i + 1][j][0]) {
                    add_(id[i + 1][j][0], tot, 1e9);
                }

                if (id[i + 1][j - 1][0]) {
                    add_(id[i + 1][j - 1][0], tot, 1e9);
                }
            }
        }
    }

    ans = tot - 2;

    while (bfs_()) {
        ans -= dfs_(S, 1e9);
    }

    ans = -ans;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i][j] == '#') {
                ans++;
            }
        }
    }

    printf("%d\n", ans);
}