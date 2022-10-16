#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
int n;
int a[200001];
int64_t f[200001];
void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    int64_t ans = 0;
    for (int i = n; i >= 1; i--) {
        if (a[i] + i <= n) f[i] = f[a[i] + i] + a[i];
        else f[i] = a[i];
        if (ans < f[i]) ans = f[i];
    }
    printf("%lld\n", ans);
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}