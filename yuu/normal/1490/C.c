#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

void solve() {
    int64_t x;
    scanf("%lld", &x);
    int64_t a = 1, b = 10000;
    while (a <= b) {
        int64_t res = a * a * a + b * b * b;
        if (res == x) {
            printf("YES\n");
            return;
        }
        if (res > x) b--;
        else a++;
    }
    printf("NO\n");
}
int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}