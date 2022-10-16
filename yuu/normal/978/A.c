#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n;
int a[51];
void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++)
            if (a[j] == a[i]) {
                a[i] = 0;
                break;
            }
        if (a[i]) ans++;
    }
    printf("%d\n", ans);
    for (int i=1; i<=n; i++) if(a[i]) printf("%d ", a[i]);
}

int main() {
    int t = 1;
    // scanf("%d", &t);
    while (t--) solve();
}