#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n, m, k;
struct {
    int u, v, w;
} e[1001];
struct {
    int a, b;
} r[1001];
struct {
    int deg, first, last;
} g[1001];
struct {
    int v, w;
} next[2001];
int f[1001][1001];

int queue[1001];
bool in[1001];
int queue_head, queue_tail;

void queue_clear() {
    for (int i = 1; i <= n; i++) in[i] = 0;
    queue_head = queue_tail = 0;
}
void queue_push(int u) {
    if (in[u]) return;
    in[u] = 1;
    queue[queue_tail++] = u;
    if (queue_tail > n) queue_tail = 0;
}
bool queue_empty() { return queue_head == queue_tail; }
int queue_pop() {
    int u = queue[queue_head++];
    in[u] = 0;
    if (queue_head > n) queue_head = 0;
    return u;
}
void shortest_path(int u, int* dist) {
    for (int i = 1; i <= n; i++) dist[i] = 1e9;
    dist[u] = 0;
    queue_clear();
    queue_push(u);
    while (!queue_empty()) {
        u = queue_pop();
        for (int i = g[u].first; i <= g[u].last; i++) {
            int v = next[i].v, w = next[i].w;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                queue_push(v);
            }
        }
    }
}

void solve() {
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= m; i++) {
        scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].w);
        g[e[i].u].deg++;
        g[e[i].v].deg++;
    }
    for (int i = 1; i <= k; i++) scanf("%d %d", &r[i].a, &r[i].b);
    for (int i = 1; i <= n; i++) {
        g[i].first = g[i - 1].first + g[i - 1].deg;
        g[i].last = g[i].first - 1;
    }
    for (int i = 1; i <= m; i++) {
        next[++g[e[i].u].last].v = e[i].v;
        next[g[e[i].u].last].w = e[i].w;
        next[++g[e[i].v].last].v = e[i].u;
        next[g[e[i].v].last].w = e[i].w;
    }
    for (int i = 1; i <= n; i++) shortest_path(i, f[i]);

    int ans = 1e9;
    for (int i = 1; i <= m; i++) {
        int cost = 0;
        for (int j = 1; j <= k; j++) {
            int route_cost = f[r[j].a][r[j].b];
            if (route_cost > f[r[j].a][e[i].u] + f[e[i].v][r[j].b]) {
                route_cost = f[r[j].a][e[i].u] + f[e[i].v][r[j].b];
            }
            if (route_cost > f[r[j].a][e[i].v] + f[e[i].u][r[j].b]) {
                route_cost = f[r[j].a][e[i].v] + f[e[i].u][r[j].b];
            }
            cost += route_cost;
            if (cost >= ans) break;
        }
        if (ans > cost) ans = cost;
    }
    printf("%d\n", ans);
}
int main() {
    int t = 1;
    // scanf("%d", &t);
    while (t--) solve();
}