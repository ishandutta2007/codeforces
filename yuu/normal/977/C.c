#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n, k;
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

void solve() {
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    merge_sort(1, n);
    if (k == 0) {
        if (a[1] == 1) {
            puts("-1");
        } else {
            puts("1");
        }
        return;
    }
    if ((k < n) && (a[k] == a[k + 1])) {
        puts("-1");
    } else {
        printf("%d\n", a[k]);
    }
}

int main() {
    int t = 1;
    // scanf("%d", &t);
    while (t--) solve();
}