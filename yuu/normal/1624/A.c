#include <stdio.h>
int n;
int a[51];
void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    int mx = a[1];
    int mi = a[1];
    for (int i = 2; i <= n; i++) {
        if (a[i] > mx) mx = a[i];
        if (a[i] < mi) mi = a[i];
    }
    printf("%d\n", mx - mi);
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}