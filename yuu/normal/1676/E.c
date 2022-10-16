#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int a[150001];
int buffer[150001];
void merge_sort(int l, int r) {
    if (l >= r) return;
    int m = (l + r) / 2;
    merge_sort(l, m);
    merge_sort(m + 1, r);
    int pos = 0;
    int x = l, y = m + 1;
    while ((x <= m) && (y <= r)) {
        if (a[x] > a[y]) buffer[pos++] = a[x++];
        else buffer[pos++] = a[y++];
    }
    while (x <= m) buffer[pos++] = a[x++];
    while (y <= r) buffer[pos++] = a[y++];
    for (int i = l; i <= r; i++) a[i] = buffer[i - l];
}

void solve() {
    int n, q;
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    merge_sort(1, n);
    for (int i = 1; i <= n; i++) a[i] += a[i - 1];
    for (int i = 1, x; i <= q; i++) {
        scanf("%d", &x);
        if (a[n] < x) {
            printf("-1\n");
        } else {
            int low = 1, high = n, mid, res;
            while (low <= high) {
                mid = (low + high) / 2;
                if (a[mid] >= x) {
                    res = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            printf("%d\n", res);
        }
    }
}
int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}