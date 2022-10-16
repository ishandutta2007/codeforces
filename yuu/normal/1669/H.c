#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n, k;
int a[200001];
void solve() {
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    int ans = 0;
    for (int j = 30; j >= 0; j--) {
        ans *= 2;
        int cost = 0;
        for (int i = 1; i <= n; i++) cost += 1 - ((a[i] >> j) & 1);
        if (cost <= k) {
            ans++;
            k -= cost;
        }
    }
    printf("%d\n", ans);
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}