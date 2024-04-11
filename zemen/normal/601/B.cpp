#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define forab(i,a,b) for (int i = int(a); i < int(b); ++i)

typedef long long ll;
typedef long double ld;

const int INF = 1000001000;
const ll INFL = 2000000000000001000;
int solve();


int main()
{
    srand(2317);
    cout.precision(10);
    cout.setf(ios::fixed);
    #ifdef LOCAL
    assert(freopen("b.in", "r", stdin));
    #else
    #endif
    int tn = 1;
    for (int i = 0; i < tn; ++i)
        solve();
    #ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
    #endif
}

const int maxn = 100100;
const int base = 1 << 17;

pair<int, int> delta[maxn];
int a[maxn];

pair<int, int> tmax[base * 2];

pair <int, int> get(int l, int r, int v = 1, int cl = 0, int cr = base)
{
    if (l <= cl && cr <= r)
        return tmax[v];
    if (r <= cl || cr <= l)
        return {-INF, -1};
    int cc = (cl + cr) / 2;
    return max(get(l, r, v * 2, cl, cc), get(l, r, v * 2 + 1, cc, cr));
}

pair<int, int> q[maxn];
int queries;
ll ans[maxn];

void calc(int l, int r)
{
    if (l + 1 >= r)
        return;
    auto mid = get(l, r - 1);
    int c = mid.second;
    forn (id, queries)
    {
        int L = c - max(l, q[id].first) + 1;
        int R = min(r, q[id].second) - c - 1;
        if (L > 0 && R > 0)
            ans[id] += (ll) mid.first * (ll) L * (ll) R;
    }
    calc(l, c + 1);
    calc(c + 1, r);
}

int solve()
{
    int n, q;
    cin >> n >> q;
    forn (i, n)
        scanf("%d", a + i);
    forn (i, n - 1)
        delta[i] = {abs(a[i] - a[i + 1]), i};
    forn (i, n - 1)
        tmax[i + base] = delta[i];
    forab (i, n - 1, base)
        tmax[i + base] = {-INF, -1};
    for (int v = base - 1; v > 0; --v)
        tmax[v] = max(tmax[v * 2], tmax[v * 2 + 1]);
    sort(delta, delta + n - 1);
    reverse(delta, delta + n - 1);
    queries = q;
    forn (i, q)
    {
        int l, r;
        cin >> l >> r;
        --l;
        ::q[i] = {l, r};
    }
    calc(0, n);
    forn (i, queries)
        cout << ans[i] << '\n';
    return 0;
}