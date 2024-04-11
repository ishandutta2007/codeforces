#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void solve() {
    int n, h, m;
    scanf("%d %d %d", &n, &h, &m);
    int s = h * 60 + m;
    int ans = 1e9;
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &h, &m);
        int a = h * 60 + m;
        a -= s;
        if (a < 0) a += 60 * 24;
        if (ans > a) ans = a;
    }
    printf("%d %d\n", ans / 60, ans % 60);
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}