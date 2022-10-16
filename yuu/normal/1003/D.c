#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n, q;
int cnt[31];
int f[31];
int need[31];
void solve() {
    scanf("%d %d", &n, &q);
    for (int i = 1, a; i <= n; i++) {
        scanf("%d", &a);
        cnt[__builtin_ctz(a)]++;
    }
    for (int i = 1, b; i <= q; i++) {
        for (int j = 0; j <= 30; j++) f[j] = cnt[j];
        for (int j = 0; j <= 30; j++) need[j] = 0;
        scanf("%d", &b);
        int ans = 0;
        while (b > 0) {
            int c = __builtin_ctz(b);
            need[c] = 1;
            b -= (1 << c);
        }
        for (int j = 30; j >= 0; j--) {
            int used = need[j];
            if (used == 0) continue;
            if (used > f[j]) used = f[j];
            ans += used;
            need[j] -= used;
            if (j > 0) {
                need[j - 1] += need[j] * 2;
                need[j] = 0;
            }
        }
        if (need[0]) ans = -1;
        printf("%d\n", ans);
    }
}

int main() {
    int t = 1;
    // scanf("%d", &t);
    while (t--) solve();
}