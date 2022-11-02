#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10, M = 3005, mod = 998244353;

int n, m, a[N], b[N], s[2], f[M][M], inv[M<<1], sum[2];

int fpow_(int a, int b, int res = 1) {
    for (; b; b >>= 1, a = 1ll*a*a%mod) {
        if (b&1) {
            res = 1ll*res*a%mod;
        }
    }

    return res;
}

int inv_(int k) {
    if (inv[k + m] == -1) {
        inv[k + m] = fpow_(k + s[0] + s[1], mod - 2);
    }

    return inv[k + m];
}

void add_(int &x, int y) {
    x = (x + y)%mod;
}

int main() {
    ios :: sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>m;
    memset(inv, -1, sizeof(inv));

    for (int i = 1; i <= n; i++) {
        cin>>a[i];
    }

    for (int i = 1; i <= n; i++) {
        cin>>b[i];
        s[a[i]] += b[i];
    }

    f[0][0] = 1;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j <= i; j++) {
            if (f[i][j]) {
                add_(f[i + 1][j + 1], 1ll*f[i][j]*inv_(j - (i - j))%mod*(j + s[1])%mod);
                add_(f[i + 1][j], 1ll*f[i][j]*inv_(j - (i - j))%mod*(s[0] - (i - j))%mod);
            }
        }
    }

    for (int i = 0; i <= m; i++) {
        if (f[m][i]) {
            add_(sum[0], 1ll*(s[0] - (m - i))*f[m][i]%mod);
            add_(sum[1], 1ll*(s[1] + i)*f[m][i]%mod);
        }
    }

    for (int i = 1; i <= n; i++) {
        cout<<(1ll*sum[a[i]]*fpow_(s[a[i]], mod - 2)%mod*b[i]%mod + mod)%mod<<'\n';
    }
}