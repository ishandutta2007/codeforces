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
    int a;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a);
        printf("%d ", a - (a % 2 == 0));
    }
}

int main() {
    int t = 1;
    // scanf("%d", &t);
    while (t--) solve();
}