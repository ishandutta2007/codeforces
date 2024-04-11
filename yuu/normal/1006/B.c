#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n, k, m;
int a[2001];
int b[2001];
void solve() {
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) b[i] = i;
    m = n;
    while (m > k) {
        int mi = 1;
        for (int i = 1; i <= m; i++)
            if (a[b[i]] < a[b[mi]]) mi = i;
        for (int i = mi; i < m; i++) b[i] = b[i + 1];
        m--;
    }
    int ans = 0;
    for (int i = 1; i <= k; i++) ans += a[b[i]];
    printf("%d\n", ans);
    for (int i = 1; i < k; i++) printf("%d ", b[i] - b[i - 1]);
    printf("%d\n", n - b[k - 1]);
}

int main() {
    int t = 1;
    // scanf("%d", &t);
    while (t--) solve();
}