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
    freopen("a.in", "r", stdin);
    #else
    #endif
    int tn = 1;
    for (int i = 0; i < tn; ++i)
        solve();
    #ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
    #endif
}

const int maxn = 250001;
const int base = (1 << 18);

struct Seg
{
    int l, r, id, cost;
    
    Seg(int l, int r, int id): l(l), r(r), id(id) {}

    Seg() {}

    bool operator<(const Seg &s) const
    {
        return r < s.r;
    }

};

bool cmpl(const Seg &a, const Seg &b)
{
    return a.l < b.l || (a.l == b.l && a.cost < b.cost);
}

vector <Seg> a;
vector <Seg> b;

vector <Seg> t[base * 2];
vector<pair<int, int>> best_len[base * 2];

pair <int, int> get(int l, int R, int v = 1, int cl = 0, int cr = base)
{
    if (t[v].empty())
        return make_pair(0, -1);
    if (l <= cl)
    {
        assert(sz(t[v]) + 1 == sz(best_len[v]));
        int ptr = upper_bound(t[v].begin(), t[v].end(), Seg(INF, R, -1)) - t[v].begin();
        return best_len[v][ptr];
    }
    if (cr <= l)
        return make_pair(0, -1);
    int cc = (cl + cr) / 2;
    return max(get(l, R, v * 2, cl, cc), get(l, R, v * 2 + 1, cc, cr));
}

pair <ll, pair <int, int> > scan()
{
    vector <Seg> v = a;
    for (auto x: b)
        v.push_back(x);
    sort(v.begin(), v.end(), cmpl);
    pair <int, int> br = {-INF, -1};
    pair <ll, pair <int, int> > ans = {0, {-1, -1}};
    for (auto x: v)
    {
        if (x.cost == -1)
            br = max(br, {x.r, x.id});
        else if (br.first >= x.l)
            ans = max(ans, make_pair(ll(min(br.first, x.r) - x.l) * x.cost, make_pair(br.second, x.id)));
    }
    return ans;
}

int solve()
{
    int n, m;
    cin >> n >> m;
    forn (i, n)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        a.emplace_back(l, r, i);
        a.back().cost = -1;
    }
    forn (i, m)
    {
        int l, r, c;
        scanf("%d%d%d", &l, &r, &c);
        b.emplace_back(l, r, i);
        b.back().cost = c;
    }
    sort(a.begin(), a.end(), cmpl);
    forn (i, n)
        t[i + base].push_back(a[i]);
    for (int i = base - 1; i > 0; --i)
    {
        t[i].resize(t[i * 2].size() + t[i * 2 + 1].size());
        merge(t[i * 2].begin(), t[i * 2].end(), t[i * 2 + 1].begin(), t[i * 2 + 1].end(), t[i].begin());
    }
    forn (i, base * 2)
    {
        pair <int, int> best = {0, -1};
        for (Seg s: t[i])
        {
            best_len[i].push_back(best);
            best = max(best, make_pair(s.r - s.l, s.id));
        }
        best_len[i].push_back(best);
    }
    pair <ll, pair <int, int>> ans = make_pair(0, make_pair(-1, -1));
    forn (i, m)
    {
        int LB = lower_bound(a.begin(), a.end(), b[i], cmpl) - a.begin();
        pair <int, int> cur = get(LB, b[i].r);
//        cerr << cur.first << ' ' << cur.second << '\n';
        ans = max(ans, make_pair(ll(cur.first) * b[i].cost, make_pair(cur.second, b[i].id)));
    }
    
    ans = max(ans, scan());
    forn (i, n)
    {
        swap(a[i].l, a[i].r);
        a[i].l = -a[i].l;
        a[i].r = -a[i].r;
    }
    forn (i, m)
    {
        swap(b[i].l, b[i].r);
        b[i].l = -b[i].l;
        b[i].r = -b[i].r;
    }
    ans = max(ans, scan());

    cout << ans.first << '\n';
    if (ans.first)
        cout << ans.second.first + 1 << ' ' << ans.second.second + 1 << '\n';
    return 0;
}