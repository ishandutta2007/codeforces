#include <stdint.h>
#include <stdio.h>

int64_t n;
void solve() {
    scanf("%lld\n", &n);
    int64_t ans = 0;
    for (int64_t i = 1; i * i <= n; i++) ans++;
    for (int64_t i = 1; i * i * i <= n; i++) ans++;
    for (int64_t i = 1; i * i * i * i * i * i <= n; i++) ans--;
    printf("%lld\n", ans);
}

int main() {
    int t = 1;
    scanf("%d\n", &t);
    while (t--) solve();
}