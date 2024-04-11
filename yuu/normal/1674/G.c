#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
int n, m;
int next[200001];
struct {
    int deg, head, tail;
    int out;
} g[200001];
struct {
    int u, v;
} e[200001];

int f[200001];
bool done[200001];
int F(int u) {
    if (done[u]) return f[u];
    done[u] = 1;
    f[u] = 0;
    if (g[u].head != g[u].tail)
        for (int i = g[u].head; i <= g[u].tail; i++) {
            int v = next[i];
            if (g[v].out == 1) continue;
            if (f[u] < F(v)) f[u] = F(v);
        }
    f[u]++;
    return f[u];
}

void solve() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &e[i].u, &e[i].v);
        g[e[i].u].deg++;
        g[e[i].v].out++;
    }
    for (int i = 1; i <= n; i++) {
        g[i].head = g[i - 1].head + g[i - 1].deg;
        g[i].tail = g[i].head - 1;
    }
    for (int i = 1; i <= m; i++) next[++g[e[i].u].tail] = e[i].v;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (ans < F(i)) ans = F(i);
    }
    printf("%d\n", ans);
}

int main() {
    int t = 1;
    // scanf("%d", &t);
    while (t--) solve();
}