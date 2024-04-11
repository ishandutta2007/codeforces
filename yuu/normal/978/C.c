#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n, m;
int64_t a[200001];
void solve() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    int64_t b = 0;
    int d = 1;
    int64_t sum = 0;
    for (int i = 1; i <= m; i++) {
        scanf("%lld", &b);
        while (sum + a[d] < b) {
            sum += a[d];
            d++;
        }
        printf("%d %lld\n", d, b - sum);
    }
}

int main() {
    int t = 1;
    // scanf("%d", &t);
    while (t--) solve();
}