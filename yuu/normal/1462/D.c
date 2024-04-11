#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
int n;
int a[3001];
void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        a[i] += a[i - 1];
    }
    for (int i = 1; i <= n; i++) {
        if (a[n] % a[i] == 0) {
            int val = a[i];
            for (int j = i; j <= n; j++) {
                if (a[i] > val) {
                    val = 0;
                    break;
                }
                if (a[j] == val) val += a[i];
            }
            if (val == a[n] + a[i]) {
                printf("%d\n", n - a[n] / a[i]);
                return;
            }
        }
    }
}
int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}