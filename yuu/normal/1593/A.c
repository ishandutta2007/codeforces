#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int solve_for(int a, int b, int c) {
    if ((a > b) && (a > c)) return 0;
    if (b > c)
        return b + 1 - a;
    else
        return c + 1 - a;
}

void solve() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    printf("%d %d %d\n", solve_for(a, b, c), solve_for(b, a, c), solve_for(c, a, b));
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}