#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

char c[3];

void solve() {
    scanf("%s", &c);
    int ans = 0;
    for (int i = 0; i < 2; i++) {
        ans *= 26;
        ans += c[i] - 'a';
    }
    ans++;
    ans -= c[0] - 'a';
    ans -= (c[1] > c[0]);
    printf("%d\n", ans);
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}