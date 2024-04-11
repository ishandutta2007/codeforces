#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
int n;
int a[101];
int ans[101];

void assign(int l, int r, int value) {
    if (l > r) return;
    int mx = l;
    for (int i = l + 1; i <= r; i++)
        if (a[i] > a[mx]) mx = i;
    ans[mx] = value;
    assign(l, mx - 1, value + 1);
    assign(mx + 1, r, value + 1);
}

void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    assign(1, n, 0);
    for (int i = 1; i <= n; i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");
}
int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}