#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n, m, k;
int f[70];
int d[70];
int g[36][70];
void solve() {
    scanf("%d %d %d", &n, &m, &k);
    int lim = m / 2;
    for (int i = 1; i < k; i++) f[i] = -1e9;
    f[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int x = 0; x <= lim; x++)
            for (int y = 0; y < k; y++) g[x][y] = -1e9;
        g[0][0] = 0;
        for (int j = 1, a; j <= m; j++) {
            scanf("%d", &a);
            for (int x = lim - 1; x >= 0; x--) {
                for (int y = 0; y < k; y++) {
                    if (g[x][y] < 0) continue;
                    int ny = (y + a) % k;
                    if (g[x + 1][ny] < g[x][y] + a) g[x + 1][ny] = g[x][y] + a;
                }
            }
        }
        for (int x = 0; x < lim; x++) {
            for (int y = 0; y < k; y++) {
                if (g[x][y] > g[x + 1][y]) g[x + 1][y] = g[x][y];
            }
        }
        for (int y = 0; y < k; y++) d[y] = -1e9;
        for (int x = 0; x < k; x++)
            for (int y = 0; y < k; y++)
                if (d[(x + y) % k] < f[x] + g[lim][y]) d[(x + y) % k] = f[x] + g[lim][y];

        for (int y = 0; y < k; y++) f[y] = d[y];
    }
    printf("%d\n", f[0]);
}
int main() {
    int t = 1;
    // scanf("%d", &t);
    while (t--) solve();
}