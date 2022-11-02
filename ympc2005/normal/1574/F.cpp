#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 10, mod = 998244353;

int n, m, K, fa[N], sz[N], pre[N], nex[N], a[N], b[N], tot;

int A[N], B[N], C[N], f[N];

bool vis[N], tag[N];

int find_(int x) {
    return fa[x] == x ? x : fa[x] = find_(fa[x]);
}

void merge_(int u, int v) {
    u = find_(u), v = find_(v);

    if (u == v) return;

    if (sz[u] < sz[v]) swap(u, v);

    fa[v] = u, sz[u] += sz[v];
}

int main() {
    scanf("%d%d%d", &n, &m, &K);

    for (int i = 1; i <= K; i++)
        fa[i] = i, sz[i] = 1;

    for (int i = 1, c; i <= n; i++) {
        scanf("%d", &c);

        for (int j = 1; j <= c; j++) {
            scanf("%d", &a[j]);

            merge_(a[j], a[1]);

            if (b[a[j]]) 
                vis[a[j]] = 1;
            else
                b[a[j]] = 1;

            if (j > 1) {
                if (pre[a[j]] && pre[a[j]] != a[j - 1]) 
                    vis[a[j]] = 1;
                else
                    pre[a[j]] = a[j - 1];
                
                if (nex[a[j - 1]] && nex[a[j - 1]] != a[j])
                    vis[a[j - 1]] = 1;
                else
                    nex[a[j - 1]] = a[j];
            }
        }

        for (int j = 1; j <= c; j++)
            b[a[j]] = 0;
    }

    for (int i = 1; i <= K; i++)
        vis[find_(i)] |= vis[i], tag[find_(i)] |= !nex[i];
    
    for (int i = 1; i <= K; i++)
        if (fa[i] == i && !vis[i] && tag[i]) {
            if (!A[sz[i]])
                A[sz[i]] = ++tot, B[tot] = sz[i];
            
            C[A[sz[i]]]++;
        }
    
    f[0] = 1;

    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= tot; j++)
            if (B[j] <= i)
                f[i] = (f[i] + 1ll*f[i - B[j]]*C[j])%mod;
    
    printf("%d\n", (f[m]%mod + mod)%mod);
}