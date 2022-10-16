#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int less(const void* a, const void* b) { return (*(int*)(a)) - (*(int*)(b)); }
int n, k;
int a[100];

void solve() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    qsort(a, n, sizeof(int), less);
    int ans = 0;
    for (int i = n - k * 2, j = n - k; j < n; i++, j++)
        if (a[i] == a[j]) ans++;

    for (int i = n - 1 - k * 2; i >= 0; i--) ans += a[i];
    printf("%d\n", ans);
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}