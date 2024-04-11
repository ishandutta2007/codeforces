#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n;
int a[100];
void solve() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    int mi = 0, mx = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] < a[mi]) mi = i;
        if (a[i] > a[mx]) mx = i;
    }
    if (mi > mx) {
        mi ^= mx;
        mx ^= mi;
        mi ^= mx;
    }
    int ans = mx + 1;
    if (ans > n - mi) ans = n - mi;
    if (ans > mi + 1 + n - mx) ans = mi + 1 + n - mx;
    printf("%d\n", ans);
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}