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
    int x_max = 0, y_max = 0, x_min = 0, y_min = 0;
    for (int i = 1, x, y; i <= n; i++) {
        scanf("%d %d", &x, &y);
        if (x > x_max) x_max = x;
        if (x < x_min) x_min = x;
        if (y > y_max) y_max = y;
        if (y < y_min) y_min = y;
    }
    printf("%d\n", 2 * (x_max - x_min + y_max - y_min));
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}