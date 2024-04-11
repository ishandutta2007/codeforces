#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const ll infl = ll(2e18) + ll(1e10);
#define int ll

const int inf = int(1e11) + int(1e5);
typedef pair<int, int> pii;

const int maxn = 500500;
pii a[maxn];
int b[maxn];
int d[maxn];

ll func(ll c, ll d) {
    if (c < d)
        return inf;
    ll t = 2 * d;
    ll rem = c - d;
    t -= rem;
    t = max(t, d);
    return t;
}

int calc(int n, int k, ll t) {
    int L = -1, R = n;
    while (L + 1 < R) {
        int C = (L + R) / 2;
        int c = a[C].first;
        ll ct = 0;
        forn (i, k)
            ct += func(c, d[i]);
        //cerr << c << ' ' << ct << '\n';
        if (ct > t)
            L = C;
        else
            R = C;
    }
    return R;
}

signed main() {
    #ifdef LOCAL
    assert(freopen("a.in", "r", stdin));
    #else
    #endif
    int n, s, k, t;
    cin >> n >> k >> s >> t;
    forn (i, n) {
        signed x, y;
        scanf("%d%d", &x, &y);
        a[i] = {y, x};
    }
    sort(a, a + n);
    forn (i, k) {
        signed x;
        scanf("%d", &x);
        b[i + 1] = x;
    }
    b[k + 1] = s;
    sort(b, b + k + 2);
    forn (i, k + 1)
        d[i] = b[i + 1] - b[i];
    int x = calc(n, k + 1, t);
    if (x >= n) {
        cout << -1 << '\n';
        return 0;
    }
    int best = inf;
    for (int i = x; i < n; ++i)
        best = min(best, a[i].second);
    cout << best << '\n';
}