#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int p[200001];
int pos[200001];
int q[200001];
int a[200001];
int n, k;
// void merge_sort(int l, int r) {
//     if (l >= r) return;
//     int m = (l + r) / 2;
//     merge_sort(l, m);
//     merge_sort(m + 1, r);
//     int x = l, y = m + 1, pos = 0;
//     while ((x <= m) && (y <= r)) {
//         if (a[x].p < a[y].p) buffer[pos++] = a[x++];
//         else buffer[pos++] = a[y++];
//     }
//     while (x <= m) buffer[pos++] = a[x++];
//     while (y <= r) buffer[pos++] = a[y++];
//     for (int i = l; i <= r; i++) a[i] = buffer[i - l];
// }
char ans[200001];
int r[200001];
int right[200001];
int root(int u) {
    if (r[u] < 0) return u;
    return r[u] = root(r[u]);
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
    r[u] += r[v];
    r[v] = u;
    if (right[u] < right[v]) right[u] = right[v];
}
void add_range(int l, int r) {
    while (l < r) {
        unite(l, l + 1);
        l = right[root(l)];
    }
}

void solve() {
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &p[i]);
        pos[p[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &q[i]);
        q[i] = pos[q[i]];
    }
    int mx = 0;
    for (int i = 1; i <= n; i++) r[i] = -1;
    for (int i = 1; i <= n; i++) right[i] = i;
    for (int i = 1; i <= n; i++) {
        if (q[i] < mx) add_range(q[i], mx);
        else mx = q[i];
    }
    char current = 'a' - 1;
    int start = 1;
    while (start <= n) {
        int end = right[root(start)];
        if (k) {
            k--;
            current++;
        }
        for (int i = start; i <= end; i++) ans[p[i]] = current;
        start = end + 1;
    }
    if (k > 0) {
        puts("NO");
        return;
    }
    puts("YES");
    for (int i = 1; i <= n; i++) putchar(ans[i]);
}

int main() {
    int t = 1;
    // scanf("%d", &t);
    while (t--) solve();
}