#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <numeric>
#include <random>
#include <vector>
#include <array>
#include <bitset>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n==0) ? 1 : 10*TEN(n-1); }
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;

int n; ll k;
V<ll> a;

ll naive() {
    for (ll d = 2*TEN(5); d >= 1; d--) {
        ll sm = 0;
        for (ll u: a) {
            sm += (d-u%d)%d;
        }
        if (sm <= k) return d;
    }
    assert(false);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);
    cin >> n >> k;
    a = V<ll>(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll ans = naive();

    ll tm = -1;
    using Q = tuple<ll, ll, int>;
    V<Q> v;
    for (ll y: a) {
        tm = max(tm, (y+TEN(4)-1)/TEN(4));
        for (ll k = 1; k <= TEN(4); k++) {
            ll l = (y+k-1)/k;
            ll r = (k == 1) ? 2*TEN(11) : ((y+k-2)/(k-1));
            if (r <= l) continue;
            v.push_back(Q(l, -y, 0));
            v.push_back(Q(l, k, 1));
            v.push_back(Q(r, y, 0));
            v.push_back(Q(r, -k, 1));
        }
    }
    sort(begin(v), end(v));

    ll z0 = 0, z1 = 0;
    int m = int(v.size());
    for (int i = 0; i < m; i++) {
        ll nt, nf; int ty;
        tie(nt, nf, ty) = v[i];
        //[tm, nt)
        if (tm < nt) {
            assert(z1 > 0);
            ll b = min(nt-1, (k - z0) / z1);
            if (tm <= b) ans = max(ans, b);
        }
        tm = max(tm, nt);
        if (ty == 0) {
            z0 += nf;
        } else {
            z1 += nf;
        }
    }

    cout << ans << endl;
    return 0;
}