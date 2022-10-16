#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

int n;
int a[101];

void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    int total = 0;
    int odd = 0;
    for (int i = 1; i <= n; i++) {
        total += a[i];
        if (a[i] == 1) odd++;
    }
    if (total % 2) {
        printf("NO\n");
    } else if ((total % 4 == 2) && (odd == 0)) {
        printf("NO\n");
    } else {
        printf("YES\n");
    }
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}