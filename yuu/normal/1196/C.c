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
    int low_x = -1e5, high_x = 1e5, low_y = -1e5, high_y = 1e5;
    for (int i = 1, x, y, f; i <= n; i++) {
        scanf("%d %d", &x, &y);
        scanf("%d", &f);
        if ((f == 0) && (low_x < x)) low_x = x;
        scanf("%d", &f);
        if ((f == 0) && (high_y > y)) high_y = y;
        scanf("%d", &f);
        if ((f == 0) && (high_x > x)) high_x = x;
        scanf("%d", &f);
        if ((f == 0) && (low_y < y)) low_y = y;
    }
    if ((low_x > high_x) || (low_y > high_y)) {
        printf("%d\n", 0);
        return;
    } else {
        printf("%d %d %d\n", 1, low_x, low_y);
    }
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}