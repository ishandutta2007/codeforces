#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n, k;
int a[200001];
void solve() {
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        a[i] %= 2;
    }
    int total_mod = 0;
    for (int i = 1; i <= n; i++) total_mod += a[i];
    if ((total_mod < k) || ((total_mod - k) % 2)) {
        puts("NO");
        return;
    }
    puts("YES");
    for (int i = 1; (i < n) && (k > 1); i++) {
        if (a[i]) {
            printf("%d ", i);
            k--;
        }
    }
    printf("%d\n", n);
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}