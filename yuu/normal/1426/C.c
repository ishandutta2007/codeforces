#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void solve() {
    int64_t n;
    scanf("%lld", &n);
    int64_t ans = n;
    for (int64_t i = sqrtl(n) - 100; i <= ans; i++) {
        if (i < 0) {
            i = 0;
            continue;
        }
        if (ans > i - 1 + (n - 1) / i) ans = i - 1 + (n - 1) / i;
    }
    printf("%lld\n", ans);
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}