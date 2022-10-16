#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int64_t n;

int get_min(int last_digit) {
    int64_t val = n;
    int ans = 0;
    while ((val > 0) && (val % 10 != last_digit)) {
        val /= 10;
        ans++;
    }
    val /= 10;
    if (val == 0) return 1e9;
    if (last_digit == 0) {
        while ((val > 0) && (val % 10 != 0) && (val % 10 != 5)) {
            val /= 10;
            ans++;
        }
        if (val == 0)
            return 1e9;
        else
            return ans;
    } else {
        while ((val > 0) && (val % 10 != 2) && (val % 10 != 7)) {
            val /= 10;
            ans++;
        }
        if (val == 0)
            return 1e9;
        else
            return ans;
    }
}

void solve() {
    scanf("%lld", &n);
    int ans = get_min(0);
    int ans_5 = get_min(5);
    if (ans > ans_5) ans = ans_5;
    printf("%d\n", ans);
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}