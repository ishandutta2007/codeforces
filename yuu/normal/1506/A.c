#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void solve() {
    int64_t n, m, x;
    scanf("%lld %lld %lld", &n, &m, &x);
    int64_t col = (x - 1) / n + 1;
    int64_t row = (x - 1) % n + 1;
    printf("%lld\n", (row - 1) * m + col);
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}