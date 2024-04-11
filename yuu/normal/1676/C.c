#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int n, m;
char s[51][9];
void solve() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%s", &s[i][0]);
    int ans = 1e9;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int res = 0;
            for (int k = 0; k < m; k++) {
                res += abs(s[i][k] - s[j][k]);
            }
            if (ans > res) ans = res;
        }
    }
    printf("%d\n", ans);
}
int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}