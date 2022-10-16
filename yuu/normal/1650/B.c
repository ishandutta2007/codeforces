#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int l, r, a;
void solve() {
    scanf("%d %d %d", &l, &r, &a);
    int ans = r / a + r % a;
    r -= r % a + 1;
    if (r >= l) {
        int temp = r / a + r % a;
        if (temp > ans) ans = temp;
    }
    printf("%d\n", ans);
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}