#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

void solve() {
    int64_t w, h, n, t = 1;
    scanf("%lld %lld %lld", &w, &h, &n);
    while (w % 2 == 0) {
        w /= 2;
        t *= 2;
    }
    while (h % 2 == 0) {
        h /= 2;
        t *= 2;
    }
    if (t >= n) printf("YES\n");
    else printf("NO\n");
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}