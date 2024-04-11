#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n, k;
const int base = 998244353;
int ans[200001];
int f[200001];
int g[200001];
void solve() {
    scanf("%d %d", &n, &k);
    f[0] = 1;
    int sum = 0;
    for (int i = k; i <= n; i++) {
        sum += i;
        if (sum > n) break;
        for (int j = sum - i; j <= n; j++) g[j] = 0;
        for (int j = sum; j <= n; j++) {
            g[j] = f[j - i] + g[j - i];
            if (g[j] >= base) g[j] -= base;
        }
        for (int j = sum; j <= n; j++) f[j] = g[j];
        for (int j = sum; j <= n; j++) {
            ans[j] += f[j];
            if (ans[j] >= base) ans[j] -= base;
        }
    }
    for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
}

int main() {
    int t = 1;
    // scanf("%d", &t);
    while (t--) solve();
}