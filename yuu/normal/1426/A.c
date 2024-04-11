#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void solve() {
    int n, x;
    scanf("%d %d", &n, &x);
    for (int level = 1, total = 0;; level++) {
        if (level == 1) total += 2;
        else total += x;
        if (total >= n) {
            printf("%d\n", level);
            return;
        }
    }
}
int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}