#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n;
char s[3];
int cnt[256][256];

void solve() {
    scanf("%d", &n);
    for (int i = 'a'; i <= 'k'; i++)
        for (int j = 'a'; j <= 'k'; j++) cnt[i][j] = 0;
    int64_t ans = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%s", &s);
        for (int c = 'a'; c <= 'k'; c++) {
            if (c != s[0]) ans += cnt[c][s[1]];
            if (c != s[1]) ans += cnt[s[0]][c];
        }
        cnt[s[0]][s[1]]++;
    }
    printf("%lld\n", ans);
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}