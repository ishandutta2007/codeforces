#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n, m;
int a[200001];
int buffer[200001];
void merge_sort(int l, int r) {
    if (l >= r) return;
    int m = (l + r) / 2;
    merge_sort(l, m);
    merge_sort(m + 1, r);
    int x = l, y = m + 1, pos = 0;
    while ((x <= m) && (y <= r)) {
        if (a[x] < a[y]) buffer[pos++] = a[x++];
        else buffer[pos++] = a[y++];
    }
    while (x <= m) buffer[pos++] = a[x++];
    while (y <= r) buffer[pos++] = a[y++];
    for (int i = l; i <= r; i++) a[i] = buffer[i - l];
}

struct bar_t {
    int y, dy, limit;
} b[400001], buffer_b[400001];
int cnt;
void merge_sort_b(int l, int r) {
    if (l >= r) return;
    int m = (l + r) / 2;
    merge_sort_b(l, m);
    merge_sort_b(m + 1, r);
    int x = l, y = m + 1, pos = 0;
    while ((x <= m) && (y <= r)) {
        if (b[x].limit > b[y].limit) buffer_b[pos++] = b[x++];
        else buffer_b[pos++] = b[y++];
    }
    while (x <= m) buffer_b[pos++] = b[x++];
    while (y <= r) buffer_b[pos++] = b[y++];
    for (int i = l; i <= r; i++) b[i] = buffer_b[i - l];
}

void make_bar(int l, int r) {
    int m = (l + r) / 2;
    if (m > l) {
        cnt++;
        b[cnt].y = l;
        b[cnt].dy = 1;
        b[cnt].limit = m - l;
    }
    if (m + 1 < r) {
        cnt++;
        b[cnt].y = r;
        b[cnt].dy = -1;
        b[cnt].limit = r - m - 1;
    }
}

int y[200001];

void solve() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    merge_sort(1, n);
    for (int i = 1; i < n; i++) make_bar(a[i], a[i + 1]);
    cnt++;
    b[cnt].y = a[1];
    b[cnt].dy = -1;
    b[cnt].limit = 1e9;

    cnt++;
    b[cnt].y = a[n];
    b[cnt].dy = 1;
    b[cnt].limit = 1e9;
    merge_sort_b(1, cnt);
    int done = 0;
    int64_t ans = 0;
    for (int d = 1;; d++) {
        for (int i = 1; i <= cnt; i++) {
            if (b[i].limit < d) break;
            done++;
            ans += d;
            y[done] = b[i].y + b[i].dy * d;
            if (done == m) break;
        }
        if (done == m) break;
    }
    printf("%lld\n", ans);
    for (int i = 1; i <= m; i++) printf("%d ", y[i]);
    puts("");
}

int main() {
    int t = 1;
    // scanf("%d", &t);
    while (t--) solve();
}