#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n;

void solve() {
    scanf("%d", &n);
    if (n == 2) {
        printf("-1\n");
        return;
    }
    int value = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%d ", value);
            value += 2;
            if (value > n * n) value = 2;
        }
        printf("\n");
    }
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}