#include <stdint.h>
#include <stdio.h>

int n;
void solve() {
    int64_t a[3];
    scanf("%lld %lld %lld", a, a + 1, a + 2);
    if ((a[1] * 2 - a[2] > 0) && ((a[1] * 2 - a[2]) % a[0] == 0)) {
        printf("YES\n");
        return;
    }
    if ((a[1] * 2 - a[0] > 0) && ((a[1] * 2 - a[0]) % a[2] == 0)) {
        printf("YES\n");
        return;
    }
    if ((a[0] + a[2]) % 2 == 0) {
        if ((a[0] + a[2] > 0) && (((a[0] + a[2]) / 2) % a[1] == 0)) {
            printf("YES\n");
            return;
        }
    }
    printf("NO\n");
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}