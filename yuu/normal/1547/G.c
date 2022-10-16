#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int next_int() {
    char c;
    while (c = getchar()) {
        if ((c >= '0') && (c <= '9')) break;
    }
    int ans = c - '0';
    while (c = getchar()) {
        if ((c < '0') || (c > '9')) break;
        ans *= 10;
        ans += (c - '0');
    }
    return ans;
}

int n, m;
struct {
    int u, v;
} e[400001];
struct {
    int deg, l, r;
} g[400001];

int next[800001];
struct {
    int deg, l, r;
} rev_g[400001];
int rev_next[800001];

int cnt;
int state[400001];
int num[400001];
int low[400001];
bool in_cc[400001];

int stack[400001];
int stack_head;
void stack_clear() { stack_head = -1; }
bool stack_empty() { return stack_head >= 0; }
int stack_top() { return stack[stack_head]; }
void stack_push(int val) { stack[++stack_head] = val; }
int stack_pop() { return stack[stack_head--]; }

void make_cc(int u) {
    state[u] = 1;
    cnt++;
    num[u] = cnt;
    low[u] = cnt;
    stack_push(u);

    for (int i = g[u].l, v; i <= g[u].r; i++) {
        v = next[i];
        if (v == u) in_cc[u] = 1;
        if (state[v] == 0) {
            make_cc(v);
            if (low[u] > low[v]) low[u] = low[v];
        } else if (state[v] == 1) {
            if (low[u] > num[v]) low[u] = num[v];
        }
    }

    if (low[u] == num[u]) {
        if (stack_top() == u) {
            stack_pop();
        } else {
            while (stack_top() != u) in_cc[stack_pop()] = 1;

            in_cc[stack_pop()] = 1;
        }
    }
    state[u] = 2;
}

bool calc[400001];
int result[400001];

int get(int u) {
    // fprintf(stderr, "u: %d\n", u);
    if (calc[u]) return result[u];
    calc[u] = true;
    if (state[u] == 0) return result[u] = 0;
    if (in_cc[u]) return result[u] = -1;
    if (u == 1) return result[u] = 1;
    result[u] = 0;
    for (int i = rev_g[u].l, v; i <= rev_g[u].r; i++) {
        v = rev_next[i];
        int res = get(v);
        if (res == -1) return result[u] = -1;
        result[u] += res;
        if (result[u] > 2) result[u] = 2;
    }
    return result[u];
}

void solve() {
    n = next_int();
    m = next_int();
    for (int i = 1; i <= n; i++) g[i].deg = 0;
    for (int i = 1; i <= n; i++) rev_g[i].deg = 0;
    for (int i = 1; i <= m; i++) {
        e[i].u = next_int();
        e[i].v = next_int();
        g[e[i].u].deg++;
        rev_g[e[i].v].deg++;
    }
    for (int i = 1; i <= n; i++) {
        g[i].l = g[i - 1].l + g[i - 1].deg;
        g[i].r = g[i].l - 1;
    }
    for (int i = 1; i <= n; i++) {
        rev_g[i].l = rev_g[i - 1].l + rev_g[i - 1].deg;
        rev_g[i].r = rev_g[i].l - 1;
    }

    for (int i = 1; i <= m; i++) {
        next[++g[e[i].u].r] = e[i].v;
        rev_next[++rev_g[e[i].v].r] = e[i].u;
    }

    cnt = 0;
    for (int i = 1; i <= n; i++) in_cc[i] = 0;
    for (int i = 1; i <= n; i++) state[i] = 0;
    stack_clear();
    make_cc(1);

    for (int i = 1; i <= n; i++) calc[i] = 0;
    // get(3);
    // exit(0);
    for (int i = 1; i <= n; i++) printf("%d ", get(i));
    printf("\n");
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}