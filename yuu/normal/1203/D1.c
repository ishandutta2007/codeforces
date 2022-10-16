#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n, m;
char s[200002];
char t[200002];
int l[200002];
int r[200002];
void solve() {
    scanf("%s", &s[1]);
    n = strlen(&s[1]);
    scanf("%s", &t[1]);
    m = strlen(&t[1]);
    for (int i = 1; i <= n; i++) {
        l[i] = l[i - 1];
        if ((l[i] < m) && (s[i] == t[l[i] + 1])) l[i]++;
    }
    r[n + 1] = m + 1;
    for (int i = n; i >= 1; i--) {
        r[i] = r[i + 1];
        if ((r[i] > 1) && (s[i] == t[r[i] - 1])) r[i]--;
    }
    int j = 1;
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        while ((j <= n) && (r[j + 1] <= l[i] + 1)) j++;
        if (ans < j - i - 1) ans = j - i - 1;
    }
    printf("%d\n", ans);
}

int main() {
    int t = 1;
    // scanf("%d", &t);
    while (t--) solve();
}