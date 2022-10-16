#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n, q;
int first_edge[200001];
int last_edge[200001];
int next_edge[200001];

int cnt;
int order[200001];
int first[200001];
int last[200001];

void dfs(int u) {
    cnt++;
    order[cnt] = u;
    first[u] = cnt;
    int v = first_edge[u];
    while (v) {
        dfs(v);
        v = next_edge[v];
    }
    last[u] = cnt;
}

void solve() {
    scanf("%d %d", &n, &q);
    for (int i = 2, p; i <= n; i++) {
        scanf("%d", &p);
        if (first_edge[p] == 0) first_edge[p] = i;
        else next_edge[last_edge[p]] = i;
        last_edge[p] = i;
    }
    dfs(1);
    for (int i = 1, u, k; i <= q; i++) {
        scanf("%d %d", &u, &k);
        int pos = first[u] + k - 1;
        if (pos > last[u]) pos = -1;
        else pos = order[pos];
        printf("%d\n", pos);
    }
}

int main() {
    int t = 1;
    // scanf("%d", &t);
    while (t--) solve();
}