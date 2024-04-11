#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void solve() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) printf("%d ", i % n + 1);
    printf("\n");
}
int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}