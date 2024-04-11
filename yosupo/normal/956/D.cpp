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

template<class T>
struct Fenwick {
    int n;
    V<T> seg;
    Fenwick() {}
    Fenwick(int n) : n(n) {
        seg = V<T>(n+1, T(0));
    }
    /// ix
    void add(int i, T x) {
        i++;
        while (i <= n) {
            seg[i] += x;
            i += i & -i;
        }
    }
    /// [0, i)sum
    T sum(int i) {
        T s{0};
        while (i > 0) {
            s += seg[i];
            i -= i & -i;
        }
        return s;
    }
    /// [a, b)sum
    T sum(int a, int b) {
        return sum(b) - sum(a);
    }
    /// sum[0, idx) >= xidx(sum[0, n) < x  n+1)
    int sum_lower_bound(T x) {
        if (x <= 0) return 0;
        int res = 0, len = 1;
        while (2*len <= n) len *= 2;
        for (; len >= 1; len /= 2) {
            if (res + len <= n && seg[res + len] < x) {
                res += len;
                x -= seg[res];
            }
        }
        return res + 1;
    }
};

struct P {
    ll x, v;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);
    int n; ll w;
    cin >> n >> w;
    V<P> p;
    for (int i = 0; i < n; i++) {
        ll x, v;
        cin >> x >> v;
        p.push_back(P{x, v});
    }

    V<int> le(n), ri(n);
    iota(begin(le), end(le), 0);
    iota(begin(ri), end(ri), 0);

    sort(begin(le), end(le), [&](int aid, int bid){
        P a = p[aid], b = p[bid];
        // a.x / (a.v - w) < b.x / (b.v - w)
        ll zl = abs(a.x) * abs(b.v + w);
        ll zr = abs(b.x) * abs(a.v + w);
        if (zl != zr) return zl < zr;
        ll epsl = (a.x > 0) ? abs(b.v + w) : -abs(b.v + w);
        ll epsr = (b.x > 0) ? abs(a.v + w) : -abs(a.v + w);
        return epsl < epsr;
    });

    sort(begin(ri), end(ri), [&](int aid, int bid){
        P a = p[aid], b = p[bid];
        // a.x / (a.v + w) < b.x / (b.v + w)
        ll zl = abs(a.x) * abs(b.v - w);
        ll zr = abs(b.x) * abs(a.v - w);
        if (zl != zr) return zl < zr;
        ll epsl = (a.x > 0) ? -abs(b.v - w) : abs(b.v - w);
        ll epsr = (b.x > 0) ? -abs(a.v - w) : abs(a.v - w);
        return epsl < epsr;
    });


/*    for (int d: le) {
        cout << d << ", ";
    }
    cout << endl;

    for (int d: ri) {
        cout << d << ", ";
    }
    cout << endl;*/

    V<int> rle(n), rri(n);
    for (int i = 0; i < n; i++) {
        rle[le[i]] = i;
    }

    Fenwick<int> fw(n);

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int p = rle[ri[i]];
        ans += fw.sum(p, n);
        fw.add(p, 1);
    }

    cout << ans << endl;
    return 0;
}