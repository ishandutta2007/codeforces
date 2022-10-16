#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct member_t {
    int v;
    struct member_t* prev;
};
struct member_t* g[200001];
void add_edge(int u, int v) {
    struct member_t* new_edge = malloc(sizeof(struct member_t));
    new_edge->v = v;
    new_edge->prev = g[u];
    g[u] = new_edge;
}

int n;
int a[200001];

int q[200000];
int head, tail;
int pop() { return q[head++]; }
void push(int u) { q[++tail] = u; }
bool empty() { return head > tail; }
void clear() {
    head = 0;
    tail = -1;
}

bool done[200001];
int dist[200001];
int ans[200001];

void bfs(int modulo) {
    clear();
    for (int i = 1; i <= n; i++) done[i] = 0;
    for (int i = 1; i <= n; i++)
        if (a[i] % 2 == modulo) {
            done[i] = 1;
            push(i);
            dist[i] = 0;
        }
    int u;
    while (!empty()) {
        u = pop();
        struct member_t* edge = g[u];
        while (edge != NULL) {
            int v = edge->v;
            if (!done[v]) {
                done[v] = 1;
                dist[v] = dist[u] + 1;
                push(v);
            }
            edge = edge->prev;
        }
    }
    for (int i = 1; i <= n; i++)
        if (a[i] % 2 != modulo) {
            if (done[i]) ans[i] = dist[i];
        }
}

void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        if (i - a[i] >= 1) add_edge(i - a[i], i);
        if (i + a[i] <= n) add_edge(i + a[i], i);
    }
    for (int i = 1; i <= n; i++) ans[i] = -1;
    bfs(0);
    bfs(1);
    for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
    putchar('\n');
}

int main() {
    int t = 1;
    // scanf("%d", &t);
    while (t--) solve();
}