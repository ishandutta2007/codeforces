#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n, k;
int p[101];
void solve() {
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%d", &p[i]);
    int ans = 0;
    for (int i = 1; i <= k; i++) ans += (p[i] > k);
    printf("%d\n", ans);
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}