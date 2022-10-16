#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int a, n, m;
bool bad[2001];
int p[2001];
int best[2001];
int f[2001];
int g[2001];
void solve() {
    scanf("%d %d %d", &a, &n, &m);
    for (int i = 1, l, r; i <= n; i++) {
        scanf("%d %d", &l, &r);
        for (int j = l; j < r; j++) bad[j] = 1;
    }
    p[0] = 1e9;
    for (int i = 1, x; i <= m; i++) {
        scanf("%d %d", &x, &p[i]);
        if (p[i] < p[best[x]]) {
            best[x] = i;
            // printf("best[%d] = %d\n", x, i);
        }
        // printf("p[%d] = %d\n", i, p[i]);
    }
    for (int i = 0; i <= m; i++) f[i] = 1e9;
    f[best[0]] = 0;
    f[0] = 0;
    p[0] = 0;
    for (int x = 0; x < a; x++) {
        for (int i = 0; i <= m; i++) g[i] = 1e9;
        for (int i = bad[x]; i <= m; i++) {
            // printf("%d %d %d %d %d\n", x, i, f[i], p[i], g[i]);
            if (g[i] > f[i] + p[i]) {
                g[i] = f[i] + p[i];
                // printf("%d %d %d %d\n", x, i, f[i], g[i]);
            }
        }
        for (int i = 0; i <= m; i++) {
            if (g[0] > g[i]) g[0] = g[i];
            if (g[best[x + 1]] > g[i]) g[best[x + 1]] = g[i];
        }
        for (int i = 0; i <= m; i++) f[i] = g[i];
    }
    if (f[0] == 1e9) f[0] = -1;
    printf("%d\n", f[0]);
}

int main() {
    int t = 1;
    // scanf("%d", &t);
    while (t--) solve();
}