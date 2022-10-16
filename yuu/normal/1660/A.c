#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void solve() {
    int a, b;
    scanf("%d %d", &a, &b);
    if (a == 0) {
        printf("1\n");
        return;
    } else {
        printf("%d\n", a + b * 2 + 1);
    }
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}