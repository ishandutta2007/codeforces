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

struct P {
    ll x;
    char c;
};

struct UnionFind {
    vector<int> p, r;
    int gn;
    UnionFind(int N) {
        p.resize(N); r.resize(N);
        fill(begin(p), end(p), -1);
        fill(begin(r), end(r), 1);
        gn = N;
    }
    void merge(int a, int b) {
        int x = group(a), y = group(b);
        if (x == y) return; //same
        gn--;
        if (r[x] < r[y]) p[x] = y;
        else if (r[x] > r[y]) p[y] = x;
        else {p[x] = y; r[x]++;}
    }
    int group(int a) {
        if (p[a] == -1) return a;
        return p[a] = group(p[a]);
    }
    bool same(int a, int b) {
        return group(a) == group(b);
    }    
};

struct E {
    int a, b;
    ll c;
};

ll single(V<P> po) {
/*    cout << "SOLVE" << endl;
    for (auto p: po) {
        cout << "(" << p.x << " " << p.c << "), ";
    } cout << endl; */
    int n = int(po.size());
    assert(n >= 2);
    assert(po[0].c == 'G');
    assert(po[n-1].c == 'G');

    ll ans = 2 * (po[n-1].x - po[0].x);
    
    V<E> edges;
    edges.push_back(E{0, n-1, 0});
    int rid = 0, bid = 0;
    ll rba = po[0].x, bba = po[0].x;
    for (int ph = 1; ph < n; ph++) {
        auto d = po[ph];
        ll x = d.x; char c = d.c;
        if (c != 'B') {
            edges.push_back(E{rid, ph, x-rba});
            rid = ph;
            rba = x;
        }
        if (c != 'R') {
            edges.push_back(E{bid, ph, x-bba});
            bid = ph;
            bba = x;
        }
    }

    sort(begin(edges), end(edges), [&](E a, E b){
        return a.c < b.c;
    });

    ll buf = po[n-1].x - po[0].x;
    UnionFind uf(n);
    for (auto e: edges) {
        int a = e.a, b = e.b;
        if (uf.same(a, b)) continue;
        uf.merge(a, b);
        buf += e.c;
    }
    return min(ans, buf);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);

    int n;
    cin >> n;
    V<P> po(n);
    int gc = 0;

    ll rmi = TEN(18), rma = -TEN(18);
    ll bmi = TEN(18), bma = -TEN(18);
    ll gmi = TEN(18), gma = -TEN(18);
    for (int i = 0; i < n; i++) {
        ll x; char c;
        cin >> x >> c;
        po.push_back(P{x, c});
        if (c == 'G') gc++;

        if (c == 'R') {
            rmi = min(rmi, x);
            rma = max(rma, x);
        }
        if (c == 'G') {
            gmi = min(gmi, x);
            gma = max(gma, x);
        }
        if (c == 'B') {
            bmi = min(bmi, x);
            bma = max(bma, x);
        }
    }
    if (gc <= 1) {
        rmi = min(rmi, gmi);
        rma = max(rma, gma);
        bmi = min(bmi, gmi);
        bma = max(bma, gma);

        ll ans = 0;
        if (rmi != TEN(18)) ans += rma-rmi;
        if (bmi != TEN(18)) ans += bma-bmi;
        cout << ans << endl;
        return 0;
    }
    ll ans = 0;
    if (rmi < gmi) ans += gmi-rmi;
    if (bmi < gmi) ans += gmi-bmi;
    if (rma > gma) ans += rma-gma;
    if (bma > gma) ans += bma-gma;

    int l = 0;
    while (po[l].c != 'G') l++;
    for (int i = 0; i < gc-1; i++) {
        int r = l+1;
        while (po[r].c != 'G') r++;
        V<P> buf(begin(po)+l, begin(po)+r+1);
        ans += single(buf);
        l = r;
    }
    cout << ans << endl;
    return 0;
}