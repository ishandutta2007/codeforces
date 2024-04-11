#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n;
struct Point {
    int r, c;
} a[200001], buff[200001];

void merge_sort(int l, int r) {
    if (l == r) return;
    int m = (l + r) / 2;
    merge_sort(l, m);
    merge_sort(m + 1, r);
    int x = l;
    int y = m + 1;
    int z = 0;
    while ((x <= m) && (y <= r)) {
        if (a[x].r < a[y].r)
            buff[z++] = a[x++];
        else
            buff[z++] = a[y++];
    }
    while (x <= m) buff[z++] = a[x++];
    while (y <= r) buff[z++] = a[y++];
    for (int i = 0; i < z; i++) a[l + i] = buff[i];
}

int64_t get_min_dist(int r, int c, int x, int y) {
    if ((r == x) && (c == y)) return 0;
    assert(x > r);
    assert(y >= c);
    int y_r_c = r - c;
    int y_x_y = x - y;
    assert(y_r_c <= y_x_y);
    if (y_r_c == y_x_y) {
        if (y_r_c % 2) return 0;
        return x - r;
    }
    if ((y_r_c % 2) == 0) y_r_c++;
    return (y_x_y - y_r_c + 1) / 2;
}

void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i].r);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i].c);
    merge_sort(1, n);
    int64_t ans = 0;
    a[0].r = a[0].c = 1;
    for (int i = 0; i < n; i++) ans += get_min_dist(a[i].r, a[i].c, a[i + 1].r, a[i + 1].c);
    printf("%lld\n", ans);
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}