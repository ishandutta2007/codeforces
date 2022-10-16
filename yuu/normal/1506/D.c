#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n;
int a[200001];
int buff[200001];
void merge_sort(int l, int r) {
    if (l == r) return;
    int m = (l + r) / 2;
    merge_sort(l, m);
    merge_sort(m + 1, r);
    int x = l;
    int y = m + 1;
    int z = 0;
    while ((x <= m) && (y <= r)) {
        if (a[x] < a[y])
            buff[z++] = a[x++];
        else
            buff[z++] = a[y++];
    }
    while (x <= m) buff[z++] = a[x++];
    while (y <= r) buff[z++] = a[y++];
    for (int i = 0; i < z; i++) a[l + i] = buff[i];
}
void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    merge_sort(1, n);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int j = i;
        while ((j < n) && (a[j + 1] == a[j])) j++;
        if (ans < j - i + 1) ans = j - i + 1;
        i = j;
    }
    if (ans > n - ans) {
        printf("%d\n", ans - (n - ans));
    } else {
        printf("%d\n", n % 2);
    }
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}