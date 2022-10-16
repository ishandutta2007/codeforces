#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n;
char s[101];
void solve() {
    scanf("%d", &n);
    scanf("%s", s);
    int ans = 0, acc = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'x') {
            acc++;
            if (acc >= 3) ans++;
        } else {
            acc = 0;
        }
    }
    printf("%d\n", ans);
}

int main() {
    int t = 1;
    // scanf("%d", &t);
    while (t--) solve();
}