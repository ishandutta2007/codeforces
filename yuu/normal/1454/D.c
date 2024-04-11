#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int64_t n;
struct {
    int64_t p;
    int x;
} factor[100];
int factor_count;
void solve() {
    scanf("%lld", &n);
    factor_count = 0;
    for (int64_t i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            factor[factor_count].p = i;
            factor[factor_count].x = 0;
            while (n % i == 0) {
                factor[factor_count].x++;
                n /= i;
            }
            factor_count++;
        }
    }
    if (n > 1) {
        factor[factor_count].p = n;
        factor[factor_count].x = 1;
        factor_count++;
        n = 1;
    }
    int mx = 0;
    for (int i = 1; i < factor_count; i++)
        if (factor[i].x > factor[mx].x) {
            mx = i;
        }
    printf("%d\n", factor[mx].x);
    for (int i = 1; i < factor[mx].x; i++) {
        printf("%lld ", factor[mx].p);
    }
    n = factor[mx].p;
    for (int i = 0; i < factor_count; i++) {
        if (i == mx) continue;
        for (int j = 0; j < factor[i].x; j++) n *= factor[i].p;
    }
    printf("%lld\n", n);
}
int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}