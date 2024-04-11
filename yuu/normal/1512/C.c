#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int a, b, n;
char s[200002];
void solve() {
    scanf("%d %d", &a, &b);
    n = a + b;
    scanf("%s", &s[1]);
    if ((a % 2) && (b % 2)) {
        printf("-1\n");
        return;
    }
    if ((a % 2) && (s[n / 2 + 1] == '1')) {
        printf("-1\n");
        return;
    }
    if ((b % 2) && (s[n / 2 + 1] == '0')) {
        printf("-1\n");
        return;
    }
    if (a % 2)
        s[n / 2 + 1] = '0';
    else if (b % 2)
        s[n / 2 + 1] = '1';
    for (int i = 1; i <= n; i++) {
        if (s[i] == '?') s[i] = s[n - i + 1];
        if (s[i] == '0')
            a--;
        else if (s[i] == '1')
            b--;
    }
    for (int i = 1; i <= n; i++)
        if (s[i] != s[n - i + 1]) {
            printf("-1\n");
            return;
        }
    if ((a % 2) || (b % 2)) {
        printf("-1\n");
        return;
    }
    if ((a < 0) || (b < 0)) {
        printf("-1\n");
        return;
    }
    for (int i = 1; i <= n; i++)
        if (s[i] == '?') {
            if (a) {
                s[i] = s[n - i + 1] = '0';
                a -= 2;
            } else {
                s[i] = s[n - i + 1] = '1';
                b -= 2;
            }
        }
    assert((a == 0) && (b == 0));
    printf("%s\n", &s[1]);
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}