#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
int n;
int cnt[3];
void solve() {
    scanf("%d", &n);
    cnt[0] = cnt[1] = cnt[2] = 0;
    for (int i = 1, a; i <= n; i++) {
        scanf("%d", &a);
        cnt[a % 3]++;
    }
    n /= 3;
    int ans = 0;
    while (true) {
        bool next = false;
        for (int i = 0; i < 3; i++) {
            if (cnt[i] > n) {
                next = true;
                ans += cnt[i] - n;
                cnt[(i + 1) % 3] += cnt[i] - n;
                cnt[i] = n;
            }
        }
        if (!next) break;
    }
    printf("%d\n", ans);
}
int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}