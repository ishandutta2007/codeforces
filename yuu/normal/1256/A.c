#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void solve() {
    int64_t a, b, n, s;
    scanf("%lld %lld %lld %lld", &a, &b, &n, &s);
    if (b < s % n) {
        puts("NO");
        return;
    }
    b -= s % n;
    s -= s % n;
    a += b / n;
    if (s / n > a) puts("NO");
    else puts("YES");
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}