#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e5 + 10, mod = 1e9 + 7;

int n, h[N], cnt = 1, sz[N];

ll ans1, ans2;

struct Edge {
    int to, next, w;
} e[N<<1];

void add_(int u, int v, int w) {
    e[++cnt] = (Edge) {v, h[u], w};
    h[u] = cnt;
}

void dfs_(int u, int fa) {
    sz[u] = 1;

    for (int v, i = h[u]; i; i = e[i].next) {
        v = e[i].to;

        if (v != fa) {
            dfs_(v, u);
            sz[u] += sz[v];
            ans1 += (sz[v]&1)*e[i].w;
            ans2 += 1ll*min(sz[v], n - sz[v])*e[i].w;
        }
    }
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        scanf("%d", &n);
        n *= 2;

        for (int i = 1; i <= n; i++) {
            h[i] = 0;
        }

        cnt = 1, ans1 = ans2 = 0;

        for (int u, v, w, i = 1; i < n; i++) {
            scanf("%d%d%d", &u, &v, &w);
            add_(u, v, w);
            add_(v, u, w);
        }

        dfs_(1, 0);
        printf("%lld %lld\n", ans1, ans2);
    }
}