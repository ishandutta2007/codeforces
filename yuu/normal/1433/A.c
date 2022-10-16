#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void solve() {
    int x;
    scanf("%d", &x);
    int ans = 0;
    for (int d = 1; d <= 9; d++) {
        int val = 0;
        for (int digit = 1; digit <= 4; digit++) {
            val *= 10;
            val += d;
            ans += digit;
            if (val == x) break;
        }
        if (val == x) break;
    }
    printf("%d\n", ans);
}
int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}