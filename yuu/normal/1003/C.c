#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n, k;
int a[5001];
void solve() {
    scanf("%d %d", &n, &k);
    double ans = 0;
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) {
        double sum = 0;
        for (int j = i; j <= n; j++) {
            sum += a[j];
            if (j - i + 1 < k) continue;
            double average = sum / (j - i + 1);
            if (ans < average) ans = average;
        }
    }
    printf("%.9f\n", ans);
}

int main() {
    int t = 1;
    // scanf("%d", &t);
    while (t--) solve();
}