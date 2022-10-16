#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void solve() {
    int64_t s, ans = 0;
    scanf("%lld", &s);
    while (s >= 10) {
        ans += (s / 10) * 10;
        s = s % 10 + (s / 10);
    }
    ans += s;
    printf("%lld\n", ans);
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}