#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int gcd(int a, int b) {
    while (b) {
        a %= b;
        a ^= b;
        b ^= a;
        a ^= b;
    }
    return a;
}

int n;
int a[40];

void solve() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    int mi = a[0];
    for (int i = 0; i < n; i++)
        if (a[i] < mi) mi = a[i];
    for (int i = 0; i < n; i++) a[i] -= mi;
    int ans = 0;
    for (int i = 0; i < n; i++) ans = gcd(ans, a[i]);
    if (ans == 0) ans = -1;
    printf("%d\n", ans);
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}