#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n;
int a[200000];
void solve() {
    scanf("%d", &n);
    int64_t sum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    if (sum % n) {
        printf("-1\n");
        return;
    }
    sum /= n;
    int ans = 0;
    for (int i = 0; i < n; i++) ans += (a[i] > sum);
    printf("%d\n", ans);
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}