#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n;
int a[200001];
int ft[200001];
void update(int u, int x) {
    for (; u <= n; u += (u & -u)) ft[u] += x;
}
int get(int u) {
    int res = 0;
    for (; u > 0; u -= (u & -u)) res += ft[u];
    return res;
}

void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) ft[i] = 0;
    int64_t ans = 0;
    for (int i = n; i >= 1; i--) {
        ans += get(a[i]);
        update(a[i], 1);
    }
    printf("%lld\n", ans);
}
int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}