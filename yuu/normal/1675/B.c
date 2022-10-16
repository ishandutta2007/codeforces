#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
int n;
int a[31];
void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    int ans = 0;
    for (int i = n - 1; i >= 1; i--) {
        while ((a[i]) && (a[i] >= a[i + 1])) {
            a[i] /= 2;
            ans++;
        }
        if (a[i] >= a[i + 1]) {
            ans = -1;
            break;
        }
    }
    printf("%d\n", ans);
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}