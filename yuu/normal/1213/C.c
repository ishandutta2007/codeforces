#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void solve() {
    int64_t n, m;
    scanf("%lld %lld", &n, &m);
    int64_t ans = 0;
    for (int64_t i = 1; i <= 9; i++) {
        // (10 * x + i) * m
        int64_t count = n / m;
        count = (count / 10) + ((count % 10) >= i);
        // printf("%d %lld\n", i, count);
        ans += count * ((m * i) % 10);
    }
    printf("%lld\n", ans);
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}