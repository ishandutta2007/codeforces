#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
int n, m;
int64_t a[200001];
int64_t peak[200001];
int binary_search(int64_t target) {
    assert(peak[n] >= target);
    int low = 1, high = n, mid, res;
    while (low <= high) {
        mid = (low + high) / 2;
        if (peak[mid] >= target) {
            res = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return res - 1;
}
int64_t get(int64_t x) {
    if (x <= peak[n]) {
        return binary_search(x);
    } else {
        if (a[n] <= 0) return -1;
        // a[n] > 0
        // p*a[n] + peak[n] >= x
        int64_t p = (x - peak[n]) / a[n];
        while (a[n] * p + peak[n] >= x) p--;
        while (a[n] * p + peak[n] < x) p++;
        return p * n + binary_search(x - a[n] * p);
    }
}
void solve() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    for (int i = 1; i <= n; i++) a[i] += a[i - 1];
    peak[1] = a[1];
    for (int i = 2; i <= n; i++) peak[i] = (a[i] > peak[i - 1]) ? a[i] : peak[i - 1];
    for (int i = 1, x; i <= m; i++) {
        scanf("%d", &x);
        printf("%lld ", get(x));
    }
    printf("\n");
}
int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}