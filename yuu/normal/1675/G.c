#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
int n, m;
int a[251];
int f[251][252][501];
void solve() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++)
            for (int k = 0; k <= m * 2; k++) f[i][j][k] = 1e9;
    }
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    f[n][0][m] = 0;
    for (int i = n; i >= 1; i--) {
        for (int min = 0; min <= m; min++) {
            for (int extra = 0; extra <= m * 2; extra++) {
                if (f[i][min][extra] < 1e9) {
                    if (f[i][min + 1][extra] > f[i][min][extra])
                        f[i][min + 1][extra] = f[i][min][extra];  // choose to increase min
                    // go from a[i] + (extra - m) -> min
                    int next_extra = a[i] + (extra - m) - min;
                    if ((next_extra < -m) || (next_extra > m)) continue;
                    int cost = next_extra;
                    if (cost < 0) cost = -cost;
                    next_extra += m;
                    if (f[i - 1][min][next_extra] > f[i][min][extra] + cost)
                        f[i - 1][min][next_extra] = f[i][min][extra] + cost;
                }
            }
        }
    }
    int ans = 1e9;
    for (int min = 0; min <= m; min++)
        if (ans > f[0][min][m]) ans = f[0][min][m];
    printf("%d\n", ans);
}

int main() {
    int t = 1;
    // scanf("%d", &t);
    while (t--) solve();
}