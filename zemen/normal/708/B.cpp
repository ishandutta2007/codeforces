#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

ll a[2][2];

vector<ll> unb(ll n) {
    if (n == 0)
        return {0, 1};
    ll x = 1;
    while (x * (x - 1) / 2 < n)
        ++x;
    if (x * (x - 1) / 2 != n)
        return {};
    return {x};
}

void solve(ll n, ll c0, ll c1) {
    if (n == 0)
        return;
    if (c0 + c1 != n)
        return;

    ll x = a[0][1];
    string res(n, '0');
    forn (i, n) {
        if (c1 <= x) {
            res[i] = '0';
            x -= c1;
            --c0;
        } else {
            res[i] = '1';
            --c1;
        }
    }
    cout << res << '\n';
    exit(0);
}

int main() {
    #ifdef LOCAL
    assert(freopen("b.in", "r", stdin));
    #else
    #endif
    cin >> a[0][0] >> a[0][1] >> a[1][0] >> a[1][1];
    ll s = 0;
    forn (i, 2)
        forn (j, 2)
            s += a[i][j];
    auto n = unb(s);
    auto c0 = unb(a[0][0]);
    auto c1 = unb(a[1][1]);
    for (ll _n: n)
        for (ll _c0: c0)
            for (ll _c1: c1)
                solve(_n, _c0, _c1);
    cout << "Impossible\n";
}