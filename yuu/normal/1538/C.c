#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n, l, r;
int a[200000];
int buff[200000];

void merge_sort(int l, int r) {
    if (l == r) return;
    int m = (l + r) / 2;
    merge_sort(l, m);
    merge_sort(m + 1, r);
    int x = l, y = m + 1;
    int pos = 0;
    while ((x <= m) && (y <= r)) {
        if (a[x] < a[y]) {
            buff[pos++] = a[x++];
        } else {
            buff[pos++] = a[y++];
        }
    }
    while (x <= m) {
        buff[pos++] = a[x++];
    }
    while (y <= r) {
        buff[pos++] = a[y++];
    }
    for (int i = l; i <= r; i++) a[i] = buff[i - l];
}

int64_t get(int64_t lim) {
    int last = n - 1;
    int64_t ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > lim) break;
        while ((last >= 0) && (a[i] + a[last] > lim)) last--;
        if (last < 0) break;
        if (last >= i)
            ans += i;
        else
            ans += last + 1;
    }
    return ans;
}

void solve() {
    scanf("%d %d %d", &n, &l, &r);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    merge_sort(0, n - 1);
    printf("%lld\n", get(r) - get(l - 1));
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}