#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e5 + 10;

int n, m, son[N], len[N], val[N], tot, fa[N];

vector <int> e[N];

ll ans = -1e18;

void dfs1_(int u) {
    len[u] = 1;

    for (int v : e[u]) {
        if (v != fa[u]) {
            fa[v] = u;
            dfs1_(v);

            if (!son[u] || len[v] > len[son[u]]) {
                son[u] = v;
                len[u] = len[v] + 1; 
            }
        }
    }
}

void dfs2_(int u, int id) {
    if (u == id) {
        val[++tot] = len[u];
    }

    if (son[u]) {
        dfs2_(son[u], id);
    }

    for (int v : e[u]) {
        if (v != fa[u] && v != son[u]) {
            dfs2_(v, v);
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);

    for (int u, v, i = 1; i < n; i++) {
        scanf("%d%d", &u, &v);
        e[u].push_back(v);
        e[v].push_back(u);
    }

    dfs1_(1), dfs2_(1, 1);

    sort(val + 1, val + tot + 1);
    reverse(val + 1, val + tot + 1);

    int sum = n;

    for (int i = 1; i <= m; i++) {
        sum -= val[i];
        
        if (sum <= n/2) {
            ans = max(ans, 1ll*i*(n - i) - 1ll*(n - sum)*sum);
        } else {
            ans = max(ans, 1ll*i*(n - i) - 1ll*(n - n/2)*(n/2));
        }
    }

    printf("%lld\n", ans);
}