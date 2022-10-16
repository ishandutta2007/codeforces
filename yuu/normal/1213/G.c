#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n, m;

struct edge_t {
    int u, v, w;
} e[200001], buffer_e[200001];
struct query_t {
    int w, i;
} q[200001], buffer_q[200001];
void merge_sort_e(int l, int r) {
    if (l >= r) return;
    int m = (l + r) / 2;
    merge_sort_e(l, m);
    merge_sort_e(m + 1, r);
    int x = l, y = m + 1, pos = 0;
    while ((x <= m) && (y <= r)) {
        if (e[x].w < e[y].w) buffer_e[pos++] = e[x++];
        else buffer_e[pos++] = e[y++];
    }
    while (x <= m) buffer_e[pos++] = e[x++];
    while (y <= r) buffer_e[pos++] = e[y++];
    for (int i = l; i <= r; i++) e[i] = buffer_e[i - l];
}

void merge_sort_q(int l, int r) {
    if (l >= r) return;
    int m = (l + r) / 2;
    merge_sort_q(l, m);
    merge_sort_q(m + 1, r);
    int x = l, y = m + 1, pos = 0;
    while ((x <= m) && (y <= r)) {
        if (q[x].w < q[y].w) buffer_q[pos++] = q[x++];
        else buffer_q[pos++] = q[y++];
    }
    while (x <= m) buffer_q[pos++] = q[x++];
    while (y <= r) buffer_q[pos++] = q[y++];
    for (int i = l; i <= r; i++) q[i] = buffer_q[i - l];
}

int64_t current_ans;
int r[200001];

int root(int u) {
    if (r[u] < 0) return u;
    return r[u] = root(r[u]);
}
void unite(int u, int v) {
    u = root(u);
    v = root(v);
    assert(u != v);
    if (r[u] > r[v]) {
        u ^= v;
        v ^= u;
        u ^= v;
    }
    current_ans += 1ll * r[u] * r[v];
    r[u] += r[v];
    r[v] = u;
}
int64_t ans[200001];
void solve() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i < n; i++) scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].w);
    for (int i = 1; i <= m; i++) {
        scanf("%d", &q[i].w);
        q[i].i = i;
    };
    merge_sort_e(1, n - 1);
    merge_sort_q(1, m);
    for (int i = 1; i <= n; i++) r[i] = -1;
    for (int i = 1, j = 1; i <= m; i++) {
        while ((j < n) && (e[j].w <= q[i].w)) {
            unite(e[j].u, e[j].v);
            j++;
        }
        ans[q[i].i] = current_ans;
    }
    for (int i = 1; i <= m; i++) printf("%lld ", ans[i]);
}

int main() {
    int t = 1;
    // scanf("%d", &t);
    while (t--) solve();
}