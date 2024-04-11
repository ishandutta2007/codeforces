#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void solve() {
    int n, m;
    int a[2][2];
    scanf("%d %d", &n, &m);
    bool good = false;
    for (int i = 1; i <= n; i++) {
        for (int x = 0; x < 2; x++)
            for (int y = 0; y < 2; y++) scanf("%d", &a[x][y]);
        if (a[0][1] == a[1][0]) good = true;
    }
    if (m % 2) good = false;
    if (good) printf("YES\n");
    else printf("NO\n");
}
int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}