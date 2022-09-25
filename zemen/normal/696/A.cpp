#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

map<ll, ll> cost;

void add(ll u, ll v, ll delta) {
    if (u == v)
        return;
    if (u < v)
        swap(u, v);
    cost[u] += delta;
    add(u / 2, v, delta);
}

ll get(ll u, ll v) {
    if (u == v)
        return 0;
    if (u < v)
        swap(u, v);
    return cost[u] + get(u / 2, v);
}

int main() {
    #ifdef LOCAL
    assert(freopen("a.in", "r", stdin));
    #else
    #endif
    int q;
    cin >> q;
    forn (i, q) {
        ll t, u, v;
        cin >> t >> u >> v;
        if (t == 1) {
            ll delta;
            cin >> delta;
            add(u, v, delta);
        } else {
            cout << get(u, v) << '\n';
        }
    }
}