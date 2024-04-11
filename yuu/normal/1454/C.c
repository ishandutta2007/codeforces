#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n;
int a[200001];
int cnt[200001];
void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) cnt[i] = 0;
    int total = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] != a[i - 1]) {
            cnt[a[i]]++;
        }
    }
    int ans = 1e9;
    for (int i = 1; i <= n; i++) {
        if (cnt[i]) {
            int cost = cnt[i] - 1;
            if (a[1] != i) cost++;
            if (a[n] != i) cost++;
            if (ans > cost) ans = cost;
        }
    }
    printf("%d\n", ans);
}
int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}