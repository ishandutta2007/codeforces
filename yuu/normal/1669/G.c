#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n, m;
char c[52][52];
void solve() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%s", &c[i][1]);
    }
    for (int i = 1; i <= m; i++) c[n + 1][i] = 'o';
    for (int j = 1; j <= m; j++) {
        for (int i = 1, last = 0; i <= n + 1; i++) {
            if (c[i][j] == 'o') {
                int cnt = 0;
                for (int k = last + 1; k < i; k++) {
                    if (c[k][j] == '*') {
                        cnt++;
                        c[k][j] = '.';
                    }
                }
                for (int k = 1; k <= cnt; k++) c[i - k][j] = '*';
                last = i;
            }
        }
    }
    for (int i = 1; i <= n; i++) printf("%s\n", &c[i][1]);
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}