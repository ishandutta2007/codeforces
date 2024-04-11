#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

const int mod = 1e9 + 7;
void udd(int &a, int b) {
    a += b;
    if (a >= mod)
        a -= mod;
}
int add(int a, int b) {
    udd(a, b);
    return a;
}
int sub(int a, int b) {
    udd(a, mod - b);
    return a;
}
int mul(ll a, ll b) {
    return a * b % mod;
}
int bin(int a, int b) {
    int r = 1;
    while (b) {
        if (b & 1)
            r = mul(r, a);
        b >>= 1;
        a = mul(a, a);
    }
    return r;
}
int inv(int a) {
    assert(a);
    return bin(a, mod - 2);
}

const int maxn = 200200;
int fact[maxn];
int ifact[maxn];

int binom(int n, int k) {
    return mul(mul(ifact[k], ifact[n - k]), fact[n]);
}

int a[maxn];
int tmp[maxn];

int v[maxn];
int naive(int n, bool neg = false) {
    if (n == 1)
        return v[0];
    forn (i, n - 1) {
        if (neg)
            tmp[i] = sub(v[i], v[i + 1]);
        else
            tmp[i] = add(v[i], v[i + 1]);
        neg ^= 1;
    }
    forn (i, n - 1)
        v[i] = tmp[i];
    return naive(n - 1, neg);
}

int main() {
    #ifdef LOCAL
    assert(freopen("b.in", "r", stdin));
    #else
    #endif
    fact[0] = ifact[0] = 1;
    for (int i = 1; i < maxn; ++i) {
        fact[i] = mul(fact[i - 1], i);
        ifact[i] = inv(fact[i]);
    }
    int n;
    cin >> n;
    forn (i, n) {
        cin >> a[i];
        v[i] = a[i];
    }
    //cerr << "naive " << naive(n, false) << '\n';
    if (n == 1) {
        cout << a[0] << '\n';
        return 0;
    }
    if (n % 2) {
        forn (i, n - 1) {
            if (i % 2)
                tmp[i] = sub(a[i], a[i + 1]);
            else
                tmp[i] = add(a[i], a[i + 1]);
        }
        forn (i, n - 1)
            a[i] = tmp[i];
        --n;
    }
    //forn (i, n)
        //cerr << a[i] << ' ';
    //cerr << '\n';
    int res = 0;
    int ss = n % 4 == 0 ? mod - 1 : 1;
    forn (i, n) {
        int coef = binom(n / 2 - 1, i / 2);
        if (i % 2)
            coef = mul(coef, ss);
        udd(res, mul(coef, a[i]));
    }
    cout << res << '\n';
}