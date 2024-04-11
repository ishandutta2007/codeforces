#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

ll n;

ll get(ll v, ll k, ll s) {
    if (k == s)
        return v;
    ll ns = (s - 1) / 2;
    if (k < s)
        return get(v * 2, k, ns);
    else
        return get(v * 2 + 1, k - s - 1, ns);
}

ll getPos(ll v) {
    vector<ll> p;
    while (v > 1) {
        p.push_back(v);
        v /= 2;
    }
    p.push_back(v);
    reverse(p.begin(), p.end());
    ll s = (n - 1) / 2;
    ll res = 0;
    forn (i, sz(p) - 1) {
        if (p[i + 1] == p[i] * 2 + 1)
            res += s + 1;
        s = (s - 1) / 2;
    }
    res += s;
    return res;
}

int main() {
    #ifdef LOCAL
    assert(freopen("d.in", "r", stdin));
    #else
    #endif
    int q;
    cin >> n >> q;
    ll base = (n + 1) / 2;
    forn (i, q) {
        ll u;
        string s;
        cin >> u >> s;
        --u;
        u = get(1, u, (n - 1) / 2);
        //cerr << "norm " << u << '\n';
        for (auto c: s) {
            if (c == 'U') {
                if (u != 1)
                    u /= 2;
            } else if (c == 'L') {
                if (u < base)
                    u *= 2;
            } else if (c == 'R') {
                if (u < base)
                    u = u * 2 + 1;
            } else
                assert(false);
        }
        //cerr << "ans " << u << '\n';
        cout << getPos(u) + 1 << '\n';
    }
}