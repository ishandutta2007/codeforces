#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char a[21];
char b[21];
int n, m;
void solve() {
    scanf("%s %s", &a, &b);
    n = strlen(a);
    m = strlen(b);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int same = ans + 1; (i + same <= n) && (j + same <= m); same++) {
                bool good = true;
                for (int k = 0; k < same; k++)
                    if (a[i + k] != b[j + k]) {
                        good = false;
                        break;
                    }
                if (good)
                    ans = same;
                else
                    break;
            }
        }
    }
    ans = n + m - ans * 2;
    printf("%d\n", ans);
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}