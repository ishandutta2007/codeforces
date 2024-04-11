#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n;
struct member_t {
    struct member_t* prev;
    int v;
};
struct member_t* g[200001];
void add_edge(int u, int v) {
    struct member_t* new_edge = malloc(sizeof(struct member_t));
    new_edge->prev = g[u];
    new_edge->v = v;
    g[u] = new_edge;
}

int a[200001];
int b[200001];

int64_t prefix_a[200001];
int64_t prefix_b[200001];
int sz = 0;
void push(int u) {
    sz++;
    prefix_a[sz] = prefix_a[sz - 1] + a[u];
    prefix_b[sz] = prefix_b[sz - 1] + b[u];
}
void pop() { sz--; }

int search() {
    int low = 1, high = sz, mid, res = 0;
    while (low <= high) {
        mid = (low + high) / 2;
        if (prefix_b[mid] <= prefix_a[sz]) {
            res = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return res;
}
int r[200001];
void dfs(int u) {
    push(u);
    r[u] = search();
    struct member_t* edge = g[u];
    while (edge != NULL) {
        dfs(edge->v);
        edge = edge->prev;
    }
    pop();
}
void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) g[i] = NULL;
    for (int i = 2, p; i <= n; i++) {
        scanf("%d %d %d", &p, &a[i], &b[i]);
        add_edge(p, i);
    }
    dfs(1);
    for (int i = 2; i <= n; i++) printf("%d ", r[i] - 1);
    printf("\n");
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}