#include <bits/stdc++.h>
using namespace std;

typedef vector <int> vi;

const int N = 1005, inf = 1e9;

int n, m, a[N], b[N], fl[N], tim, rk[N];

vi c[N];

namespace NF {
    int n, h[N], cur[N], d[N], cnt, vis[N];

    struct Edge {
        int to, next, w;
    } e[N<<3];

    void init_(int _n) {
        n = _n;

        for (int i = 0; i <= n + 1; i++) {
            h[i] = vis[i] = 0;
        }

        cnt = 1;
    }

    void add_(int u, int v, int w) {
        e[++cnt] = (Edge) {v, h[u], w};
        h[u] = cnt;

        if (!(cnt&1)) {
            add_(v, u, 0);
        }
    }

    bool bfs_() {
        for (int i = 0; i <= n + 1; i++) {
            d[i] = 0;
            cur[i] = h[i];
        }

        queue <int> q;
        q.push(0), d[0] = 1;

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

        return d[n + 1];
    }

    int dfs_(int u, int lim) {
        if (u == n + 1 || !lim) {
            return lim;
        }

        int flow = 0, f;

        for (int v, &i = cur[u]; i; i = e[i].next) {
            v = e[i].to;

            if (d[v] == d[u] + 1 && (f = dfs_(v, min(e[i].w, lim)))) {
                lim -= f, flow += f;
                e[i].w -= f, e[i^1].w += f;

                if (!lim) {
                    break;
                }
            }
        }

        return flow;
    }

    void work_() {
        while (bfs_()) {
            dfs_(0, inf);
        }

        queue <int> q;
        q.push(0);

        while (!q.empty()) {
            int u = q.front(); q.pop();

            for (int v, i = h[u]; i; i = e[i].next) {
                v = e[i].to;

                if (e[i].w && !vis[v]) {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
    }
}

void solve_(vi id, int l, int r) {
    if (!id.size()) {
        return;
    }

    if (l == r) {
        for (int x : id) {
            b[x] = l;
        }

        return;
    }

    int mid = (l + r)>>1, cnt = 0;

    ++tim;

    for (int x : id) {
        fl[x] = tim;
        rk[x] = ++cnt;
    }

    NF :: init_(cnt);

    for (int x : id) {
        if (a[x] <= mid) {
            NF :: add_(0, rk[x], 1);
        } else {
            NF :: add_(rk[x], cnt + 1, 1);
        }

        for (int y : c[x]) {
            if (fl[y] == tim) {
                NF :: add_(rk[y], rk[x], inf);
            }
        }
    }

    NF :: work_();

    vi L, R;

    for (int x : id) {
        if (a[x] <= mid) {
            if (!NF :: vis[rk[x]]) {
                R.push_back(x);
            } else {
                L.push_back(x);
            }
        } else {
            if (NF :: vis[rk[x]]) {
                L.push_back(x); 
            } else {
                R.push_back(x);
            }
        }
    }

    solve_(L, l, mid);
    solve_(R, mid + 1, r);
}

int main() {
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    for (int u, v, i = 1; i <= m; i++) {
        scanf("%d%d", &u, &v);
        c[u].push_back(v);
    }

    vi tmp;

    for (int i = 1; i <= n; i++) {
        tmp.push_back(i);
    }

    solve_(tmp, 1, 1e9);

    for (int i = 1; i <= n; i++) {
        printf("%d ", b[i]);
    }
}