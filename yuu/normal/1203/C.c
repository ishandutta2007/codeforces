#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n;
int64_t gcd(int64_t a, int64_t b) {
    if (a == 0) return b;
    if (b == 0) return a;
    return gcd(b, a % b);
}
void solve() {
    int64_t g = 0;
    scanf("%d", &n);
    int64_t a;
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a);
        g = gcd(g, a);
    }
    int ans = 0;
    for (int64_t i = 1; i * i <= g; i++) {
        if (g % i == 0) {
            ans++;
            ans += ((i * i) != g);
        }
    }
    printf("%d\n", ans);
}

int main() {
    int t = 1;
    // scanf("%d", &t);
    while (t--) solve();
}