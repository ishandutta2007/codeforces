#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n, a, b, k;
int h[200001], buffer[200001];
void merge_sort(int l, int r) {
    if (l >= r) return;
    int m = (l + r) / 2;
    merge_sort(l, m);
    merge_sort(m + 1, r);
    int x = l, y = m + 1, pos = 0;
    while ((x <= m) && (y <= r)) {
        if (h[x] < h[y]) buffer[pos++] = h[x++];
        else buffer[pos++] = h[y++];
    }
    while (x <= m) buffer[pos++] = h[x++];
    while (y <= r) buffer[pos++] = h[y++];
    for (int i = l; i <= r; i++) h[i] = buffer[i - l];
}
// if a monster has health of h, how many cheat is required
int required(int h) {
    h %= (a + b);
    if (h == 0) h = a + b;
    return (h - 1) / a;
}
void solve() {
    scanf("%d %d %d %d", &n, &a, &b, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &h[i]);
        h[i] = required(h[i]);
    }
    merge_sort(1, n);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (h[i] > k) break;
        ans++;
        k -= h[i];
    }
    printf("%d\n", ans);
}

int main() {
    int t = 1;
    // scanf("%d", &t);
    while (t--) solve();
}