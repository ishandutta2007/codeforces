#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
int n;
int a[200001];
void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = n % 2 + 1; i <= n; i += 2) {
        if (a[i] > a[i + 1]) {
            a[i] ^= a[i + 1];
            a[i + 1] ^= a[i];
            a[i] ^= a[i + 1];
        }
        if (a[i] < a[i - 1]) {
            printf("NO\n");
            return;
        }
    }
    printf("YES\n");
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}