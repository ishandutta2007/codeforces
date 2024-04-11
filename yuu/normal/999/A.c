#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n, k;
int a[101];
void solve() {
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    int l = 1, r = n, ans = 0;
    while (l <= r) {
        if (a[l] <= k) {
            ans++;
            l++;
        } else if (a[r] <= k) {
            ans++;
            r--;
        } else {
            break;
        }
    }
    printf("%d\n", ans);
}

int main() {
    int t = 1;
    // scanf("%d", &t);
    while (t--) solve();
}