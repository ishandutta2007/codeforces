#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 5e5 + 10;

int n, m, h[N], cnt, tot;

ll f[N], g[N], a[N];

struct Edge {
    int to, next, w;
} e[N<<1];

void add_(int u, int v, int w) {
    e[++cnt] = (Edge) {v, h[u], w};
    h[u] = cnt;
}

void dfs_(int u, int fa) {
    for (int v, i = h[u]; i; i = e[i].next) {
        v = e[i].to;

        if (v != fa) {
            dfs_(v, u);
        }
    }

    tot = 0;
    f[u] = g[u] = 0;
    ll sum = 0;

    for (int v, i = h[u]; i; i = e[i].next) {
        v = e[i].to;

        if (v != fa) {
            sum += g[v];
            a[++tot] = max(0ll, f[v] - g[v] + e[i].w);
        }
    }

    sort(a + 1, a + tot + 1);
    reverse(a + 1, a + tot + 1);
    f[u] = g[u] = sum;

    for (int i = 1; i <= tot; i++) {
        if (i < m) {
            f[u] += a[i];
        }

        if (i <= m) {
            g[u] += a[i];
        }
    }
}

void work_() {
    cin>>n>>m;

    for (int i = 1; i <= n; i++) {
        h[i] = 0;
    }

    cnt = 0;

    for (int u, v, w, i = 1; i < n; i++) {
        cin>>u>>v>>w;
        add_(u, v, w);
        add_(v, u, w);
    }

    dfs_(1, 0);
    cout<<g[1]<<'\n';
}

int main() {
    ios :: sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin>>T;

    while (T--) {
        work_();
    }
}