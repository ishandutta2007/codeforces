#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n;
char s[101];
int cnt[256][256];
void solve() {
    scanf("%d %s", &n, s);
    int ans = 0;
    for (int i = 1; i < n; i++) {
        cnt[s[i - 1]][s[i]]++;
        if (ans < cnt[s[i - 1]][s[i]]) ans = cnt[s[i - 1]][s[i]];
    }
    for (int i = 'A'; i <= 'Z'; i++)
        for (int j = 'A'; j <= 'Z'; j++)
            if (cnt[i][j] == ans) {
                putchar(i);
                putchar(j);
                return;
            }
}

int main() {
    int t = 1;
    // scanf("%d", &t);
    while (t--) solve();
}