#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void solve() {
    int a, b;
    scanf("%d %d", &a, &b);
    int ans = 0;
    if (a > b) {
        ans = 1 + (a - b) % 2;
    } else if (a < b) {
        ans = 1 + (b - a + 1) % 2;
    }
    printf("%d\n", ans);
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}