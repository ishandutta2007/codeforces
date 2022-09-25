#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <string.h>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <complex>
#include <cassert>

using namespace std;

#define INF 1000000001
#define INFL 1000000000000000001ll
#define pb push_back
#define fi first
#define se second
#define mp make_pair

typedef long long ll;
typedef long double ld;
typedef complex <double> point;

#define NAME "c"
//~ #undef NAME
#ifndef NAME
    #error "Write problem name"
#endif

pair <int, int> ev[1000001];
ll D[150001];
ll a[150001];
int k = 0;
int n, d;

pair <ll, ll> o_add[300001];
pair <ll, ll> o_del[300001];
int ac, dc;

void add(ll val, pair <ll, ll> *o = o_add, int &cnt = ac) {
    ll vmin = val;
    if (cnt)
        vmin = min(vmin, o[cnt - 1].se);
    o[cnt++] = mp(val, vmin);
}

void del() {
    if (!dc) {
        for (int i = ac - 1; i >= 0; --i)
            add(o_add[i].fi, o_del, dc);
        ac = 0;
    }
    --dc;
}

ll get() {
    ll res = INFL;
    if (ac)
        res = min(res, o_add[ac - 1].se);
    if (dc)
        res = min(res, o_del[dc - 1].se);
    return res;
}

void add_events(int lb, int rb, int ct) {
    ll s = min(ll(n - 1), d * ll(ct));
    //~ cerr << lb << ' ' << rb << '\n';
    //~ cerr << s << '\n';
    int pos = lb;
    ll bad = 0;
    int delta = rb - lb;
    for (int i = lb; i < rb; ++i)
        bad += ev[i].se;
    for (int i = 0; i < n; ++i) {
        D[i] = bad;
        while (pos < rb && ev[pos].se == i) {
            delta -= 2;
            ++pos;
        }
        bad -= delta;
    }
    //~ for (int i = 0; i < n; ++i)
        //~ cerr << D[i] << ' ';
    //~ cerr << '\n';
    ac = dc = 0;
    for (int i = 0; i <= s; ++i) {
        if (i > n)
            break;
        add(a[i]);
    }
    for (int i = 0; i < n; ++i) {
        if (i > s)
            del();
        a[i] = get() + D[i];
        if (i + 1 + s < n)
            add(a[i + 1 + s]);
    }
    //~ for (int i = 0; i < n; ++i)
        //~ cerr << a[i] << ' ';
    //~ cerr << '\n';
}

int main() {
    #ifdef _GEANY
    assert(freopen(NAME ".in", "r", stdin));
    #endif
    int m;
    cin >> n >> m >> d;
    ll sum = 0;
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        --a;
        sum += b;
        ev[i] = mp(c, a);
    }
    sort(ev, ev + m);
    int lb = 0;
    int pt = -2 * n;
    for (int i = 0; i < m; ++i) {
        if (ev[i].fi != ev[lb].fi) {
            add_events(lb, i, ev[lb].fi - pt);
            pt = ev[lb].fi;
            lb = i;
            continue;
        }
    }
    add_events(lb, m, ev[lb].fi - pt);
    ll res = *min_element(a, a + n);
    cout << sum - res << '\n';
}