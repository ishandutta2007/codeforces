#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n, m, s;
int u[5001];
int v[5001];
int in_deg[5001];
struct member_t {
    struct member_t* prev;
    int v;
};
struct member_t* g[5001];
void add_edge(int u, int v) {
    struct member_t* new_item = malloc(sizeof(struct member_t));
    new_item->prev = g[u];
    new_item->v = v;
    in_deg[v]++;
    g[u] = new_item;
}

int done[5001];
int low[5001];
int num[5001];
int cc[5001];
int cnt;

int stk[5001];
int stk_sz = 0;
int push(int u) { stk[++stk_sz] = u; }
int pop() { return stk[stk_sz--]; }

int min(int x, int y) { return (x < y) ? x : y; }

void dfs(int u) {
    cnt++;
    low[u] = num[u] = cnt;
    done[u] = 1;
    struct member_t* edge = g[u];
    push(u);
    while (edge != NULL) {
        int v = edge->v;
        if (!done[v]) {
            dfs(v);
            low[u] = min(low[u], low[v]);
        } else if (done[v] == 1) {
            low[u] = min(low[u], low[v]);
        }
        edge = edge->prev;
    }
    if (low[u] == num[u]) {
        int v;
        while (true) {
            v = pop();
            done[v] = 2;
            cc[v] = u;
            if (v == u) break;
        }
    }
}

void solve() {
    scanf("%d %d %d", &n, &m, &s);
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &u[i], &v[i]);
        add_edge(u[i], v[i]);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (!done[i]) dfs(i);
    for (int i = 1; i <= n; i++) in_deg[i] = 0;
    for (int i = 1; i <= m; i++) {
        if (cc[u[i]] != cc[v[i]]) in_deg[cc[v[i]]]++;
    }
    for (int i = 1; i <= n; i++)
        if (i == cc[i]) {
            if ((in_deg[i] == 0) && (i != cc[s])) ans++;
        }
    printf("%d\n", ans);
}

int main() {
    int t = 1;
    // scanf("%d", &t);
    while (t--) solve();
}