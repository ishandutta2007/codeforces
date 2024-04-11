#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n;
struct {
    int u, v;
} e[200001];
struct {
    int deg, head, tail;
} g[200001];
int next[400001];
bool done[200001];
bool in_cycle[200001];
int cycle_start;
bool dfs(int u, int p) {
    done[u] = 1;
    for (int i = g[u].head; i <= g[u].tail; i++) {
        int v = next[i];
        if (!done[v]) {
            if (dfs(v, u)) return true;
        } else {
            if (v == p) continue;
            cycle_start = v;
        }
        if (cycle_start) {
            in_cycle[u] = 1;
            if (u == cycle_start) return true;
            else return false;
        }
    }
    return false;
}
int cnt[200001];
int dfs2(int u) {
    done[u] = 1;
    int res = 1;
    for (int i = g[u].head; i <= g[u].tail; i++) {
        int v = next[i];
        if (in_cycle[v]) continue;
        if (!done[v]) res += dfs2(v);
    }
    return res;
}
void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) g[i].deg = 0;
    for (int i = 1, u, v; i <= n; i++) {
        scanf("%d %d", &e[i].u, &e[i].v);
        g[e[i].u].deg++;
        g[e[i].v].deg++;
    }
    for (int i = 1; i <= n; i++) {
        g[i].head = g[i - 1].head + g[i - 1].deg;
        g[i].tail = g[i].head - 1;
    }
    for (int i = 1; i <= n; i++) {
        next[++g[e[i].u].tail] = e[i].v;
        next[++g[e[i].v].tail] = e[i].u;
    }
    for (int i = 1; i <= n; i++) done[i] = 0;
    for (int i = 1; i <= n; i++) in_cycle[i] = 0;
    cycle_start = 0;
    dfs(1, 0);
    for (int i = 1; i <= n; i++) done[i] = 0;
    int64_t ans = 0;
    for (int i = 1; i <= n; i++)
        if (in_cycle[i]) {
            int64_t cnt = dfs2(i);
            ans += cnt * (n - cnt) * 2;
            ans += cnt * (cnt - 1);
        }
    ans /= 2;
    printf("%lld\n", ans);
}
int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}