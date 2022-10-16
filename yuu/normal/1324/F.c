#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct edge_t {
    struct edge_t* prev;
    int v;
} e[400001];
struct edge_t* g[200001];
int n;
int a[200001];
int edge_count;
void add_edge(int u, int v) {
    struct edge_t* new_edge = &e[edge_count++];
    new_edge->prev = g[u];
    new_edge->v = v;
    g[u] = new_edge;
}
bool done[200001];
int f[200001];
int ans[200001];
int max(int u, int v) { return (u > v) ? u : v; }
void attach_child(int u, int v) { f[u] += max(f[v], 0); }
void remove_child(int u, int v) { f[u] -= max(f[v], 0); }
int order[400001];
int sz = 0;
void dfs(int u) {
    done[u] = 1;
    struct edge_t* edge = g[u];
    if (a[u]) f[u] = 1;
    else f[u] = -1;
    while (edge != NULL) {
        int v = edge->v;
        if (!done[v]) {
            order[sz++] = v;
            dfs(v);
            order[sz++] = u;
            attach_child(u, v);
        }
        edge = edge->prev;
    }
}
void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1, u, v; i < n; i++) {
        scanf("%d %d", &u, &v);
        add_edge(u, v);
        add_edge(v, u);
    }
    dfs(1);
    ans[1] = f[1];
    int root = 1;
    for (int i = 0; i < sz; i++) {
        int u = order[i];
        remove_child(root, u);
        attach_child(u, root);
        root = u;
        ans[u] = f[u];
    }
    for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
    printf("\n");
}

int main() {
    int t = 1;
    // scanf("%d", &t);
    while (t--) solve();
}