#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void solve() {
    int n, w;
    scanf("%d %d", &n, &w);
    int sum = 0;
    int low = 0, high = w;
    for (int i = 1, a; i <= n; i++) {
        scanf("%d", &a);
        sum += a;
        if (high > w - sum) high = w - sum;
        if (low < -sum) low = -sum;
    }
    int ans = high - low + 1;
    if (ans < 0) ans = 0;
    printf("%d\n", ans);
}

int main() {
    int t = 1;
    // scanf("%d", &t);
    while (t--) solve();
}