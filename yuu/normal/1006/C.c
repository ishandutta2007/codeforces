#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n;
int64_t d[200001];
void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%lld", &d[i]);
    int64_t prefix = 0, suffix = 0, r = n + 1;
    int64_t ans = 0;
    for (int i = 1; i <= n; i++) {
        prefix += d[i];
        while ((r > 1) && (suffix < prefix)) {
            r--;
            suffix += d[r];
        }
        if (r <= i) break;
        if(suffix == prefix) ans = prefix;
    }
    printf("%lld\n", ans);
}

int main() {
    int t = 1;
    // scanf("%d", &t);
    while (t--) solve();
}