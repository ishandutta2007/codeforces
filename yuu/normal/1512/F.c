#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n;
int64_t c;
int a[200001];
int b[200001];
void solve() {
    scanf("%d %lld", &n, &c);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i < n; i++) scanf("%d", &b[i]);
    int64_t min_day = 1e9 + 7;
    int64_t day = 0, money = 0;
    for (int i = 1; i <= n; i++) {
        int64_t day_to_buy = (c - money - 1) / a[i] + 1;
        if (day_to_buy < 0) break;
        if (min_day > day + day_to_buy) min_day = day + day_to_buy;
        if (i == n) break;
        if (money < b[i])
            day_to_buy = (b[i] - money - 1) / a[i] + 1;
        else
            day_to_buy = 0;
        money += day_to_buy * a[i] - b[i];
        day += day_to_buy + 1;
    }
    printf("%lld\n", min_day);
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}