#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10, mod = 1e9 + 7;

int n, T, a[N], b[N], m, id[N], t[N], f[N], g[N], h[N];

vector <int> p[N];

bool cmp_(int u, int v) {
    return a[u] == a[v] ? u < v : a[u] > a[v];
}

void upd_(int x, int k) {
    for (; x <= m; x += x&-x) {
        t[x] = (t[x] + k)%mod;
    }
}

int ask_(int x, int res = 0) {
    for (; x; x -= x&-x) {
        res = (res + t[x])%mod;
    }

    return res;
}

void solve_(int k) {
    sort(p[k].begin(), p[k].end());
    reverse(p[k].begin(), p[k].end());

    for (int x : p[k]) {
        h[x] = (g[x] - g[k])%mod;
        h[x] = (1ll*h[x] + ask_(m) - ask_(a[x]))%mod;
        upd_(a[x], (h[x] - g[x])%mod);
    }

    for (int x : p[k]) {
        upd_(a[x], (g[x] - h[x])%mod);
    }
}

int main() {
    scanf("%d", &T);

    while (T--) {
        scanf("%d", &n);

        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            b[i] = a[i], h[i] = 0;
            p[i].clear();
        }

        sort(b + 1, b + n + 1);
        m = unique(b + 1, b + n + 1) - b - 1;

        for (int i = 1; i <= n; i++) {
            a[i] = lower_bound(b + 1, b + m + 1, a[i]) - b;
        }

        for (int i = 1; i <= n; i++) {
            id[i] = i;
        }

        sort(id + 1, id + n + 1, cmp_);

        int mx = 0;

        for (int i = 1; i <= n; i++) {
            if (mx > id[i]) {
                p[mx].push_back(id[i]);
            }

            mx = max(mx, id[i]);
        }

        for (int i = 1; i <= m; i++) {
            t[i] = 0;
        }

        for (int i = 1; i <= n; i++) {
            f[i] = (1 + ask_(a[i] - 1))%mod;
            upd_(a[i], f[i]);
        }

        for (int i = 1; i <= m; i++) {
            t[i] = 0;
        }

        for (int i = n; i; i--) {
            g[i] = (1ll + ask_(m) - ask_(a[i]))%mod;
            upd_(a[i], g[i]);
        }

        for (int i = 1; i <= m; i++) {
            t[i] = 0;
        }

        for (int i = 1; i <= n; i++) {
            if (p[i].size()) {
                solve_(i);
            }
        }

        int ans = 0;

        for (int i = 1; i <= n; i++) {
            ans = (ans + 1ll*f[i]*h[i])%mod;
        }

        printf("%d\n", (ans%mod + mod)%mod);
    }
}