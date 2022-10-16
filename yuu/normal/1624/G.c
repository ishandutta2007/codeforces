#include <stdio.h>
#include <stdbool.h>

int n, m;
struct {
    int u, v, w;
} e[200001];
int r[200001];

int root(int u) {
    if (r[u] < 0) return u;
    return r[u] = root(r[u]);
}

void unite(int u, int v) {
    u = root(u);
    v = root(v);
    if (u == v) return;
    if (r[u] > r[v]) {
        int t = u;
        u = v;
        v = t;
    }
    r[u] += r[v];
    r[v] = u;
}

bool check_prefix(int prefix, int used_bits) {
    for (int i = 1; i <= n; i++) r[i] = -1;
    for (int i = 1; i <= m; i++) {
        if (((e[i].w & used_bits) | prefix) == prefix) {
            unite(e[i].u, e[i].v);
            if (r[root(e[i].u)] == -n) return 1;
        }
    }
    return 0;
}
void solve() {
    scanf("%d %d\n", &n, &m);
    for (int i = 1; i <= m; i++) scanf("%d %d %d\n", &e[i].u, &e[i].v, &e[i].w);

    int ans = 0, used = 0;
    for (int i = 30; i >= 0; i--) {
        used ^= (1 << i);
        if (!check_prefix(ans, used)) ans ^= (1 << i);
    }
    printf("%d\n", ans);
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}