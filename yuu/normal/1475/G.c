#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
int n;
int cnt[200001];
int f[200001];
void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= 200000; i++) cnt[i] = 0;
    for (int i = 1; i <= 200000; i++) f[i] = 0;
    for (int i = 1, a; i <= n; i++) {
        scanf("%d", &a);
        cnt[a]++;
    }
    int ans = 0;
    for (int i = 1; i <= 200000; i++) {
        f[i] += cnt[i];
        if (f[i] > ans) ans = f[i];
        for (int j = i + i; j <= 200000; j += i)
            if (f[j] < f[i]) f[j] = f[i];
    }
    ans = n - ans;
    printf("%d\n", ans);
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}