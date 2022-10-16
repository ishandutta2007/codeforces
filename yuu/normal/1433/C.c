#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n;
int a[300001];
void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    int mx = 0;
    for (int i = 1; i <= n; i++)
        if (a[i] > mx) mx = a[i];
    for (int i = 1; i <= n; i++)
        if (a[i] == mx) {
            if ((i < n) && (a[i + 1] < a[i])) {
                printf("%d\n", i);
                return;
            }
            if ((i > 1) && (a[i - 1] < a[i])) {
                printf("%d\n", i);
                return;
            }
        }
    printf("-1\n");
}
int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}