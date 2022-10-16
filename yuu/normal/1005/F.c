#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n, m, k;
struct edge_t {
    int a, b;
} e[200001];

struct member_t {
    struct member_t* prev;
    int id;
};
struct member_t* g[200001];
void add_edge(int u, int id) {
    struct member_t* new_edge = malloc(sizeof(struct member_t));
    new_edge->id = id;
    new_edge->prev = g[u];
    g[u] = new_edge;
}

int q[200001];
int head = 0, tail = -1;
void push(int u) { q[++tail] = u; }
int pop() { return q[head++]; }
bool empty() { return head > tail; }
bool done[200001];
int f[200001];

struct member_t* trace[200001];
int trace_size[200001];
void add_trace_edge(int u, int id) {
    struct member_t* new_edge = malloc(sizeof(struct member_t));
    new_edge->id = id;
    new_edge->prev = trace[u];
    trace[u] = new_edge;
    trace_size[u]++;
}

void bfs() {
    push(1);
    done[1] = 1;
    while (!empty()) {
        int u = pop();
        struct member_t* edge = g[u];
        while (edge != NULL) {
            int v = e[edge->id].a ^ e[edge->id].b ^ u;
            if (done[v]) {
                if (f[v] == f[u] + 1) add_trace_edge(v, edge->id);
            } else {
                f[v] = f[u] + 1;
                done[v] = 1;
                add_trace_edge(v, edge->id);
                push(v);
            }
            edge = edge->prev;
        }
    }
}

bool select[200001];

void print_way() {
    for (int i = 1; i <= m; i++) putchar('0' + select[i]);
    putchar('\n');
    k--;
    if (k == 0) exit(0);
}

void backtrack(int u) {
    if (u == n + 1) {
        print_way();
    } else {
        struct member_t* edge = trace[u];
        while (edge != NULL) {
            select[edge->id] = 1;
            backtrack(u + 1);
            select[edge->id] = 0;
            edge = edge->prev;
        }
    }
}

void solve() {
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &e[i].a, &e[i].b);
        add_edge(e[i].a, i);
        add_edge(e[i].b, i);
    }
    bfs();
    int64_t number_of_way = 1;
    for (int i = 2; i <= n; i++) {
        number_of_way *= trace_size[i];
        if (number_of_way > k) break;
    }
    if (k > number_of_way) k = number_of_way;
    printf("%d\n", k);
    backtrack(2);
}

int main() {
    int t = 1;
    // scanf("%d", &t);
    while (t--) solve();
}