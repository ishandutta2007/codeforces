#include <stdio.h>
int n, k;
char c[200000];
int cnt[256];
void solve() {
    scanf("%d %d\n%s", &n, &k, c);
    for (int i = 'a'; i <= 'z'; i++) cnt[i] = 0;
    for (int i = 0; i < n; i++) cnt[c[i]]++;
    int pair = 0, odd = 0;
    for (int i = 'a'; i <= 'z'; i++) {
        pair += cnt[i] / 2;
        odd += cnt[i] % 2;
    }
    int ans = 0;
    int divided = pair / k;
    if (odd + 2 * (pair % k) >= k) {
        ans = divided * 2 + 1;
    } else {
        ans = divided * 2;
    }
    if (ans < 1) ans = 1;
    printf("%d\n", ans);
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}