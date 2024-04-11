#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

map<ll, ll> len;
ll getLen(ll n) {
    if (n <= 1)
        return 1;
    if (len.count(n))
        return len[n];
    return len[n] = getLen(n / 2) * 2 + 1;
}

ll calc(ll n, ll l, ll r) {
    //cerr << "yo " << n << ' ' << l << ' ' << r << '\n';
    if (n <= 1)
        return n;
    int len = getLen(n);
    if (l == 0 && r == len)
        return n;
    ll r1 = getLen(n / 2);
    ll l2 = r1 + 1;

    ll res = 0;
    if (l < r1)
        res += calc(n / 2, l, min(r, r1));
    if (l2 < r)
        res += calc(n / 2, max(l2, l) - l2, r - l2);
    if (l <= r1 && r1 < r)
        res += n % 2;
    return res;
}

int main() {
    #ifdef LOCAL
    assert(freopen("b.in", "r", stdin));
    #else
    #endif
    ll n, l, r;
    cin >> n >> l >> r;
    --l;
    cout << calc(n, l, r) << '\n';
}