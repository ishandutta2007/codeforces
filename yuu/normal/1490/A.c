#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
int n;
int a[51];
int add(int x, int y) {
    if (x > y) {
        x ^= y;
        y ^= x;
        x ^= y;
    }
    int ans = 0;
    while (x * 2 < y) {
        x *= 2;
        ans++;
    }
    return ans;
}
void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    int ans = 0;
    for (int i = 1; i < n; i++) ans += add(a[i], a[i + 1]);
    printf("%d\n", ans);
}
int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}