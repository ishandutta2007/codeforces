#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void solve() {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", (b - a % b) % b);
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}