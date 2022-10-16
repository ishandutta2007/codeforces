#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int64_t x, y;
int n_0, n_1, m;
int s_0[100], s_1[100], t[100];

void build(int64_t value, int* buffer, int* size, bool keep_trailing_zero) {
    *size = 0;
    if (!keep_trailing_zero)
        while (value % 2 == 0) value /= 2;
    while (value > 0) {
        buffer[(*size)++] = value % 2;
        value /= 2;
    }
}

void reverse(int* a, int size) {
    for (int i = 0, j = size - 1; i < j; i++, j--) {
        a[i] ^= a[j];
        a[j] ^= a[i];
        a[i] ^= a[j];
    }
}

bool try_match(int* s, int n, int* t, int m) {
    for (int i = 0; i + n <= m; i++) {
        if (t[i] == 0) break;
        bool good = true;
        for (int j = 0; j < n; j++) {
            if (t[i + j] != s[j]) {
                good = false;
                break;
            }
        }
        if (!good) continue;
        for (int j = i + n; j < m; j++) {
            if (t[j] == 0) {
                good = false;
                break;
            }
        }
        if (good) return true;
    }
    return false;
}

void solve() {
    scanf("%lld %lld", &x, &y);
    if (x == y) {
        printf("YES\n");
        return;
    }
    build(x, s_0, &n_0, false);
    build(x * 2 + 1, s_1, &n_1, true);
    build(y, t, &m, true);
    if (try_match(s_0, n_0, t, m)) {
        printf("YES\n");
        return;
    }
    reverse(s_0, n_0);
    if (try_match(s_0, n_0, t, m)) {
        printf("YES\n");
        return;
    }

    if (try_match(s_1, n_1, t, m)) {
        printf("YES\n");
        return;
    }
    reverse(s_1, n_1);
    if (try_match(s_1, n_1, t, m)) {
        printf("YES\n");
        return;
    }

    printf("NO\n");
}

int main() {
    int t = 1;
    // scanf("%d", &t);
    while (t--) solve();
}