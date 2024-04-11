#include <stdio.h>
int n;
int a[51];
int cnt[51];
void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    for (int i = 1; i <= n; i++) cnt[i] = 0;
    for (int i = 1; i <= n; i++) {
        while (a[i] > n) a[i] /= 2;
        cnt[a[i]]++;
    }
    for (int i = n; i >= 1; i--) {
        if (cnt[i] == 0) {
            printf("NO\n");
            return;
        }
        cnt[i / 2] += cnt[i] - 1;
    }
    printf("YES\n");
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}