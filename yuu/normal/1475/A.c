#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

void solve() {
    int64_t n;
    scanf("%lld", &n);
    while (n % 2 == 0) {
        n /= 2;
    }
    if (n > 1) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}