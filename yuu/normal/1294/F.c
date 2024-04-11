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
    new_edge->v = v;
    new_edge->prev = g[u];
    g[u] = new_edge;
}
int n;
bool done[200001];
int f[200001];
int trace[200001];
int queue[200001];
int head, tail;
void clear() {
    head = 0;
    tail = -1;
    for (int i = 1; i <= n; i++) done[i] = 0;
    for (int i = 1; i <= n; i++) f[i] = 0;
}
void push(int u) { queue[++tail] = u; }
int pop() {
    assert(head <= tail);
    return queue[head++];
}
bool empty() { return head > tail; }

void bfs() {
    int u;
    // printf("BFS\n");
    while (!empty()) {
        u = pop();
        // printf("%d %d\n", u, f[u]);
        struct member_t* edge = g[u];
        while (edge != NULL) {
            int v = edge->v;
            if (!done[v]) {
                done[v] = 1;
                f[v] = f[u] + 1;
                trace[v] = u;
                push(v);
            }
            edge = edge->prev;
        }
    }
}
void solve() {
    scanf("%d", &n);
    for (int i = 1, u, v; i < n; i++) {
        scanf("%d %d", &u, &v);
        add_edge(u, v);
        add_edge(v, u);
    }

    clear();
    push(1);
    done[1] = 1;
    bfs();
    int a = queue[tail];

    clear();
    push(a);
    done[a] = 1;
    bfs();
    int b = queue[tail];
    int ans = f[b];
    clear();
    push(a);
    done[a] = 1;
    int u = b;
    while (u != a) {
        push(u);
        done[u] = 1;
        u = trace[u];
    }
    bfs();
    int c = queue[tail];
    ans += f[c];
    printf("%d\n%d %d %d\n", ans, a, b, c);
}

int main() {
    int t = 1;
    // scanf("%d", &t);
    while (t--) solve();
}