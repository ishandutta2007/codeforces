#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int N = 2e5 + 10;

int n, rt, a[N], f[N];

vector <int> e[N];

ll ans;

void dfs_(int u, int fa) {
    if (e[u].size() == 1) {
        f[u] = a[u];
        ans += a[u];
        return;
    }

    int mx = 0, sx = 0;

    for (int v : e[u]) {
        if (v != fa) {
            dfs_(v, u);
            
            if (sx < f[v]) {
                sx = f[v];
            }

            if (mx < sx) {
                swap(mx, sx);
            }
        }
    }

    if (u != rt) {
        if (a[u] > mx) {
            ans += a[u] - mx;
            f[u] = a[u];
        } else {
            f[u] = mx;
        }
    } else {
        ans += max(0, a[u] - mx);
        ans += max(0, a[u] - sx);
    }
}

void dfs1_(int u, int fa) {
    if (u != rt && e[u].size() == 1) {
        ans += a[u];
        f[u] = a[u];
        return;
    }

    int mx = 0;

    for (int v : e[u]) {
        if (v != fa) {
            dfs1_(v, u);
            mx = max(mx, f[v]);
        }
    }

    if (u == rt) {
        ans += 2ll*a[u] - mx;
        return;
    }

    if (mx < a[u]) {
        ans += a[u] - mx;
        f[u] = a[u];
    } else {
        f[u] = mx;
    }
}

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    for (int u, v, i = 1; i < n; i++) {
        scanf("%d%d", &u, &v);
        e[u].push_back(v);
        e[v].push_back(u);
    }

    if (n == 2) {
        printf("%lld\n", 2ll*max(a[1], a[2]));
        exit(0);
    }

    for (int i = 1; i <= n; i++) {
        if (a[rt] < a[i]) {
            rt = i;
        }
    }

    if (e[rt].size() == 1) {
        dfs1_(rt, 0);
    } else {
        dfs_(rt, 0);
    }

    printf("%lld\n", ans);
}