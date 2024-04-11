#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n, k;
int cnt[200001][20];
void solve() {
    scanf("%d %d", &n, &k);
    for (int i = 1, a; i <= n; i++) {
        scanf("%d", &a);
        cnt[a][0]++;
    }
    int ans = 1e9;
    for (int i = 200000; i >= 0; i--) {
        int req = k;
        int res = 0;
        for (int cost = 0; cost < 20; cost++) {
            int d = req;
            if (d > cnt[i][cost]) d = cnt[i][cost];
            res += cost * d;
            req -= d;
            if (i && (cost < 19)) cnt[i / 2][cost + 1] += cnt[i][cost];
        }
        if (req == 0)
            if (ans > res) ans = res;
    }
    printf("%d\n", ans);
}

int main() {
    int t = 1;
    // scanf("%d", &t);
    while (t--) solve();
}