#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

int n, m;
struct {
    int u, v;
} e[200001];
int next[200001];
struct {
    int deg, head, tail;
} g[200001];

int d[200001];
int queue[200001];
int queue_head, queue_tail;

void queue_push(int x) { queue[++queue_tail] = x; }
int queue_pop() { return queue[queue_head++]; }
void queue_clear() {
    queue_head = 0;
    queue_tail = -1;
}
bool queue_empty() { return queue_head > queue_tail; }

void bfs() {
    queue_clear();
    for (int i = 1; i <= n; i++) d[i] = 1e9;
    d[1] = 0;
    queue_push(1);
    while (!queue_empty()) {
        int u = queue_pop();
        for (int i = g[u].head; i <= g[u].tail; i++) {
            int v = next[i];
            if (d[v] > d[u] + 1) {
                d[v] = d[u] + 1;
                queue_push(v);
            }
        }
    }
}

bool done[200001];
int f[200001];
int F(int u) {
    if (done[u]) return f[u];
    done[u] = 1;
    f[u] = d[u];
    for (int i = g[u].head; i <= g[u].tail; i++) {
        int v = next[i];
        if (d[v] > d[u]) {
            if (f[u] > F(v)) f[u] = F(v);
        } else {
            if (f[u] > d[v]) f[u] = d[v];
        }
    }
    return f[u];
}

void solve() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) g[i].deg = 0;
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &e[i].u, &e[i].v);
        g[e[i].u].deg++;
    }
    for (int i = 1; i <= n; i++) {
        g[i].head = g[i - 1].head + g[i - 1].deg;
        g[i].tail = g[i].head - 1;
    }
    for (int i = 1; i <= m; i++) {
        next[++g[e[i].u].tail] = e[i].v;
    }
    bfs();
    for (int i = 1; i <= n; i++) done[i] = 0;
    for (int i = 1; i <= n; i++) printf("%d ", F(i));
    printf("\n");
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}