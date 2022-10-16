#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// #define FOR_D1

int less(const void* A, const void* B) { return *((int*)A) - *((int*)B); }

int gcd(int a, int b) {
    while (b) {
        a %= b;
        a ^= b;
        b ^= a;
        a ^= b;
    }
    return a;
}

int n;
int a[40];
int b[40];

bool check(int x, int l, int r) {
    int cnt = 0;
    for (int i = l; i <= r; i++)
        if (b[i] % x == 0) {
            cnt++;
            if (cnt * 2 >= n) return true;
        }
    return false;
}

void solve() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    int mi = a[0];
    for (int i = 0; i < n; i++)
        if (a[i] < mi) mi = a[i];
    for (int i = 0; i < n; i++) a[i] -= mi;
    int ans = 1;
#ifdef FOR_D1
    for (int i = 0; i < n; i++) ans = gcd(ans, a[i]);
    if (ans == 1) ans = -1;
    printf("%d\n", ans);
    return;
#endif
    qsort(a, n, sizeof(int), less);
    for (int i = 0; i < n; i++) {
        int same = 0;
        for (int j = i; j < n; j++)
            if (a[j] == a[i]) same++;
        if (same * 2 >= n) {
            printf("-1\n");
            return;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + n / 2 - 1; j < n; j++) {
            int diff = a[j] - a[i];
            for (int k = i; k <= j; k++) b[k] = (a[k] - a[i]) % diff;
            int val = 1;
            while ((val * val <= diff) && (diff / val > ans)) {
                if (diff % val == 0) {
                    if (check(diff / val, i, j)) {
                        ans = diff / val;
                        goto next_j;
                    }
                }
                val++;
            }
            while (val > ans) {
                if (diff % val == 0) {
                    if (check(val, i, j)) {
                        ans = val;
                        goto next_j;
                    }
                }
                val--;
            }
        next_j:;
        }
    }
    printf("%d\n", ans);
    return;
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}