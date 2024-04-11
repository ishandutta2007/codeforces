#include <cstdio>
#include <algorithm>
#include <cassert>
using namespace std;

typedef long long llong;

llong gcd(llong a, llong b) {
    while (b > 0) {
        a %= b;
        swap(a, b);
    }
    return a;
}

void solve() {
    llong x, y, p, q;
    scanf("%lld %lld %lld %lld", &x, &y, &p, &q);
    y -= x;
    q -= p;
    long long ans = -1;
    if (p == 0) {
        assert(q != 0);
        if (x != 0) {
            ans = -1;
        } else {
            ans = 0;
        }
    } else if (q == 0) {
        assert(p != 0);
        if (y != 0) {
            ans = -1;
        } else {
            ans = 0;
        }
    } else {
        llong g = gcd(p, q);
        p /= g;
        q /= g;
        assert(p != 0 && q != 0);
        llong k = max((x + p - 1) / p, (y + q - 1) / q);
        ans = k * p - x + k * q - y;
    }
    printf("%lld\n", ans);
}

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        solve();
    }
}