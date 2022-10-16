#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char s[200001];
char t[200001];
void solve() {
    scanf("%s %s", s, t);
    int n = strlen(s);
    int m = strlen(t);
    while ((n > 0) && (m > 0)) {
        if (s[n - 1] == t[m - 1]) {
            n--;
            m--;
        } else {
            break;
        }
    }
    printf("%d\n", n + m);
}

int main() {
    int t = 1;
    // scanf("%d", &t);
    while (t--) solve();
}