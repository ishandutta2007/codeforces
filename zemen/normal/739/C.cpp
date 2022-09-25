#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

struct E {
    ll l, r;
    int p1, p2, s1, s2, ans, len;
    bool fict;

    E(ll x) {
        l = r = x;
        p1 = p2 = s1 = s2 = ans = len = 1;
        fict = false;
    }

    E(): fict(true) { }

    void add(ll delta) {
        l += delta;
        r += delta;
    }

    void print() {
        assert(!fict);
        cerr << "l " << l << '\n';
        cerr << "r " << r << '\n';
        cerr << "p1 " << p1 << '\n';
        cerr << "p2 " << p2 << '\n';
        cerr << "s1 " << s1 << '\n';
        cerr << "s2 " << s2 << '\n';
        cerr << "len " << len << '\n';
        cerr << "ans " << ans << '\n';
    }

    E(const E &a, const E &b) {
        if (a.fict) {
            *this = b;
            return;
        }
        if (b.fict) {
            *this = a;
            return;
        }
        fict = false;
        len = a.len + b.len;
        l = a.l;
        r = b.r;
        p1 = a.p1;
        p2 = a.p2;
        s1 = b.s1;
        s2 = b.s2;
        ans = max(a.ans, b.ans);
        if (a.r < b.l) {
            ans = max(ans, a.s1 + b.p2);
            if (b.s1 == b.len)
                s1 = b.len + a.s1;
            if (b.s2 == b.len)
                s2 = b.len + a.s1;
            if (a.s1 == a.len)
                p2 = a.len + b.p2;
        } else if (a.r > b.l) {
            ans = max(ans, a.s2 + b.p1);
            if (a.p1 == a.len)
                p1 = a.len + b.p1;
            if (a.p2 == a.len)
                p2 = a.len + b.p1;
            if (b.p1 == b.len)
                s2 = b.len + a.s2;
        }

        p2 = max(p2, p1);
        s2 = max(s2, s1);
    }

};

//const int base = 1 << 3;
const int base = 1 << 19;

namespace T {

E t[base * 2];
ll upd[base * 2];

void build() {
    for (int i = base - 1; i > 0; --i)
        t[i] = E(t[i * 2], t[i * 2 + 1]);
}

void push(int v) {
    if (!upd[v])
        return;
    t[v * 2].add(upd[v]);
    t[v * 2 + 1].add(upd[v]);
    upd[v * 2] += upd[v];
    upd[v * 2 + 1] += upd[v];
    upd[v] = 0;
}

void put(int l, int r, ll delta, int v = 1, int cl = 0, int cr = base) {
    if (l <= cl && cr <= r) {
        t[v].add(delta);
        upd[v] += delta;
        return;
    }
    if (r <= cl || cr <= l)
        return;
    int cc = (cl + cr) / 2;
    push(v);
    put(l, r, delta, v * 2, cl, cc);
    put(l, r, delta, v * 2 + 1, cc, cr);
    t[v] = E(t[v * 2], t[v * 2 + 1]);
}

int get() {
    return t[1].ans;
}

} //T

int main() {
    #ifdef LOCAL
    assert(freopen("c.in", "r", stdin));
    #else
    #endif
    int n;
    scanf("%d", &n);
    forn (i, n) {
        int a;
        scanf("%d", &a);
        T::t[i + base] = E(a);
    }
    T::build();
    //T::t[4].print();
    int m;
    scanf("%d", &m);
    forn (i, m) {
        int l, r, d;
        scanf("%d%d%d", &l, &r, &d);
        --l;
        T::put(l, r, d);
        cout << T::get() << '\n';
    }
}