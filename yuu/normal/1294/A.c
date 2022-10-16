#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void solve() {
    int a, b, c, n;
    scanf("%d %d %d %d", &a, &b, &c, &n);
    n += a + b + c;
    if (n % 3) {
        puts("NO");
        return;
    }
    n /= 3;
    if ((a > n) || (b > n) || (c > n)) {
        puts("NO");
    } else {
        puts("YES");
    }
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}