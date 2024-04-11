#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e5 + 10, mod = 998244353;

int n, q, d[N], f[N][20], fa[N], st[N], ed[N], inv[N], tim, sz[N];

int op[N][3], ans[N], cf[N], a[N];

vector <int> e[N];

int fpow_(int a, int b, int res = 1) {
    for (; b; b >>= 1, a = 1ll*a*a%mod) {
        if (b&1) {
            res = 1ll*res*a%mod;
        }
    }

    return res;
}

void dfs_(int u) {
    d[u] = d[fa[u]] + 1;
    f[u][0] = fa[u];
    st[u] = ++tim;

    for (int k = 1; k < 20; k++) {
        f[u][k] = f[f[u][k - 1]][k - 1];
    }

    for (int v : e[u]) {
        if (v != fa[u]) {
            fa[v] = u;
            dfs_(v);
        }
    }

    ed[u] = tim;
    sz[u] = ed[u] - st[u] + 1;
}

int find_(int x, int k) {
    for (int i = 0; i < 20; i++) {
        if (k&(1<<i)) {
            x = f[x][i];
        }
    }

    return x;
}

int calc_(int u, int k, int v) {
    if (u == v) {
        return k;
    }

    if (st[u] <= st[v] && ed[v] <= ed[u]) {
        v = find_(v, d[v] - d[u] - 1);
        return 1ll*k*inv[n - sz[v]]%mod;
    } else {
        return 1ll*k*inv[sz[u]]%mod;
    }
}

void upd_(int l, int r, int v) {
    cf[l] = (cf[l] + v)%mod;
    cf[r + 1] = (cf[r + 1] - v)%mod;
}

int main() {
    ios :: sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>q;

    for (int u, v, i = 1; i < n; i++) {
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        inv[i] = 1ll*i*fpow_(n, mod - 2)%mod;
    }

    dfs_(1);

    for (int i = 1; i <= q; i++) {
        cin>>op[i][0]>>op[i][1];

        if (op[i][0] == 1) {
            cin>>op[i][2];
        }
    }

    for (int l = 1, r; l <= q; l = r + 1) {
        r = min(l + 300, q);

        for (int i = 1; i <= n; i++) {
            a[i] = cf[i] = 0;
        }

        for (int i = l; i <= r; i++) {
            if (op[i][0] == 2) {
                int u = op[i][1], res = ans[st[u]];

                for (int j = l; j < i; j++) {
                    if (op[j][0] == 1) {
                        res = (res + calc_(op[j][1], op[j][2], u))%mod;
                    }
                }

                cout<<(res%mod + mod)%mod<<'\n';
            } else {
                a[op[i][1]] = (a[op[i][1]] + op[i][2])%mod;
            }
        }

        for (int u = 1; u <= n; u++) {
            if (a[u]) {
                upd_(st[u], st[u], a[u]);

                for (int v : e[u]) {
                    if (v != fa[u]) {
                        upd_(st[v], ed[v], 1ll*a[u]*inv[n - sz[v]]%mod);
                    }
                }

                if (st[u] > 1) {
                    upd_(1, st[u] - 1, 1ll*a[u]*inv[sz[u]]%mod);
                }

                if (ed[u] < n) {
                    upd_(ed[u] + 1, n, 1ll*a[u]*inv[sz[u]]%mod);
                }
            }
        }

        for (int i = 1; i <= n; i++) {
            cf[i] = (cf[i] + cf[i - 1])%mod;
            ans[i] = (ans[i] + cf[i])%mod;
        }
    }   
}