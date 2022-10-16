#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n, k;
int h[100001];
int dp[5001];
int distribute(int have, int like) {
    if ((have == 0) || (like == 0)) return 0;
    if (have > like * k) return like * h[k];
    for (int i = 1; i <= have; i++) dp[i] = 0;
    for (int i = 1; i <= like; i++) {
        for (int j = have; j >= 1; j--) {
            for (int use = 1; use <= k; use++) {
                if (j < use) break;
                if (dp[j] < dp[j - use] + h[use]) dp[j] = dp[j - use] + h[use];
            }
        }
    }
    return dp[have];
}
int have[100001];
int like[100001];
void solve() {
    scanf("%d %d", &n, &k);
    for (int i = 1, c; i <= n * k; i++) {
        scanf("%d", &c);
        have[c]++;
    }
    for (int i = 1, f; i <= n; i++) {
        scanf("%d", &f);
        like[f]++;
    }
    for (int i = 1; i <= k; i++) scanf("%d", &h[i]);
    int ans = 0;
    for (int i = 1; i <= 100000; i++) ans += distribute(have[i], like[i]);
    printf("%d\n", ans);
}

int main() {
    int t = 1;
    // scanf("%d", &t);
    while (t--) solve();
}