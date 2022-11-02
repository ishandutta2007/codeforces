#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10, mod = 998244353;

int n, m, a[N], b[N], l[N], r[N], ans, f[2][N], p[N], tot, mu[N];

bool vis[N];

int calc_(int k) {
    int mx = m/k;

    for (int i = 1; i <= n; i++) {
        l[i] = (a[i] + k - 1)/k, r[i] = b[i]/k;

        if (l[i] > r[i])
            return 0;
    }

    int u = 0, v = 1;

    for (int i = 0; i <= mx; i++)
        f[u][i] = 1;

    for (int i = 1; i <= n; i++) {
        u ^= 1, v ^= 1;

        for (int j = 0; j <= mx; j++) {
            f[u][j] = 0;

            if (j < l[i]) continue;

            f[u][j] = f[v][j - l[i]];

            if (j > r[i])
                f[u][j] = (f[u][j] - f[v][j - r[i] - 1])%mod;
        }

        for (int j = 1; j <= mx; j++)
            f[u][j] = (f[u][j] + f[u][j - 1])%mod;
    }

    return f[u][mx];
}

int main() {
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++)
        scanf("%d%d", &a[i], &b[i]);

    mu[1] = 1;

    for (int i = 2; i <= m; i++) {
        if (!vis[i])
            p[++tot] = i, mu[i] = -1;
        
        for (int j = 1; j <= tot && i*p[j] <= m; j++) {
            vis[i*p[j]] = 1;

            if (i%p[j] == 0) continue;

            mu[i*p[j]] = -mu[i];
        }
    }

    for (int i = 1; i <= m; i++)
        if (mu[i])
            ans = (ans + calc_(i)*mu[i])%mod;

    printf("%d\n", (ans%mod + mod)%mod);
}