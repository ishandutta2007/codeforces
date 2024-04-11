#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n;
char s[201];
int m;
char t[201];
int p;
int cnt;
int encode_state(int i, int j, int k) {
    return k + (p + 1) * (j + (m + 1) * i);
}
void decode_state(int state, int* i, int* j, int* k) {
    *k = state % (p + 1);
    state /= (p + 1);
    *j = state % (m + 1);
    state /= (m + 1);
    *i = state;
}

struct member_t {
    int v;
    struct member_t* prev;
};
struct member_t* g[202 * 202 * 202 + 1];
void add_edge(int u, int v) {
    struct member_t* new_edge = malloc(sizeof(struct member_t));
    new_edge->v = v;
    new_edge->prev = g[u];
    g[u] = new_edge;
}

int q[202 * 202 * 202];
int head, tail;
int pop() { return q[head++]; }
void push(int u) { q[++tail] = u; }
bool empty() { return head > tail; }
void clear() {
    head = 0;
    tail = -1;
}
bool done[202 * 202 * 202];
int trace[202 * 202 * 202];

void bfs() {
    clear();
    int u = encode_state(0, 0, 0);
    push(u);
    done[u] = 1;
    while (!empty()) {
        u = pop();
        struct member_t* edge = g[u];
        while (edge != NULL) {
            int v = edge->v;
            if (!done[v]) {
                // printf("%d %d\n", u, v);
                done[v] = 1;
                trace[v] = u;
                push(v);
            }
            edge = edge->prev;
        }
    }
}

void get_ans(int state, int i, int j, int k) {
    if ((i == 0) && (j == 0) && (k == 0)) return;
    // printf("%d %d %d %d\n", state, i, j, k);
    int oi, oj, ok;
    decode_state(trace[state], &oi, &oj, &ok);
    get_ans(trace[state], oi, oj, ok);
    if (ok < k) putchar('(');
    else putchar(')');
}

void solve() {
    scanf("%s", &s);
    n = strlen(s);
    scanf("%s", &t);
    m = strlen(t);
    p = (m > n) ? m : n;
    cnt = (n + 1) * (m + 1) * (p + 1);
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
            for (int k = 0; k <= p; k++) {
                // printf("%d %d %d\n", i, j, k);
                // int encoded = encode_state(i, j, k);
                // int ti, tj, tk;
                // decode_state(encoded, &ti, &tj, &tk);
                // printf("%d %d %d\n", ti, tj, tk);
                // assert(i == ti);
                // assert(j == tj);
                // assert(k == tk);
                // select '('
                if (k < p) {
                    int ni = i;
                    if ((ni < n) && (s[ni] == '(')) ni++;
                    int nj = j;
                    if ((nj < m) && (t[nj] == '(')) nj++;
                    add_edge(encode_state(i, j, k), encode_state(ni, nj, k + 1));
                }
                // select ')'
                if (k > 0) {
                    int ni = i;
                    if ((ni < n) && (s[ni] == ')')) ni++;
                    int nj = j;
                    if ((nj < m) && (t[nj] == ')')) nj++;
                    add_edge(encode_state(i, j, k), encode_state(ni, nj, k - 1));
                }
            }
    bfs();
    get_ans(encode_state(n, m, 0), n, m, 0);
}
int main() {
    int t = 1;
    // scanf("%d", &t);
    while (t--) solve();
}