#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n, m;
struct edge_t {
    int u, v;
} e[5001];
struct member_t {
    struct member_t* prev;
    int id;
};
struct member_t* g[5001];
void add_edge(int u, int i) {
    struct member_t* new_edge = malloc(sizeof(struct member_t));
    new_edge->prev = g[u];
    new_edge->id = i;
    g[u] = new_edge;
}
bool done[5001];
int h[5001];
int p[5001];
int f[5001];
struct query_t {
    int a, b, g;
} q[5001];
void dfs(int u) {
    done[u] = 1;
    // printf("%d %d\n", u, h[u]);
    struct member_t* edge = g[u];
    while (edge != NULL) {
        int id = edge->id;
        int v = e[id].u ^ e[id].v ^ u;
        if (!done[v]) {
            h[v] = h[u] + 1;
            p[v] = id;
            dfs(v);
        }
        edge = edge->prev;
    }
}
 
int max(int a, int b) { return (a > b) ? a : b; }
 
void apply_query(int id) {
    int u = q[id].a;
    int v = q[id].b;
    int g = q[id].g;
    if (h[u] < h[v]) {
        u ^= v;
        v ^= u;
        u ^= v;
    }
    while (h[u] > h[v]) {
        f[p[u]] = max(f[p[u]], g);
        u = e[p[u]].u ^ e[p[u]].v ^ u;
    }
    while (u != v) {
        f[p[u]] = max(f[p[u]], g);
        u = e[p[u]].u ^ e[p[u]].v ^ u;
        f[p[v]] = max(f[p[v]], g);
        v = e[p[v]].u ^ e[p[v]].v ^ v;
    }
}
 
bool check_query(int id) {
    int u = q[id].a;
    int v = q[id].b;
    int g = q[id].g;
    if (h[u] < h[v]) {
        u ^= v;
        v ^= u;
        u ^= v;
    }
    bool found = 0;
    while (h[u] > h[v]) {
        if (f[p[u]] == g) return true;
        u = e[p[u]].u ^ e[p[u]].v ^ u;
    }
    while (u != v) {
        if (f[p[u]] == g) return true;
        u = e[p[u]].u ^ e[p[u]].v ^ u;
        if (f[p[v]] == g) return true;
        v = e[p[v]].u ^ e[p[v]].v ^ v;
    }
    return false;
}
 
void solve() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        scanf("%d %d", &e[i].u, &e[i].v);
        add_edge(e[i].u, i);
        add_edge(e[i].v, i);
        f[i] = 1;
    }
    dfs(1);
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) scanf("%d %d %d", &q[i].a, &q[i].b, &q[i].g);
    for (int i = 1; i <= m; i++) apply_query(i);
    for (int i = 1; i <= m; i++)
        if (!check_query(i)) {
            puts("-1");
            return;
        }
    for (int i = 1; i < n; i++) {
        printf("%d ", f[i]);
    }
}
 
int main() {
    int t = 1;
    // scanf("%d", &t);
    while (t--) solve();
}