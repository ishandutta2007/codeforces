#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n;
int a[101];
void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    int ans = 0;
    if (a[1] != a[2]) {
        ans = a[1] ^ a[2] ^ a[3];
    } else {
        for (int i = 2; i <= n; i++)
            if (a[i] != a[1]) ans = a[i];
    }
    for (int i = 1; i <= n; i++)
        if (a[i] == ans) {
            printf("%d\n", i);
            return;
        }
    assert(false);
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}