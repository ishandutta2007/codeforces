#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n;
char s[200002];

void solve() {
    scanf("%s", s + 1);
    n = strlen(s + 1);
    s[0] = 'R';
    int old = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (s[i] == 'R') {
            if (ans < i - old) ans = i - old;
            old = i;
        }
    if (ans < n + 1 - old) ans = n + 1 - old;
    printf("%d\n", ans);
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}