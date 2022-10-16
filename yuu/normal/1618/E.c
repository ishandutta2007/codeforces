#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int n;
int64_t b[40001];
int64_t a[40001];
void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%lld", &b[i]);
    if (n == 1) {
        printf("YES\n%lld\n", b[1]);
        return;
    }
    int64_t sum = 0;
    for (int i = 1; i <= n; i++) sum += b[i];
    sum *= 2;
    if (sum % n) {
        printf("NO\n");
        return;
    }
    sum /= n;
    if (sum % (n + 1)) {
        printf("NO\n");
        return;
    }
    sum /= (n + 1);
    b[0] = b[n];
    for (int i = n; i >= 1; i--) {
        a[i] = b[i - 1] - b[i] + sum;
        if ((a[i] <= 0) || a[i] % n) {
            printf("NO\n");
            return;
        }
        a[i] /= n;
    }
    printf("YES\n");
    for (int i = 1; i <= n; i++) printf("%lld ", a[i]);
    printf("\n");
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}