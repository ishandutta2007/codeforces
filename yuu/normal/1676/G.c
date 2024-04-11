#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n;
int a[4001];
int c[4001];
char s[4002];
void solve() {
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) scanf("%d", &a[i]);
    scanf("%s", &s[1]);
    int ans = 0;
    for (int i = 1; i <= n; i++) c[i] = 0;
    for (int i = n; i >= 1; i--) {
        if (s[i] == 'B') c[i]++;
        else c[i]--;
        c[a[i]] += c[i];
        ans += (c[i] == 0);
    }
    printf("%d\n", ans);
}
int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}