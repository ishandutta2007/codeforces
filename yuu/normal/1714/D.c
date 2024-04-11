#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n;
char t[101];
int k;
int len[10];
char s[10][11];
int f[101];
int trace[101];
int prev[101];
void get_trace(int u) {
    if (u == 0) return;
    printf("%d %d\n", trace[u] + 1, prev[u] + 1);
    get_trace(prev[u]);
}
void solve() {
    scanf("%s", t);
    n = strlen(t);
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%s", &s[i]);
        len[i] = strlen(s[i]);
    }
    for (int i = 0; i <= n; i++) f[i] = 1e9;
    f[0] = 0;
    for (int i = 0; i < n; i++) {
        if (f[i] == 1e9) {
            puts("-1");
            return;
        }
        for (int match = 0; match < k; match++) {
            if (i + len[match] > n) continue;
            bool good = true;
            for (int j = 0; j < len[match]; j++) {
                if (t[i + j] != s[match][j]) {
                    good = false;
                    break;
                }
            }
            if (good) {
                for (int j = 1; j <= len[match]; j++) {
                    if (f[i + j] > f[i] + 1) {
                        f[i + j] = f[i] + 1;
                        trace[i + j] = match;
                        prev[i + j] = i;
                    }
                }
            }
        }
    }
    if (f[n] == 1e9) {
        puts("-1");
        return;
    }
    printf("%d\n", f[n]);
    get_trace(n);
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}