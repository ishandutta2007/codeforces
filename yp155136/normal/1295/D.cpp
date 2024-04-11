#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;
#define F first
#define S second

ll gogo(ll x, ll m) {
    ll ret = 0;
    vector<pii> v;
    for (ll i = 2; i * i <= m; ++i) {
        if (m % i == 0) {
            ll cnt = 0;
            while (m % i == 0) {
                ++cnt;
                m /= i;
            }
            v.push_back({i, cnt});
        }
    }
    if (m != 1) {
        v.push_back({m, 1});
    }
    vector<pii> mu;
    mu.push_back({1, 1});
    for (pii p: v) {
        int sz = (int)mu.size();
        for (int i = 0; i < sz; ++i) {
            mu.push_back({mu[i].F * p.F, mu[i].S * (-1)});
        }
    }
    for (pii p: mu) {
        ret += p.S * (x / p.F);
    }
    return ret;
}

void go() {
    ll a, m; cin >> a >> m;
    ll gcd = __gcd(a, m);
    ll aa = a / gcd;
    ll mm = m / gcd;
    ll cnt = m / gcd;
    // x \in [0, cnt]
    // gcd(aa + x, mm) = 1
    // use mu to calculate
    cout << -gogo(aa - 1, mm) + gogo(aa + cnt - 1, mm) << endl;
}

int main () {
    int T; cin >> T;
    while (T--) {
        go();
    }
}