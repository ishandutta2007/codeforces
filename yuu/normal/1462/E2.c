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
const int base = 1000000000 + 7;
int64_t f[200001];
int64_t r[200001];
int64_t power(int64_t x, int64_t a) {
    if (a == 0) return 1;
    int64_t t = power(x, a / 2);
    t *= t;
    t %= base;
    if (a % 2) t *= x;
    t %= base;
    return t;
}
void prepare() {
    f[0] = 1;
    for (int i = 1; i <= 200000; i++) f[i] = (f[i - 1] * i) % base;
    r[200000] = power(f[200000], base - 2);
    for (int i = 200000; i >= 1; i--) r[i - 1] = (r[i] * i) % base;
}
int64_t choose(int64_t n, int k) {
    if (n < k) return 0;
    return ((f[n] * r[k]) % base * r[n - k]) % base;
}
void solve() {
    scanf("%d", &n);
    scanf("%d %d", &m, &k);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    merge_sort(1, n);
    int64_t ans = 0;
    for (int i = 1, j = 1; i <= n; i++) {
        while (a[i] - a[j] > k) j++;
        ans += choose(i - j, m - 1);
        ans %= base;
    }
    printf("%lld\n", ans);
}
int main() {
    prepare();
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}