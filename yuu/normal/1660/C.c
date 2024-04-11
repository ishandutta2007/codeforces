#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char s[200001];
int n;
int f[27];
int g[27];
void solve() {
    scanf("%s", &s);
    n = strlen(s);
    for (int i = 0; i <= 26; i++) f[i] = 1e9;
    f[26] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= 26; j++) g[j] = 1e9;
        for (int j = 0; j <= 26; j++) {
            if (g[j] > f[j] + 1) g[j] = f[j] + 1;
        }
        if (g[s[i] - 'a'] > f[26]) g[s[i] - 'a'] = f[26];
        if (g[26] > f[s[i] - 'a']) g[26] = f[s[i] - 'a'];
        for (int j = 0; j <= 26; j++) f[j] = g[j];
    }
    printf("%d\n", f[26]);
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}