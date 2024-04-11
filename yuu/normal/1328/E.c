#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n, m;
struct item_t {
    int v;
    struct item_t* prev;
};
struct item_t* g[200001];

void add_edge(int u, int v) {
    struct item_t* item = malloc(sizeof(struct item_t));
    item->prev = g[u];
    item->v = v;
    g[u] = item;
}

bool done[200001];
int cnt;
int first[200001];
int last[200001];
int p[200001];
void dfs(int u) {
    done[u] = 1;
    cnt++;
    first[u] = cnt;
    struct item_t* item = g[u];
    while (item != NULL) {
        if (!done[item->v]) {
            p[item->v] = u;
            dfs(item->v);
        }
        item = item->prev;
    }
    last[u] = cnt;
}

struct element_t {
    int pos, weight;
} e[400001], buffer[400001];

void merge_sort(int l, int r) {
    if (l == r) return;
    int m = (l + r) / 2;
    merge_sort(l, m);
    merge_sort(m + 1, r);
    int x = l, y = m + 1;
    int pos = 0;
    while ((x <= m) && (y <= r)) {
        if (e[x].pos < e[y].pos) buffer[pos++] = e[x++];
        else buffer[pos++] = e[y++];
    }
    while ((x <= m)) buffer[pos++] = e[x++];
    while ((y <= r)) buffer[pos++] = e[y++];
    for (int i = l; i <= r; i++) e[i] = buffer[i - l];
}

void solve() {
    scanf("%d %d", &n, &m);
    for (int i = 1, u, v; i < n; i++) {
        scanf("%d %d", &u, &v);
        add_edge(u, v);
        add_edge(v, u);
    }
    dfs(1);
    for (int i = 1, v, k; i <= m; i++) {
        scanf("%d", &k);
        for (int j = 1; j <= k; j++) {
            scanf("%d", &v);
            if (p[v]) v = p[v];
            e[j * 2 - 1].pos = first[v];
            e[j * 2 - 1].weight = 1;
            e[j * 2].pos = last[v] + 1;
            e[j * 2].weight = -1;
        }
        merge_sort(1, k * 2);
        int current = 0;
        for (int j = 1; j <= k * 2; j++) {
            current += e[j].weight;
            if ((j < k * 2) && (e[j + 1].pos == e[j].pos)) continue;
            if (current == k) {
                printf("YES\n");
                goto next_i;
            }
        }
        printf("NO\n");
    next_i:;
    }
}

int main() {
    int t = 1;
    // scanf("%d", &t);
    while (t--) solve();
}