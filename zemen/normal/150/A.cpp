#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

int main() {
    #ifdef LOCAL
    assert(freopen("a.in", "r", stdin));
    #else
    #endif
    ll x;
    cin >> x;
    vector<ll> p;
    for (ll i = 2; i * i <= x; ++i) {
        if (x % i)
            continue;
        while (x % i == 0) {
            p.push_back(i);
            x /= i;
        }
    }
    if (x > 1)
        p.push_back(x);
    if (sz(p) <= 1) {
        cout << 1 << '\n' << 0 << '\n';
        return 0;
    }
    if (sz(p) == 2) {
        cout << 2 << '\n';
        return 0;
    }
    cout << 1 << '\n';
    cout << p[0] * p[1] << '\n';
}