#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n, d, k;
struct edge_t {
    int u, v;
} e[400000];

void output() {
    puts("YES");
    for (int i = 1; i < n; i++) printf("%d %d\n", e[i].u, e[i].v);
    exit(0);
}

int deg[400001];
int m = 0;
int vertex = 0;
void try_expand(int u, int max_allowed) {
    if (max_allowed <= 0) return;
    if (m == n - 1) return;
    while (deg[u] < k) {
        int v = ++vertex;
        deg[u]++;
        deg[v]++;
        m++;
        e[m].u = u;
        e[m].v = v;
        if (m == n - 1) return;
        try_expand(v, max_allowed - 1);
        if (m == n - 1) return;
    }
}
void solve() {
    scanf("%d %d %d", &n, &d, &k);
    if (d >= n) {
        puts("NO");
        return;
    }
    for (int i = 1; i <= d; i++) {
        m++;
        e[m].u = i;
        e[m].v = i + 1;
        deg[i]++;
        deg[i + 1]++;
    }
    vertex = d + 1;
    if (k == 1) {
        if (n == 2) output();
        puts("NO");
        return;
    } else if (k == 2) {
        if (d + 1 == n) output();
        puts("NO");
        return;
    }
    assert(k >= 3);
    for (int i = 2; i <= d; i++) {
        int max_allowed = i - 1;
        if (max_allowed > d + 1 - i) max_allowed = d + 1 - i;
        try_expand(i, max_allowed);
    }
    if (m == n - 1) output();
    puts("NO");
}

int main() {
    int t = 1;
    // scanf("%d", &t);
    while (t--) solve();
}