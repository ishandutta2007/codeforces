#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int n;
int64_t a[100];

int64_t gcd(int64_t a, int64_t b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

void solve() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
    for (int i = 0; i < 2; i++) {
        int64_t g = 0;
        for (int j = 0; j < n; j++)
            if (j % 2 == i) g = gcd(g, a[j]);
        bool good = true;
        for (int j = 0; j < n; j++)
            if (j % 2 != i)
                if (a[j] % g == 0) good = false;
        if (good) {
            printf("%lld\n", g);
            return;
        }
    }
    printf("0\n");
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}