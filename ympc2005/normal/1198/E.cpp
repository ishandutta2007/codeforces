#include <bits/stdc++.h>
using namespace std;

const int N = 205, inf = 1e9;

int n, m, h[N], cnt = 1, nx, ny, S, T, bx[N], by[N], ans;

bool vis[N][N];

struct Rec {
    int xl, xr, yl, yr;
} a[N];

struct Edge {
    int to, next, w;
} e[N*N<<2];

void add_(int u, int v, int w) {
    e[++cnt] = (Edge) {v, h[u], w};
    h[u] = cnt;

    if (!(cnt&1)) {
        add_(v, u, 0);
    }
}

int d[N], cur[N];

bool bfs_() {
    queue <int> q;

    for (int i = S; i <= T; i++) {
        d[i] = 0;
        cur[i] = h[i];
    }

    d[S] = 1, q.push(S);

    while (!q.empty()) {
        int u = q.front(); q.pop();

        for (int v, i = h[u]; i; i = e[i].next) {
            v = e[i].to;

            if (!d[v] && e[i].w) {
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }

    return d[T];
}

int dfs_(int u, int lim) {
    if (u == T || !lim) {
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
    ios :: sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>m;

    for (int i = 1; i <= m; i++) {
        cin>>a[i].xl>>a[i].yl>>a[i].xr>>a[i].yr;
        bx[++nx] = a[i].xl;
        bx[++nx] = ++a[i].xr;
        by[++ny] = a[i].yl;
        by[++ny] = ++a[i].yr;
    }

    sort(bx + 1, bx + nx + 1);
    nx = unique(bx + 1, bx + nx + 1) - bx - 1;
    sort(by + 1, by + ny + 1);
    ny = unique(by + 1, by + ny + 1) - by - 1;
    S = 0, T = nx + ny + 1;

    for (int i = 1; i <= m; i++) {
        int xl = lower_bound(bx + 1, bx + nx + 1, a[i].xl) - bx;
        int xr = lower_bound(bx + 1, bx + nx + 1, a[i].xr) - bx;
        int yl = lower_bound(by + 1, by + ny + 1, a[i].yl) - by;
        int yr = lower_bound(by + 1, by + ny + 1, a[i].yr) - by;

        for (int j = xl; j < xr; j++) {
            for (int k = yl; k < yr; k++) {
                if (!vis[j][k]) {
                    vis[j][k] = 1;
                    add_(j, k + nx, inf);
                }
            }
        }
    }   

    for (int i = 1; i < nx; i++) {
        add_(S, i, bx[i + 1] - bx[i]);
    }

    for (int i = 1; i < ny; i++) {
        add_(i + nx, T, by[i + 1] - by[i]);
    }

    while (bfs_()) {
        ans += dfs_(S, inf);
    }

    cout<<ans<<'\n';
}