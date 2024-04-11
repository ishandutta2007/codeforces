#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void solve() {
    int n, k;
    scanf("%d %d", &n, &k);
    int a = n / k;

    n %= k;
    if (n > k / 2) n = k / 2;
    printf("%d\n", a * k + n);
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}