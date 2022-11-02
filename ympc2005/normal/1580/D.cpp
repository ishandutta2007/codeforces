#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 4005;

int n, m, a[N], sz[N];

ll f[N][N], g[N];

void merge_(int u, int v) {
    for (int i = 0; i <= sz[u] + sz[v]; i++)
        g[i] = 0;
    
    for (int i = 0; i <= sz[u]; i++)
        for (int j = 0; j <= sz[v]; j++)
            g[i + j] = max(g[i + j], f[u][i] + f[v][j] - 2ll*i*j*a[u]);
    
    sz[u] += sz[v];
    
    for (int i = 0; i <= sz[u]; i++)
        f[u][i] = g[i];
}

int solve_(int l, int r) {
    if (l > r) return 0;

    int p = 0;

    for (int i = l; i <= r; i++)
        if (!p || a[p] > a[i])
            p = i;
    
    int lc = solve_(l, p - 1), rc = solve_(p + 1, r);
    f[p][1] = (m - 1ll)*a[p], sz[p] = 1;
    merge_(p, lc);
    merge_(p, rc);
    return p;
}

int main() {
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    int rt = solve_(1, n);

    printf("%lld\n", f[rt][m]);
}