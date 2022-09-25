#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

const int maxn = 500200;
int n, m, c;
ld x[maxn];
ld p[maxn];
ld a[maxn];

struct Seg {
    ld mn, mx, res;

    Seg(): mn(1e18), mx(-1e18), res(0) {}

    Seg(ld x) {
        mn = mx = x;
        res = 0;
    }

    Seg(Seg a, Seg b) {
        if (a.mn == 1e18)
            *this = b;
        else if (b.mn == 1e18)
            *this = a;
        else {
            mn = min(a.mn, b.mn);
            mx = max(a.mx, b.mx);
            res = max(max(a.res, b.res), b.mx - a.mn);
        }
    }
};

const int base = 1 << 18;
Seg t[base * 2];

Seg get(int l, int r, int v = 1, int cl = 0, int cr = base) {
    if (l <= cl && cr <= r)
        return t[v];
    if (r <= cl || cr <= l)
        return Seg();
    int cc = (cl + cr) / 2;
    return Seg(get(l, r, v * 2, cl, cc), get(l, r, v * 2 + 1, cc, cr));
}

int main() {
    #ifdef LOCAL
    assert(freopen("c.in", "r", stdin));
    #else
    #endif
    cin >> n >> m >> c;
    forn (i, n)
        cin >> x[i];
    --n;
    forn (i, n) {
        cin >> p[i];
        p[i] /= 100.;
    }
    forn (i, n) {
        ld cur = (x[i + 1] - x[i]) * 0.5 - c * p[i];
        a[i + 1] = a[i] + cur;
    }

    forn (i, n + 1)
        t[i + base] = Seg(a[i]);
    for (int i = base - 1; i > 0; --i)
        t[i] = Seg(t[i * 2], t[i * 2 + 1]);

    ld res = 0;
    forn (i, m) {
        int a, b;
        cin >> a >> b;
        --a;

        auto cur = get(a, b);
        //cerr << a << ' ' << b << ' ' << cur.res << '\n';
        res += cur.res;
    }
    cout << fixed;
    cout.precision(10);
    cout << res << '\n';
}