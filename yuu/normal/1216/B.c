#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n;
int a[1001];
int ans[1001];
int buffer[1001];
void merge_sort(int l, int r) {
    if (r - l <= 1) return;
    int m = (l + r) / 2;
    merge_sort(l, m);
    merge_sort(m, r);
    int x = l, y = m, pos = 0;
    while ((x < m) && (y < r)) {
        if (a[ans[x]] > a[ans[y]]) buffer[pos++] = ans[x++];
        else buffer[pos++] = ans[y++];
    }
    while (x < m) buffer[pos++] = ans[x++];
    while (y < r) buffer[pos++] = ans[y++];
    for (int i = l; i < r; i++) ans[i] = buffer[i - l];
}

void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) ans[i] = i;
    merge_sort(1, n + 1);
    int cost = 0;
    for (int i = 1; i <= n; i++) {
        cost += a[ans[i]] * (i - 1) + 1;
    }
    printf("%d\n", cost);
    for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
}

int main() {
    int t = 1;
    // scanf("%d", &t);
    while (t--) solve();
}