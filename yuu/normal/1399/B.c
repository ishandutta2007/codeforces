#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int a[51];
int ans[51];
void solve() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) ans[i] = 0;
    for (int ab = 0; ab < 2; ab++) {
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        int mi = 1e9;
        for (int i = 1; i <= n; i++)
            if (a[i] < mi) mi = a[i];
        for (int i = 1; i <= n; i++)
            if (ans[i] < a[i] - mi) ans[i] = a[i] - mi;
    }
    int64_t res = 0;
    for (int i = 1; i <= n; i++) res += ans[i];
    printf("%lld\n", res);
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}