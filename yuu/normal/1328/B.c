#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int64_t n, k;
int64_t C(int64_t n, int64_t k) {
    if (k == 1) return n;
    return n * (n - 1) / 2;
}
void solve() {
    scanf("%lld %lld", &n, &k);
    int rem = 2;
    for (int i = 1; i <= n; i++) {
        if (rem == 0) {
            putchar('a');
            continue;
        }
        if (n - i + 1 == rem) {
            putchar('b');
            continue;
        }
        if (C(n - i, rem) >= k) {
            putchar('a');
        } else {
            putchar('b');
            k -= C(n - i, rem);
            rem--;
        }
    }
    putchar('\n');
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}