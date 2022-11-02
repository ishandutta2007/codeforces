#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10, mod = 998244353;

int x[N], y[N], s[N], n, a[N], b[N], m, c[N], f[N], g[N];

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d%d%d", &x[i], &y[i], &s[i]);
        a[++m] = x[i], a[++m] = y[i];
    }

    sort(a + 1, a + m + 1);

    for (int i = 1; i <= n; i++) {
        x[i] = lower_bound(a + 1, a + m + 1, x[i]) - a;
        y[i] = lower_bound(a + 1, a + m + 1, y[i]) - a;
        b[x[i]] = y[i], c[x[i]] = s[i];
    }

    g[1] = 0;

    for (int i = 2; i <= m; i++) {
        if (!b[i - 1]) g[i] = (1ll*g[i - 1] + a[i] - a[i - 1])%mod;
        else g[i] = (2ll*g[i - 1] - g[b[i - 1]] + a[i] - a[i - 1])%mod;

        //cout<<g[i]<<'\n';
    }

    f[m + 1] = 0, a[m + 1] = a[m] + 1;

    for (int i = m; i >= 0; i--) {
        if (!c[i]) 
            f[i] = (1ll*f[i + 1] + a[i + 1] - a[i])%mod;
        else
            f[i] = (1ll*f[i + 1] + g[i] - g[b[i]] + a[i + 1] - a[i])%mod;
    }

    printf("%d\n", (f[0]%mod + mod)%mod);
}