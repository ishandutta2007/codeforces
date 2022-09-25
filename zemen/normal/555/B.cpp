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

const int maxn = 300001;
ll l[maxn], r[maxn];

struct dist
{
    ll l, r;
    int id;

    dist(ll l, ll r, int id): l(l), r(r), id(id) {}

    dist() {}

    bool operator<(const dist &d) const
    {
        return r < d.r;
    }

};

set<pair<ll, int>> a;
dist p[maxn];

int ans[maxn];

int solve()
{
    int n, m;
    cin >> n >> m;
    forn (i, n)
        cin >> l[i] >> r[i];
    forn (i, n - 1)
        p[i] = dist(l[i + 1] - r[i], r[i + 1] - l[i], i);
    --n;
    sort(p, p + n);

    forn (i, m)
    {
        ll q;
        cin >> q;
        a.insert(make_pair(q, i));
    }

    forn (i, n)
    {
        auto it = a.lower_bound(make_pair(p[i].l, -1));
        if (it == a.end() || it->first > p[i].r)
        {
            cout << "No\n";
            return 0;
        }
        ans[p[i].id] = it->second;
        a.erase(it);
    }
    cout << "Yes\n";
    forn (i, n)
        cout << ans[i] + 1 << ' ';
    cout << '\n';
    return 0;
}