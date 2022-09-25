#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) (x).size())
#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; --i)

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
    freopen("f.in", "r", stdin);
    #else
    #endif
    int tn = 1;
    for (int i = 0; i < tn; ++i)
        solve();
    #ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
    #endif
}

const int maxn = 300300;
int p[maxn];

const int base = 1 << 19;
pair <int, int> t[base * 2];
int upd[base * 2];
set <int> minp, maxp;

void push(int v)
{
    t[v * 2].first += upd[v];
    upd[v * 2] += upd[v];
    t[v * 2 + 1].first += upd[v];
    upd[v * 2 + 1] += upd[v];
    upd[v] = 0;
}

pair <int, int> combine(pair <int, int> a, pair <int, int> b)
{
    auto res = max(a, b);
    if (a.first == b.first)
        res.second = a.second + b.second;
    return res;
}

void update(int v)
{
    t[v] = combine(t[v * 2], t[v * 2 + 1]);
}

void add(int l, int r, int val, int v = 1, int cl = 0, int cr = base)
{
    if (l <= cl && cr <= r)
    {
        t[v].first += val;
        upd[v] += val;
        return;
    }
    if (r <= cl || cr <= l)
        return;
    push(v);
    int cc = (cl + cr) / 2;
    add(l, r, val, v * 2, cl, cc);
    add(l, r, val, v * 2 + 1, cc, cr);
    update(v);
}

pair <int, int> get(int l, int r, int v = 1, int cl = 0, int cr = base)
{
    if (l <= cl && cr <= r)
        return t[v];
    if (r <= cl || cr <= l)
        return make_pair(-INF, 0);
    push(v);
    int cc = (cl + cr) / 2;
    return combine(get(l, r, v * 2, cl, cc), get(l, r, v * 2 + 1, cc, cr));
}

int solve()
{
    int n;
    cin >> n;
    forn (i, n)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        --a, --b;
        p[a] = b;
    }
    minp.insert(n);
    maxp.insert(n);
    forn (i, n)
        t[i + base] = make_pair(0, 1);
    for (int i = n; i < base; ++i)
        t[i + base] = make_pair(-INF, 0);
    ford (i, base)
        update(i);
    ll ans = 0;
    ford (i, n)
    {
        add(i, n, 1);
        while (sz(minp) > 1 && p[*minp.begin()] > p[i])
        {
            int l = *minp.begin();
            minp.erase(minp.begin());
            int r = *minp.begin();
            int old = p[l];
            add(l, r, p[i] - old);
        }
        minp.insert(i);
        while (sz(maxp) > 1 && p[*maxp.begin()] < p[i])
        {
            int l = *maxp.begin();
            maxp.erase(maxp.begin());
            int r = *maxp.begin();
            int old = p[l];
            add(l, r, old - p[i]);
        }
        maxp.insert(i);
        pair <int, int> res = get(i, n);
        assert(res.first == 1);
        ans += res.second;
    }
    cout << ans << '\n';
    return 0;
}