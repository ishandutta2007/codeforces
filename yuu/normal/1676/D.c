#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n, m;
int a[201][201];
int x[501];
int y[501];
void solve() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) scanf("%d", &a[i][j]);
    for (int i = 1 + 1; i <= n + m; i++) x[i] = 0;
    for (int i = 1 - m; i <= n - 1; i++) y[i + m] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            x[i + j] += a[i][j];
            y[i - j + m] += a[i][j];
        }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            int res = x[i + j] + y[i - j + m] - a[i][j];
            if (ans < res) ans = res;
        }
    printf("%d\n", ans);
}
int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}