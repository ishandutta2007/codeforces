#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e5 + 10, mod = 998244353;

int n, m, a[N], b[N], fac[N], inv[N], c[N], ans, lim = 2e5 + 1;

int fpow_(int a, int b, int res = 1) {
    for (; b; b >>= 1, a = 1ll*a*a%mod) {
        if (b&1) {
            res = 1ll*res*a%mod;
        }
    }

    return res;
}

int f[N<<2], s[N<<2];

void up_(int o) {
    s[o] = s[o<<1] + s[o<<1|1];
    f[o] = 1ll*f[o<<1]*f[o<<1|1]%mod;
}

void build_(int o, int l, int r) {
    if (l == r) {
        f[o] = inv[a[l]];
        s[o] = a[l];
        return;
    }

    int mid = (l + r)>>1;
    build_(o<<1, l, mid);
    build_(o<<1|1, mid + 1, r);
    up_(o);
}

int qf_(int o, int l, int r, int x, int y) {
    if (x <= l && r <= y) {
        return f[o];
    }

    int mid = (l + r)>>1, res = 1;

    if (x <= mid) {
        res = 1ll*res*qf_(o<<1, l, mid, x, y)%mod;
    }

    if (mid < y) {
        res = 1ll*res*qf_(o<<1|1, mid + 1, r, x, y)%mod;
    }

    return res;
}

int qs_(int o, int l, int r, int x, int y) {
    if (x <= l && r <= y) {
        return s[o];
    }

    int mid = (l + r)>>1, res = 0;

    if (x <= mid) {
        res += qs_(o<<1, l, mid, x, y);
    }

    if (mid < y) {
        res += qs_(o<<1|1, mid + 1, r, x, y);
    }

    return res;
}

void upd_(int o, int l, int r, int x) {
    if (l == r) {
        f[o] = inv[a[l]];
        s[o] = a[l];
        return;
    }

    int mid = (l + r)>>1;

    if (x <= mid) {
        upd_(o<<1, l, mid, x);
    } else {
        upd_(o<<1|1, mid + 1, r, x);
    }

    up_(o);
}

int C_(int n, int k) {
    return n < k ? 0 : 1ll*fac[n]*inv[k]%mod*inv[n - k]%mod;
}

int main() {
    scanf("%d%d", &n, &m);
    fac[0] = 1;

    for (int x, i = 1; i <= n; i++) {
        scanf("%d", &x);
        a[x]++;
        fac[i] = 1ll*fac[i - 1]*i%mod;
    }

    inv[n] = fpow_(fac[n], mod - 2);

    for (int i = n; i; i--) {
        inv[i - 1] = 1ll*inv[i]*i%mod;
    }

    for (int i = 1; i <= m; i++) {
        scanf("%d", &b[i]);
        c[b[i]] += i <= n;
    }

    if (n < m) {
        bool ok = 1;

        for (int i = 1; i <= lim; i++) {
            if (a[i] > c[i]) {
                ok = 0;
                break;
            }
        }

        ans += ok;
    }

    build_(1, 0, lim);

    for (int i = 1; i <= min(n, m); i++) {
        int f1 = qf_(1, 0, lim, 0, b[i] - 1), f2 = qf_(1, 0, lim, b[i], lim);
        int s1 = qs_(1, 0, lim, 0, b[i] - 1), s2 = qs_(1, 0, lim, b[i], lim);

        if (s1 > 0) {
            ans = (ans + 1ll*f1*fac[s1]%mod*f2%mod*fac[s2]%mod*C_(s1 + s2 - 1, s1 - 1))%mod;
        }

        if (!a[b[i]]) {
            break;
        }

        a[b[i]]--;
        upd_(1, 0, lim, b[i]);
    }

    printf("%d\n", (ans%mod + mod)%mod);
}