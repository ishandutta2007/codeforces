#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n, k;
char s[200001];
bool good[256];
void solve() {
    scanf("%d %d", &n, &k);
    scanf("%s", &s);
    for (int i = 1; i <= k; i++) {
        char c;
        while (true) {
            c = getchar();
            if (('a' <= c) && (c <= 'z')) break;
        }
        good[c] = 1;
    }
    int64_t ans = 0;
    for (int i = 0; i < n; i++) {
        if (!good[s[i]]) continue;
        int j = i;
        while ((j < n) && good[s[j]]) j++;
        int64_t cnt = j - i;
        ans += cnt * (cnt + 1) / 2;
        i = j;
    }
    printf("%lld\n", ans);
}

int main() {
    int t = 1;
    // scanf("%d", &t);
    while (t--) solve();
}