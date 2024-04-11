#include <stdbool.h>
#include <stdio.h>

int n;
int a[200001];

void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    if (a[n] == n) {
        for (int i = n - 1; i >= 1; i--) printf("%d ", a[i]);
        printf("%d\n", a[n]);
        return;
    } else if (a[1] == n) {
        printf("%d", a[1]);
        for (int i = n; i >= 2; i--) printf(" %d", a[i]);
        printf("\n");
        return;
    } else {
        printf("-1\n");
        return;
    }
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}