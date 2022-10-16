#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int64_t get(int64_t a, int64_t b, int64_t c) {
    if (b > c) {
        b ^= c;
        c ^= b;
        b ^= c;
    }
    int64_t add = c - b;
    if (add > a) add = a;
    b += add;
    a -= add;
    b += a / 2;
    return b;
}

void solve() {
    int64_t a, b, c;
    scanf("%lld %lld %lld", &a, &b, &c);
    int64_t ans = 0;
    ans = get(a, b, c);
    int64_t res;
    res = get(b, a, c);
    if (ans < res) ans = res;
    res = get(c, a, b);
    if (ans < res) ans = res;
    printf("%lld\n", ans);
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}