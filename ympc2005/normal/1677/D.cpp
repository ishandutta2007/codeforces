#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10, mod = 998244353;

int T, n, m, a[N];

int main() {
    scanf("%d", &T);

    while (T--) {
        scanf("%d%d", &n, &m);

        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }

        int ans = 1;

        for (int i = 1; i <= m; i++) {
            ans = 1ll*ans*i%mod;
        }

        for (int i = m + 1; i <= n; i++) {
            if (a[i - m] == -1) {
                ans = 1ll*ans*i%mod;
            } else if (!a[i - m]) {
                ans = 1ll*ans*(m + 1)%mod;
            }
        }

        for (int i = 0; i < m; i++) {
            if (a[n - i] > 0) {
                ans = 0;
            }
        }

        printf("%d\n", (ans%mod + mod)%mod);
    }
}