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
    while (k--) {
        if (n % 10) n--;
        else n /= 10;
    }
    printf("%d\n", n);
}

int main() {
    int t = 1;
    // scanf("%d", &t);
    while (t--) solve();
}