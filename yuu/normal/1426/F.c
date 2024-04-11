#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n, q;
char s[200001];
#define base 1000000007
int64_t p[200001];
int64_t f[4];
void solve() {
    scanf("%d", &n);
    scanf("%s", &s);
    for (int i = 0; i < n; i++) q += (s[i] == '?');
    p[0] = 1;
    for (int i = 1; i <= q; i++) p[i] = (p[i - 1] * 3) % base;
    int ans = 0;
    f[0] = 1;
    for (int i = 0; i < n; i++) {
        if (s[i] != '?') {
            for (int j = 0; j < 3; j++) {
                if (s[i] == "abc"[j]) {
                    f[j + 1] = (f[j + 1] + f[j]) % base;
                }
            }
        } else {
            for (int j = 3; j >= 0; j--) {
                f[j] = (f[j] * 3) % base;
                if (j) f[j] = (f[j] + f[j - 1]) % base;
            }
        }
    }
    printf("%lld\n", f[3]);
}
int main() {
    int t = 1;
    // scanf("%d", &t);
    while (t--) solve();
}