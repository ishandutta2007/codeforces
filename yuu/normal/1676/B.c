#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
int n;
int a[50];
void solve() {
    scanf("%d", &n);
    int mi = 1e9;
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < n; i++)
        if (a[i] < mi) mi = a[i];
    int ans = 0;
    for (int i = 0; i < n; i++) ans += a[i] - mi;
    printf("%d\n", ans);
}
int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}