#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
int n, m, k;
int a[200001];
int b[200001];
int ca[200001];
int cb[200001];
void solve() {
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= k; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= k; i++) scanf("%d", &b[i]);
    for (int i = 1; i <= n; i++) ca[i] = 0;
    for (int i = 1; i <= m; i++) cb[i] = 0;
    int64_t ans = 0;
    for (int i = 1; i <= k; i++) {
        ans += i - 1 - ca[a[i]] - cb[b[i]];
        ca[a[i]]++;
        cb[b[i]]++;
    }
    printf("%lld\n", ans);
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}