#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n;
int a[200001];
void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        if (a[i] % 2) a[i] += a[i] % 10;
    }
    if (n == 1) {
        puts("YES");
        return;
    }
    for (int i = 1; i < n; i++) {
        if (a[i] % 10 == 0) {
            if (a[i + 1] % 10) {
                puts("NO");
                return;
            }
        } else if (a[i + 1] % 10 == 0) {
            puts("NO");
            return;
        }
    }
    if (a[1] % 10 == 0) {
        for (int i = 1; i < n; i++) {
            if (a[i] != a[i + 1]) {
                puts("NO");
                return;
            }
        }
        puts("YES");
        return;
    }
    // 2 4 6 8
    for (int i = 1; i <= n; i++) {
        while (a[i] % 10 != 2) a[i] += a[i] % 10;
    }
    for (int i = 1; i < n; i++) {
        if ((a[i] - a[i + 1]) % 20) {
            puts("NO");
            return;
        }
    }
    puts("YES");
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}