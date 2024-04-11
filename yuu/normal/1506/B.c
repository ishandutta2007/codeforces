#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n, k;
char s[51];
int f[51];
void solve() {
    scanf("%d %d %s", &n, &k, &s);
    int ans = 1e9;
    for (int i = 0; i < n; i++) {
        if (s[i] != '*') continue;
        f[i] = 1e9;
        for (int j = i - 1; j >= 0; j--) {
            if (i - j > k) break;
            if (s[j] == '*') {
                if (f[i] > f[j] + 1) f[i] = f[j] + 1;
            }
        }
        if (f[i] == 1e9) f[i] = 1;
        ans = f[i];
    }
    printf("%d\n", ans);
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}