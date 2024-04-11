#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void solve() {
    int n;
    scanf("%d", &n);
    n /= 2;
    int64_t ans = 1;
    for (int i = 1; i <= n; i++) ans *= n + i;
    for (int i = 1; i <= n; i++) ans /= i;
    ans /= 2;
    for (int i = 1; i < n; i++) ans *= i;
    for (int i = 1; i < n; i++) ans *= i;
    printf("%lld\n", ans);
}
int main() {
    int t = 1;
    // scanf("%d", &t);
    while (t--) solve();
}