#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
int n, m, k;
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
int64_t choose(int64_t n, int k) {
    if (n < k) return 0;
    assert(k == 2);
    return n * (n - 1) / 2;
}
void solve() {
    scanf("%d", &n);
    // scanf("%d %d", &m, &k);
    m = 3;
    k = 2;
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    merge_sort(1, n);
    int64_t ans = 0;
    for (int i = 1, j = 1; i <= n; i++) {
        while (a[i] - a[j] > k) j++;
        ans += choose(i - j, m - 1);
    }
    printf("%lld\n", ans);
}
int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}