#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n;
int w[51];
int cnt[101];
int get(int s) {
    int res = 0;
    for (int i = 1; i * 2 < s; i++) {
        if (s - i > n) continue;
        res += (cnt[i] < cnt[s - i]) ? cnt[i] : cnt[s - i];
    }
    if (s % 2 == 0) res += cnt[s / 2] / 2;
    return res;
}
void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &w[i]);
    for (int i = 1; i <= n; i++) cnt[i] = 0;
    for (int i = 1; i <= n; i++) cnt[w[i]]++;
    int ans = 0;
    for (int s = 1; s <= n * 2; s++) {
        int res = get(s);
        if (ans < res) ans = res;
    }
    printf("%d\n", ans);
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}