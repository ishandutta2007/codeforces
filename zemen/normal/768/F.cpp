#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

int f, w, h;

const int maxn = 300100;
int fact[maxn], ifact[maxn];

const int mod = 1e9 + 7;
void udd(int &a, int b) {
    a += b;
    if (a >= mod)
        a -= mod;
}
int mul(ll a, ll b) {
    return a * b % mod;
}
int bin(int a, int deg) {
    int res = 1;
    while (deg) {
        if (deg & 1)
            res = mul(res, a);
        deg >>= 1;
        a = mul(a, a);
    }
    return res;
}
int inv(int x) {
    assert(x);
    return bin(x, mod - 2);
}
int ways(int n, int k, ll mn) {
    if (k == 0)
        return n == 0;
    ll nn = n - mn * k;
    if (nn < 0)
        return 0;
    return mul(mul(ifact[k - 1], ifact[nn]), fact[nn + k - 1]);
}

int main() {
    #ifdef LOCAL
    assert(freopen("f.in", "r", stdin));
    #else
    #endif
    fact[0] = ifact[0] = 1;
    forn (i, maxn)
        if (i) {
            fact[i] = mul(fact[i - 1], i);
            ifact[i] = mul(ifact[i - 1], inv(i));
        }

    cin >> f >> w >> h;
    int total = 0, good = 0;
    for (int n = 1; n <= f + w; ++n) {
        for (int c1: {n / 2, n - n / 2}) {
            int c2 = n - c1;
            udd(total, mul(ways(f, c1, 1), ways(w, c2, 1)));
            udd(good, mul(ways(f, c1, 1), ways(w, c2, h + 1)));
        }
    }
    int res = mul(good, inv(total));
    cout << res << '\n';
}