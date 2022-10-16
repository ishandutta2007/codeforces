#include <assert.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void write(int x) {
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}

void writesp(int x) {
    write(x);
    putchar(' ');
}

int n;
int a[1001][1001];

int next_int() {
    char c;
    while (c = getchar()) {
        if (isdigit(c)) break;
    }
    int res = c - '0';
    while (c = getchar()) {
        if (!isdigit(c)) break;
        res *= 10;
        res += c - '0';
    }
    return res;
}
int r[2001];
bool done[2001];
bool used[2001];

int root(int u) {
    while (r[u] > 0) u = r[u];
    return u;
}

struct rollback_t {
    int u, r;
} rollback[100000];
int sz;

void clear_rollback() { sz = 0; }

void push_rollback(int u) {
    sz++;
    rollback[sz].u = u;
    rollback[sz].r = r[u];
}

void perform_rollback() {
    while (sz) {
        r[rollback[sz].u] = rollback[sz].r;
        sz--;
    }
}

void unite(int u, int v) {
    u = root(u);
    v = root(v);
    if (u == v) return;
    if (r[u] > r[v]) {
        u ^= v;
        v ^= u;
        u ^= v;
    }
    push_rollback(u);
    push_rollback(v);

    r[u] += r[v];
    r[v] = u;
}

void solve() {
    n = next_int();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) a[i][j] = next_int();
    for (int i = 1; i <= n + n; i++) r[i] = -1;
    for (int i = 1; i <= n + n; i++) done[i] = 0;
    for (int i = 1; i <= n + n; i++) used[i] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            clear_rollback();
            if (a[i][j] < a[j][i]) {
                unite(i, j);
                unite(i + n, j + n);
            } else if (a[i][j] > a[j][i]) {
                unite(i, j + n);
                unite(i + n, j);
            }
            // cannot include this
            if (root(i) == root(i + n)) perform_rollback();
        }
    }
    for (int i = 1; i <= n; i++) {
        if ((!done[root(i)]) && (!done[root(i + n)])) {
            done[root(i)] = done[root(i + n)] = 1;
            used[root(i)] = 1;
        }
    }
    for (int k = 1; k <= n; k++) {
        if (used[root(k)]) {
            for (int i = 1; i <= n; i++) {
                if (i == k) continue;
                a[i][k] ^= a[k][i];
                a[k][i] ^= a[i][k];
                a[i][k] ^= a[k][i];
            }
        } else {
            assert(used[root(k + n)]);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) writesp(a[i][j]);
        putchar('\n');
    }
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}