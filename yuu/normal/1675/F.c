#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
int n, k, x, y;
bool need[400001];
int next[400001];
int p[400001];
bool done[200001];
struct {
    int deg, first, last;
} g[200001];
struct {
    int u, v;
} e[200001];

void dfs(int u) {
    done[u] = 1;
    for (int i = g[u].first; i <= g[u].last; i++) {
        int v = next[i];
        if (done[v]) continue;
        p[v] = u;
        dfs(v);
        need[u] = need[u] || need[v];
    }
}

void solve() {
    scanf("%d %d", &n, &k);
    scanf("%d %d", &x, &y);

    for (int i = 1; i <= n; i++) need[i] = 0;
    for (int i = 1, a; i <= k; i++) {
        scanf("%d", &a);
        need[a] = 1;
    }
    for (int i = 1; i < n; i++) {
        scanf("%d %d", &e[i].u, &e[i].v);
        g[e[i].u].deg++;
        g[e[i].v].deg++;
    }
    for (int i = 1; i <= n; i++) {
        g[i].first = g[i - 1].first + g[i - 1].deg;
        g[i].last = g[i].first - 1;
    }
    for (int i = 1; i < n; i++) {
        next[++g[e[i].u].last] = e[i].v;
        next[++g[e[i].v].last] = e[i].u;
    }
    for (int i = 1; i <= n; i++) done[i] = 0;
    p[x] = 0;
    dfs(x);
    int ans = 0;
    while (y != x) {
        need[y] = 0;
        ans++;
        y = p[y];
    }
    need[x] = 0;
    for (int i = 1; i <= n; i++) ans += (2 * need[i]);
    printf("%d\n", ans);
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}