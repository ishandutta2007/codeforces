#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n;
int a[200001];
int f[200001][2];
void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    f[1][0] = f[1][1] = 1;
    int ans = 1;
    for (int i = 2; i <= n; i++) {
        if (a[i] > a[i - 1]) {
            f[i][0] = f[i - 1][0] + 1;
            f[i][1] = f[i - 1][1] + 1;
        } else {
            f[i][0] = f[i][1] = 1;
        }
        if ((i > 1) && (a[i] > a[i - 2]))
            if (f[i - 2][0] + 1 > f[i][1]) f[i][1] = f[i - 2][0] + 1;
        if (ans < f[i][0]) ans = f[i][0];
        if (ans < f[i][1]) ans = f[i][1];
    }
    printf("%d\n", ans);
}

int main() {
    int t = 1;
    // scanf("%d", &t);
    while (t--) solve();
}