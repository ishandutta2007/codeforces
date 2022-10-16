#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n;
char s[200001];
void solve() {
    scanf("%d %s", &n, s);
    int ans = 0;
    for (int i = 0; i < n; i += 2) {
        if (s[i] == s[i + 1]) {
            ans++;
            s[i] ^= 'a' ^ 'b';
        }
    }
    printf("%d\n%s", ans, s);
}

int main() {
    int t = 1;
    // scanf("%d", &t);
    while (t--) solve();
}