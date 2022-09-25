#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define forab(i,a,b) for (int i = int(a); i < int(b); ++i)
#define sz(x) ((int) (x).size())

int n, k, a, b, q;

const int maxn = 200100;

struct Fenwick {
    ll a[maxn];
    ll t[maxn];
    ll bound;

    Fenwick(int bd): bound(bd) {
        memset(a, 0, sizeof(a));
        memset(t, 0, sizeof(t));
    }

    void add(int pos, ll delta) {
        delta = min(delta, bound - a[pos]);
        a[pos] += delta;
        for (int i = pos; i < maxn; i |= i + 1)
            t[i] += delta;
    }

    ll get(int r) {
        ll res = 0;
        for (int i = r - 1; i >= 0; i = (i & (i + 1)) - 1)
            res += t[i];
        return res;
    }

    ll get(int l, int r) {
        if (l >= r)
            return 0;
        return get(r) - get(l);
    }
};

int main() {
#ifdef LOCAL
    assert(freopen("b.in", "r", stdin));
#endif
    cin >> n >> k >> a >> b >> q;
    Fenwick pref(b), suf(a);
    forn (i, q) {
        int t;
        scanf("%d", &t);
        if (t == 1) {
            int d, x;
            scanf("%d%d", &d, &x);
            --d;
            pref.add(d, x);
            suf.add(d, x);
        } else {
            int d;
            scanf("%d", &d);
            --d;
            ll res = pref.get(d) + suf.get(d + k, n);
            cout << res << '\n';
        }
    }
}