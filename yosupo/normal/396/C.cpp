#include <vector>
#include <iostream>
#include <set>
#include <cstdio>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <tuple>
#include <algorithm>
#include <limits>
#include <map>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;

template <int SIZE, ll MD>
struct FenwickTreeMod {
    ll seg[SIZE];
    
    void init() {
        fill_n(seg, SIZE, 0);
    }

    void add(int i, ll x) {
        x %= MD;
        while (i < SIZE) {
            seg[i] += x;
            seg[i] %= MD;
            i += (i+1) & ~i;
        }
    }

    //[0, i)
    ll sum(int i) {
        ll s = 0;
        int d = 1;
        while (i >= d) {
            i -= d;
            s += seg[i];
            s %= MD;
            d = (i+1) & ~i;
        }
        return s;
    }

    //[a, b)
    ll sum(int a, int b) {
        ll d = sum(b) - sum(a);
        return (d % MD + MD) % MD;
    }
};

template <int SIZE, ll MD>
struct FenwickRAddMod {
    FenwickTreeMod<SIZE, MD> b0, b1;
    ll ds[SIZE+1];
    void init(const ll d[]) {
        b0.init();
        b1.init();
        ds[0] = 0;
        for (int i = 1; i <= SIZE; i++) {
            ds[i] = (d[i-1]+ds[i-1])%MD;
        }
    }

    void add(int i, ll x) {
        b0.add(i, x);
    }

    void add(int l, int r, ll x) {
        b1.add(l, x);
        b1.add(r, -x);
        b0.add(l, -ds[l]*x);
        b0.add(r, ds[r]*x);
    }

    //[0, i)
    ll sum(int i) {
        ll d = b0.sum(i)+b1.sum(i)*ds[i];
        return (d % MD + MD) % MD;
    }

    //[a, b)
    ll sum(int a, int b) {
        ll d = sum(b) - sum(a);
        return (d % MD + MD) % MD;
    }
};

const int MN = 300300;
const int MD = 1e9+7;
FenwickRAddMod<MN, MD> f;
FenwickTreeMod<MN, MD> bit;
vector<int> g[MN];
ll h[MN];
int p[MN];
int pl[MN], pr[MN];
int c = 0;
void tour(int i, int hh) {
    p[c] = i;
    pl[i] = c;
    h[c] = hh;
    c++;
    for (int d: g[i]) {
        tour(d, hh+1);
    }
    pr[i] = c;
}
int main() {
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int d;
        cin >> d; d--;
        g[d].push_back(i);
    }
    tour(0, 0);
    bit.init();
    f.init(h);
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int type, v;
        cin >> type >> v; v--;
        if (type == 1) {
            ll x, k;
            cin >> x >> k;
            f.add(pl[v], pr[v], -k);
            ll u = x+k*h[pl[v]]%MD;
            bit.add(pl[v], u);
            bit.add(pr[v], -u);
        } else {
            cout << ((bit.sum(pl[v]+1) + f.sum(pl[v], pl[v]+1)) % MD + MD) % MD << endl;
        }
    }
    return 0;
}