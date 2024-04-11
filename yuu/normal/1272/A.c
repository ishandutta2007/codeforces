#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void solve() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    int mi = a, mx = a;
    if (mi > b) mi = b;
    if (mi > c) mi = c;
    if (mx < b) mx = b;
    if (mx < c) mx = c;
    if (mx - mi >= 2) {
        printf("%d\n", (mx - mi - 2) * 2);
    } else {
        printf("0\n");
    }
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}