#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
int n;
int a[301];
void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    int l = 1, r = n;
    while (l <= r) {
        printf("%d ", a[l]);
        l++;
        if (r >= l) printf("%d ", a[r]);
        r--;
    }
    printf("\n");
}
int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}