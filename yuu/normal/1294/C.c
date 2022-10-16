#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int64_t d[1001];

void solve() {
    int64_t n;
    scanf("%lld", &n);
    int cnt = 0;
    for (int64_t b = 2; b * b <= n; b++) {
        if (n % b == 0) {
            int64_t m = n / b;
            for (int j = 0; j < cnt; j++) {
                int64_t a = d[j];
                int64_t c = m / a;
                if (c <= b) break;
                if (a * b * c == n) {
                    printf("YES\n%lld %lld %lld\n", a, b, c);
                    return;
                }
            }
            d[cnt++] = b;
        }
    }
    puts("NO");
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}