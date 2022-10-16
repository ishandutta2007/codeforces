#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

uint64_t sum_natural(uint64_t l, uint64_t r) {
    // l + (l + 1) + ... + (l+r)
    uint64_t lim = 1e19 / (r + l);
    if (r - l + 1 > lim) return 1e18 + 1;
    return (r + l) * (r - l + 1) / 2;
}

uint64_t count_group(uint64_t k) {
    // how many digit are there if we write out all group from 1 to k
    uint64_t count = 0;
    for (uint64_t low_10 = 1, high_10 = 10, size = 1; low_10 <= k; low_10 *= 10, high_10 *= 10, size++) {
        if (high_10 > k + 1) high_10 = k + 1;
        count += size * sum_natural(k - (high_10 - 1) + 1, k - low_10 + 1);
        if (count > 1e18) return 1e18 + 1;
    }
    return count;
}

int get_digit_in_group(uint64_t k, uint64_t pos) {
    for (uint64_t low_10 = 1, high_10 = 10, size = 1; low_10 <= k; low_10 *= 10, high_10 *= 10, size++) {
        if (high_10 > k + 1) high_10 = k + 1;
        uint64_t total_count = (high_10 - low_10) * size;
        if (total_count < pos) {
            pos -= total_count;
            continue;
        }
        uint64_t whole = (pos - 1) / size;
        low_10 += whole;
        pos -= whole * size;
        for (int i = 1; i <= size - pos; i++) low_10 /= 10;
        return low_10 % 10;
    }
    assert(false);
}

int get_digit(uint64_t k) {
    // find out what group k is from first
    uint64_t low = 1, high = 1e10, mid, res;
    while (low <= high) {
        uint64_t mid = (low + high) / 2;
        if (count_group(mid) >= k) {
            res = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return get_digit_in_group(res, k - count_group(res - 1));
}

void solve() {
    uint64_t k;
    scanf("%lld", &k);
    printf("%d\n", get_digit(k));
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}