#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n;
int a[51];
void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int pass = 1; pass <= n; pass++) {
        for (int j = 2; j <= n; j++)
            if (a[j - 1] > a[j]) {
                a[j] ^= a[j - 1];
                a[j - 1] ^= a[j];
                a[j] ^= a[j - 1];
            }
    }
    for (int i = 2; i <= n; i++)
        if (a[i] - a[i - 1] > 1) {
            printf("NO\n");
            return;
        }
    printf("YES\n");
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}