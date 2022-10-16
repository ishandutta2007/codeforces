#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

void solve() {
    int a, b, c, x, y;
    scanf("%d%d%d%d%d", &a, &b, &c, &x, &y);
    x -= a;
    y -= b;
    if (x > 0) c -= x;
    if (y > 0) c -= y;
    if (c >= 0) printf("YES\n");
    else printf("NO\n");
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}