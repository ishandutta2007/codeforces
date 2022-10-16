#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n;
char s[200001];
int f[3];
int g[3];
void solve() {
    scanf("%s", s);
    n = strlen(s);
    f[1] = f[2] = -1e9;
    f[0] = -1e9;
    f[s[0] % 3] = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 3; j++) g[j] = -1e9;
        // end the current number
        for (int j = 0; j < 3; j++)
            if (g[s[i] % 3] < f[j] + (j == 0)) g[s[i] % 3] = f[j] + (j == 0);
        // continue the current number
        for (int j = 0; j < 3; j++)
            if (g[(j + s[i]) % 3] < f[j]) g[(j + s[i]) % 3] = f[j];
        for (int j = 0; j < 3; j++) f[j] = g[j];
    }
    f[0]++;
    int ans = f[0];
    if (ans < f[1]) ans = f[1];
    if (ans < f[2]) ans = f[2];
    printf("%d\n", ans);
}

int main() {
    int t = 1;
    // scanf("%d", &t);
    while (t--) solve();
}