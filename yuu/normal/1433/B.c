#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n;
int a[51];
void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    int cnt = 0;
    int low = 0, high = 0;
    for (int i = 1; i <= n; i++)
        if (a[i]) {
            cnt++;
            high = i;
            if (low == 0) low = i;
        }
    int ans = 1e9;
    for (int target = low; target + cnt - 1 <= high; target++) {
        int res = target - low;
        if (high > target + cnt - 1) res += high - (target + cnt - 1);
        if (ans > res) ans = res;
    }
    printf("%d\n", ans);
}
int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}