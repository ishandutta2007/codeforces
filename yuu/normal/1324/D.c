#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n;
int a[200001];
int b[200001];
struct item_t {
    int i, w;
} f[200001], buffer[200001];
void merge_sort(int l, int r) {
    if (l >= r) return;
    int m = (l + r) / 2;
    merge_sort(l, m);
    merge_sort(m + 1, r);
    int x = l, y = m + 1;
    int pos = 0;
    while ((x <= m) && (y <= r)) {
        if (f[x].w < f[y].w) buffer[pos++] = f[x++];
        else buffer[pos++] = f[y++];
    }
    while (x <= m) buffer[pos++] = f[x++];
    while (y <= r) buffer[pos++] = f[y++];
    for (int i = l; i <= r; i++) f[i] = buffer[i - l];
}
void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
    for (int i = 1; i <= n; i++) {
        f[i].i = i;
        f[i].w = a[i] - b[i];
    }
    merge_sort(1, n);
    int first = 1;
    int64_t ans = 0;
    for (int i = n; i >= 1; i--) {
        int weight = -f[i].w;  // b[id] - a[id]
        while (first <= n) {
            if (f[first].w <= weight) first++;
            else break;
        }
        ans += n - first + 1 - (first <= i);
    }
    printf("%lld\n", ans / 2);
}

int main() {
    int t = 1;
    // scanf("%d", &t);
    while (t--) solve();
}