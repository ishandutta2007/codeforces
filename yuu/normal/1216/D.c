#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n;
int a[200001];

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    int mx = 0;
    for (int i = 1; i <= n; i++)
        if (a[i] > mx) mx = a[i];
    int z = 0;
    for (int i = 1; i <= n; i++) z = gcd(z, mx - a[i]);
    int64_t y = 0;
    for (int i=1; i<=n; i++) y += (mx - a[i])/z;
    printf("%lld %d\n", y, z);
}

int main() {
    int t = 1;
    // scanf("%d", &t);
    while (t--) solve();
}