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

struct D {
    ll m, r;
    const bool operator<(const D &ri) {
        // m/r < ri.m/ri.r
        return m*ri.r < r*ri.m;
    }
};

struct Node {
    using NP = Node*;
    NP l, r;
    int sz;
    ll fs;
    V<D> v;
    V<ll> msm, rsm;
    bool same; ll ti;
    Node(int sz, D d[], ll s[]) : sz(sz) {
        same = false; ti = 0;
        if (sz == 1) {
            fs = s[0];
            v = {d[0]};
        } else {
            l = new Node(sz/2, d, s);
            r = new Node(sz - sz/2, d + sz/2, s + sz/2);
            v.resize(sz);
            merge(begin(l->v), end(l->v), begin(r->v), end(r->v), begin(v));
        }
        msm = V<ll>(sz+1);
        rsm = V<ll>(sz+1);
        for (int i = 0; i < sz; i++) {
            msm[i+1] = msm[i] + v[i].m;
        }
        for (int i = sz-1; i >= 0; i--) {
            rsm[i] = rsm[i+1] + v[i].r;
        }
    }

    ll query(int a, int b, ll t) {
        if (b <= 0 || sz <= a) return 0;
        if (a <= 0 && sz <= b && same) {
            ll di = t-ti;
            ti = t;
            int L = -1, R = sz;
            while (R-L > 1) {
                int M = (L+R)/2;
                if (v[M].m <= v[M].r * di) {
                    L = M;
                } else {
                    R = M;
                }
            }
            return msm[R] + di * rsm[R];
        }
        if (sz == 1) {
            ti = t;
            same = true;
            return min(v[0].m, fs + t*v[0].r);
        }
        if (same) {
            l->same = true; l->ti = ti;
            r->same = true; r->ti = ti;
        }
        if (a <= 0 && sz <= b) {
            ti = t;
            same = true;
        } else {
            same = false;
        }
        return l->query(a, b, t) + r->query(a-sz/2, b-sz/2, t);
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);

    int n;
    cin >> n;
    V<D> v(n); V<ll> s(n);
    for (int i = 0; i < n; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        if (b == 0) {
            a = 0; b = 1; c = 0;
        }
        s[i] = a;
        v[i] = D{b, c};
    }
    auto tr = new Node(n, v.data(), s.data());
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        ll t; int a, b;
        cin >> t >> a >> b; a--;
        cout << tr->query(a, b, t) << endl;
    }
    return 0;
}