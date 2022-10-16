#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int64_t n;
void solve() {
    scanf("%lld", &n);
    int ans = 0;
    for (int i = 1; i <= 9; i++) {
        int64_t j = i;
        while (j <= n) {
            ans++;
            j *= 10;
            j += i;
        }
    }
    printf("%d\n", ans);
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}