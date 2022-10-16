#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n;
int cnt[150003];
bool have[150003];
void solve() {
    scanf("%d", &n);
    for (int i = 1, a; i <= n; i++) {
        scanf("%d", &a);
        cnt[a]++;
    }
    int ans = 0;
    for (int i = 1; i <= 150001; i++) {
        if (!have[i]) {
            if (cnt[i]) {
                have[i] = 1;
                cnt[i]--;
            }
        }
        if (!have[i]) {
            if (cnt[i + 1]) {
                cnt[i + 1]--;
                have[i] = 1;
            }
        }
        if (cnt[i]) {
            have[i + 1] = 1;
            cnt[i]--;
        }
        if (have[i]) ans++;
    }
    printf("%d\n", ans);
}

int main() {
    int t = 1;
    // scanf("%d", &t);
    while (t--) solve();
}