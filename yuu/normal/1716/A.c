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
    if (n % 3 == 0) {
        printf("%d\n", n / 3);
    } else if (n % 3 == 1) {
        if (n == 1) printf("%d\n", 2);
        else printf("%d\n", (n - 4) / 3 + 2);
    } else if (n % 3 == 2) {
        printf("%d\n", n / 3 + 1);
    }
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}