#include <assert.h>
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
    for (int i = 3; i <= n; i++) {
        if ((a[i] + a[i - 2]) % 2) {
            printf("No\n");
            return;
        }
    }
    printf("Yes\n");
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}