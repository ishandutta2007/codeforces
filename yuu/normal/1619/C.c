#include <stdint.h>
#include <stdio.h>

int64_t a, s;
int n, m;
int d_a[30];
int d_s[30];
int trace[31][31];

void solve() {
    scanf("%lld %lld\n", &a, &s);
    m = 0;
    while (s > 0) {
        d_s[m++] = s % 10;
        s /= 10;
    }
    n = 0;
    while (n < m) {
        d_a[n++] = a % 10;
        a /= 10;
    }

    for (int64_t i = m; i < 30; i++) d_s[i] = 0;
    for (int64_t i = n; i < 30; i++) d_a[i] = 0;

    for (int i = 0; i <= 30; i++)
        for (int j = 0; j <= 30; j++) trace[i][j] = -1;
    trace[0][0] = 0;
    for (int i = 0; i < 30; i++)
        for (int j = 0; j < 30; j++)
            if (trace[i][j] != -1) {
                if (d_a[i] <= d_s[j]) {
                    trace[i + 1][j + 1] = j;
                } else if (j + 1 < 30) {
                    int digit = d_s[j + 1] * 10 + d_s[j] - d_a[i];
                    if ((0 <= digit) && (digit <= 9)) {
                        trace[i + 1][j + 2] = j;
                    }
                }
            }
    for (int i = n; i <= 30; i++) {
        for (int j = m; j <= 30; j++) {
            if (trace[i][j] != -1) {
                n = i;
                m = j;
                goto outside;
            }
        }
    }
outside:;
    if (trace[n][m] == -1) {
        printf("-1\n");
        return;
    }
    int64_t ans = 0;
    while (n > 0) {
        ans *= 10;
        if (trace[n][m] == m - 1) {
            ans += d_s[m - 1] - d_a[n - 1];
            m--;
        } else {
            ans += d_s[m - 1] * 10 + d_s[m - 2] - d_a[n - 1];
            m -= 2;
        }
        n--;
    }
    printf("%lld\n", ans);
}

int main() {
    int t = 1;
    scanf("%d\n", &t);
    while (t--) solve();
}