#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n;
int w[200001];
void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &w[i]);
    int j = n + 1;
    int ans = 0;
    int sum_l = 0;
    int sum_r = 0;
    for (int i = 1; i <= n; i++) {
        sum_l += w[i];
        while (sum_r < sum_l) {
            j--;
            sum_r += w[j];
        }
        if (j <= i) break;
        if (sum_l == sum_r) ans = i + (n - j + 1);
    }
    printf("%d\n", ans);
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}