#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

const int mod = 1e9 + 7;

void add(int &a, int b) {
    a += b;
    if (a >= mod)
        a -= mod;
}

int mul(ll a, ll b) {
    return (a * b) % mod;
}

struct M {
    int a[2][2];

    M() {
        forn (i, 2)
            forn (j, 2)
                a[i][j] = 0;
    }

    M operator*(const M &m) const {
        M res;
        forn (i, 2)
            forn (j, 2)
                forn (k, 2)
                    add(res.a[i][j], mul(a[i][k], m.a[k][j]));
        return res;
    }
};

M p;

M pw(ll deg) {
    M res, p2;
    forn (i, 2)
        forn (j, 2)
            p2.a[i][j] = p.a[i][j];
    res.a[0][0] = res.a[1][1] = 1;
    while (deg) {
        if (deg % 2)
            res = res * p2;
        deg /= 2;
        p2 = p2 * p2;
    }
    return res;
}

int pw2(int q, ll deg) {
    int c = q, res = 1;
    while (deg) {
        if (deg % 2)
            res = mul(res, c);
        c = mul(c, c);
        deg /= 2;
    }
    return res;
}

int main() {
    #ifdef LOCAL
    assert(freopen("c.in", "r", stdin));
    #else
    #endif
    p.a[0][0] = 0;
    p.a[0][1] = 1;
    p.a[1][0] = 2;
    p.a[1][1] = 1;

    M res;
    res.a[0][0] = res.a[1][1] = 1;
    int q = 2;
    int k;
    cin >> k;
    forn (i, k) {
        ll deg;
        scanf("%I64d", &deg);
        p = pw(deg);
        q = pw2(q, deg);
    }

    int pp = p.a[0][0];
    q = mul(q, (mod + 1) / 2);
    pp = mul(pp, (mod + 1) / 2);
    cout << pp << '/' << q << '\n';
}