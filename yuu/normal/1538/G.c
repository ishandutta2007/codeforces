#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int64_t x, y, a, b;

bool check(int64_t n) {
    // a*p + b*(n-p) <= x
    // b*p + a*(n-p) <= y
    // (b-a) * p >= b * n - x;
    // (b-a) * p <= y - a * n;
    int64_t lower_bound = b * n - x;
    int64_t upper_bound = y - a * n;
    if (lower_bound > upper_bound) return false;
    lower_bound /= (b - a);
    upper_bound /= (b - a);
    while (lower_bound * (b - a) > b * n - x) lower_bound--;
    while (lower_bound * (b - a) < b * n - x) lower_bound++;
    while (upper_bound * (b - a) < y - a * n) upper_bound++;
    while (upper_bound * (b - a) > y - a * n) upper_bound--;
    if (lower_bound < 0) lower_bound = 0;
    if (upper_bound > n) upper_bound = n;
    return lower_bound <= upper_bound;
}

void solve() {
    scanf("%lld %lld %lld %lld", &x, &y, &a, &b);
    if (a == b) {
        if (x > y) {
            x ^= y;
            y ^= x;
            x ^= y;
        }
        printf("%lld\n", x / a);
        return;
    }
    if (a > b) {
        a ^= b;
        b ^= a;
        a ^= b;
        x ^= y;
        y ^= x;
        x ^= y;
    }
    int low = 1, high = 1e9, mid, ans = 0;
    while (low <= high) {
        mid = (low + high) / 2;
        if (check(mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    printf("%d\n", ans);
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}