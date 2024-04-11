#include <bits/stdc++.h>

// typedef long long ll;
typedef __int128 ll;

ll A, B, C, D;

ll comp(ll t) {
    ll k = std::min(C / D, t - 1);
    return -(k + 1) * k / 2 * B * D - (t - k - 1) * B * C + t * A;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        A = a; B = b; C = c; D = d;
        if (A > B * C) {
            puts("-1");
        } else {
            std::vector<ll> pos;
            pos.push_back(1);
            for (ll det = -2; det <= 2; ++det) {
                pos.push_back((2 * A + B * D) / (2 * B * D) + det);
                pos.push_back(C / D + 1 + det);
            }
            ll ans = 0;
            for (ll &x: pos) {
                if (x >= 1) ans = std::max(ans, comp(x));
            }
            printf("%lld\n", (long long) ans);
        }
    }
}