#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n;
int64_t b[100001];

int64_t get(int d1, int d2) {
    int64_t res = 0;
    res += (d1 != 0);
    res += (d2 != 0);
    int64_t pro = (b[2] + d2) - (b[1] + d1);
    int64_t a = b[2] + d2;
    for (int i = 3; i <= n; i++) {
        a += pro;
        int64_t diff = b[i] - a;
        if (diff < 0) diff = -diff;
        if (diff > 1) return 1e9;
        if (diff == 1) res++;
    }
    return res;
}

void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%lld", &b[i]);
    if (n <= 2) {
        puts("0");
        return;
    }
    int64_t ans = 1e9;
    for (int i = -1; i <= 1; i++)
        for (int j = -1; j <= 1; j++) {
            int64_t res = get(i, j);
            if (ans > res) ans = res;
        }
    if (ans == 1e9) ans = -1;
    printf("%lld\n", ans);
}

int main() {
    int t = 1;
    // scanf("%d", &t);
    while (t--) solve();
}