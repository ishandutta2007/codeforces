#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct member_t {
    struct member_t* prev;
    int v;
};
struct member_t* g[200001];
void add_edge(int u, int v) {
    struct member_t* new_edge = malloc(sizeof(struct member_t));
    new_edge->v = v;
    new_edge->prev = g[u];
    g[u] = new_edge;
}
bool done[200001];
int vertex_count;
int edge_count;
bool dfs(int u) {
    done[u] = 1;
    vertex_count++;
    int visit_count = 0;
    int degree = 0;
    struct member_t* edge = g[u];
    while (edge != NULL) {
        edge_count++;
        degree++;
        if (!done[edge->v]) {
            visit_count++;
            if (!dfs(edge->v)) visit_count = 1e9;
        }
        edge = edge->prev;
    }

    return (degree == 2) && (visit_count <= 1);
}

int n, m;
void solve() {
    scanf("%d %d", &n, &m);
    for (int i = 1, u, v; i <= m; i++) {
        scanf("%d %d", &u, &v);
        add_edge(u, v);
        add_edge(v, u);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (!done[i]) {
            vertex_count = edge_count = 0;
            if (dfs(i)) ans += (edge_count == vertex_count * 2);
        }
    printf("%d\n", ans);
}

int main() {
    int t = 1;
    // scanf("%d", &t);
    while (t--) solve();
}