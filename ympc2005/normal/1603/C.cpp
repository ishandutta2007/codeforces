#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10, mod = 998244353;

int T, n, a[N], b[N], c[N], ans, sum;

void init_() {
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
}

void work_() {
    ans = sum = 0;

    for (int i = 1; i <= n; i++) {
        b[i] = a[i], c[i] = 1;

        for (int j = i - 1; j; j--) {
            int x = a[j]/((a[j] + b[j + 1] - 1)/b[j + 1]), y = (a[j] + b[j + 1] - 1)/b[j + 1];

            if (x == b[j] && y == c[j]) {
                break;
            }

            sum = (sum - 1ll*(c[j] - 1)*j)%mod;
            b[j] = x, c[j] = y;
            sum = (sum + 1ll*(c[j] - 1)*j)%mod;
        }

        ans = (ans + sum)%mod;
    }

    printf("%d\n", (ans%mod + mod)%mod);
}

int main() {
    scanf("%d", &T);

    while (T--) {
        init_();
        work_();
    }

    return 0;
}