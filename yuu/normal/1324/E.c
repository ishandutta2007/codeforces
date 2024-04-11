#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n, h;
int a[2000];
int l, r;
int f[2000];
int g[2000];
bool good(int t) { return (l <= t) && (r >= t); }
void solve() {
    scanf("%d %d %d %d", &n, &h, &l, &r);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    for (int i = 0; i < h; i++) f[i] = -1e9;
    f[0] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < h; j++) g[j] = -1e9;
        for (int j = 0; j < h; j++)
            if (f[j] >= 0) {
                int t = (j + a[i]) % h;
                if (g[t] < f[j] + good(t)) g[t] = f[j] + good(t);
                t = (t + h - 1) % h;
                if (g[t] < f[j] + good(t)) g[t] = f[j] + good(t);
            }
        for (int j = 0; j < h; j++) f[j] = g[j];
    }
    int ans = 0;
    for (int i = 0; i < h; i++)
        if (f[i] > ans) ans = f[i];
    printf("%d\n", ans);
}

int main() {
    int t = 1;
    // scanf("%d", &t);
    while (t--) solve();
}