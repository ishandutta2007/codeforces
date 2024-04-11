#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void solve() {
    int n;
    scanf("%d", &n);
    int sum = 0, mask = 0;
    for (int i = 0, a; i < n; i++) {
        scanf("%d", &a);
        sum += a % 2;
        mask |= 1 << (a % 2);
    }
    if ((sum % 2) == 0) {
        if (mask != 3) {
            puts("NO");
            return;
        }
    }
    puts("YES");
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}