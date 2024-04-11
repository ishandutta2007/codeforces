#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e6 + 10;

int n, r1, r2, r3, d, a[N];

ll ans, f[N][2];

int main() {
    scanf("%d%d%d%d%d", &n, &r1, &r2, &r3, &d);

    memset(f, 0x3f, sizeof(f));
    f[0][0] = 0;

    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        ll v1 = 1ll*a[i]*r1 + r3;
        ll v2 = min(1ll*(a[i] + 2)*r1, 1ll*r2 + r1);
        f[i][0] = min(f[i][0], min(f[i - 1][0], f[i - 1][1] - d*(i == n)) + v1 + d);
        f[i][0] = min(f[i][0], f[i - 1][1] + v2 + d);
        f[i][1] = min(f[i - 1][0], f[i - 1][1]) + min(v1, v2) + 3ll*d;
    }

    printf("%lld\n", min(f[n][0], f[n][1]) - d);
}