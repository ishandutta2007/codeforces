#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct point_t {
    int x;
    int v;
} p[200001], buffer[200001];

void merge_sort(int l, int r) {
    if (l >= r) return;
    int m = (l + r) / 2;
    merge_sort(l, m);
    merge_sort(m + 1, r);
    int x = l, y = m + 1;
    int pos = 0;
    while ((x <= m) && (y <= r)) {
        if (p[x].x < p[y].x) buffer[pos++] = p[x++];
        else buffer[pos++] = p[y++];
    }
    while (x <= m) buffer[pos++] = p[x++];
    while (y <= r) buffer[pos++] = p[y++];
    for (int i = l; i <= r; i++) p[i] = buffer[i - l];
}

int n, m;

int ft_w[200001];
int64_t ft_s[200001];
void update(int u, int64_t s) {
    for (; u <= m; u += u & -u) {
        ft_w[u]++;
        ft_s[u] += s;
    }
}

int64_t get(int u, int64_t x) {
    int64_t ans = 0;
    int w = 0;
    for (; u > 0; u -= u & -u) {
        ans += ft_s[u];
        w += ft_w[u];
    }
    ans += x * w;
    return ans;
}

void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &p[i].v);
    for (int i = 1; i <= n; i++) scanf("%d", &p[i].x);
    merge_sort(1, n);
    for (int i = 1; i <= n; i++) {
        p[i].x ^= p[i].v;
        p[i].v ^= p[i].x;
        p[i].x ^= p[i].v;
    }
    int old = p[1].v;
    m = 1;
    for (int i = 1; i <= n; i++) {
        if (p[i].v == old) {
            p[i].v = m;
        } else {
            old = p[i].v;
            p[i].v = ++m;
        }
    }
    merge_sort(1, n);
    int64_t ans = 0;
    for (int i = 1; i <= n; i++) {
        // x[i] >= x[j] -> v[j] <= v[i]
        ans += get(p[i].v, p[i].x);
        update(p[i].v, -p[i].x);
    }
    printf("%lld\n", ans);
}

int main() {
    int t = 1;
    // scanf("%d", &t);
    while (t--) solve();
}