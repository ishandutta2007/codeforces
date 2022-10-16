#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int next_int() {
    char c;
    while (c = getchar()) {
        if ((c >= '0') && (c <= '9')) break;
    }
    int res = c - 48;
    while (c = getchar()) {
        if ((c < '0') || (c > '9')) break;
        res *= 10;
        res += (c - 48);
    }
    return res;
}

int n, k;
struct {
    int u, v;
} e[400000];
struct {
    int deg, head, tail;
} g[400001];
int next[800001];
int queue[400001];
int queue_head, queue_tail;
void queue_clear() {
    queue_head = 0;
    queue_tail = -1;
}
int queue_push(int val) { queue[++queue_tail] = val; }
bool queue_empty() { return queue_head > queue_tail; }
int queue_pop() { return queue[queue_head++]; }
int queue_size() { return queue_tail - queue_head + 1; }

void solve() {
    n = next_int();
    k = next_int();
    for (int i = 1; i <= n; i++) g[i].deg = 0;
    for (int i = 1; i < n; i++) {
        e[i].u = next_int();
        e[i].v = next_int();
        g[e[i].u].deg++;
        g[e[i].v].deg++;
    }
    for (int i = 1; i <= n; i++) {
        g[i].head = g[i - 1].head + g[i - 1].deg;
        g[i].tail = g[i].head - 1;
    }
    for (int i = 1; i < n; i++) {
        next[++g[e[i].u].tail] = e[i].v;
        next[++g[e[i].v].tail] = e[i].u;
    }
    queue_clear();
    int ans = n;
    for (int i = 1; i <= n; i++)
        if (g[i].deg == 1) queue_push(i);
    for (int i = 1; i <= k; i++) {
        if (ans <= 1) {
            ans = 0;
            break;
        }
        int sz = queue_size();
        for (int j = 1; j <= sz; j++) {
            int u = queue_pop();
            ans--;
            for (int iter = g[u].head, v; iter <= g[u].tail; iter++) {
                v = next[iter];
                g[v].deg--;
                if (g[v].deg == 1) queue_push(v);
            }
        }
    }
    printf("%d\n", ans);
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}