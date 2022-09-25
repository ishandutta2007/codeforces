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
    assert(freopen("c.in", "r", stdin));
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
const int maxd = 17;
const int BOUND = 10;
const int ROOT = 0;

vector<int> g[maxn];

typedef vector<int> vi;
vi combine(const vi &a, const vi &b)
{
    vi res(sz(a) + sz(b));
    res.erase(set_union(a.begin(), a.end(), b.begin(), b.end(), res.begin()), res.end());
    if (sz(res) > BOUND)
        res.resize(BOUND);
    return res;
}

int p[maxd][maxn];
vi P[maxd][maxn];

int in[maxn], out[maxn];
int timer = 0;

vi who[maxn];
void dfs(int u, int prev)
{
    in[u] = timer++;
    p[0][u] = prev;
    P[0][u] = who[prev];
    for (int v: g[u])
        if (v != prev)
            dfs(v, u);
    out[u] = timer;
}

inline bool isPrev(int u, int v)
{
    return in[u] <= in[v] && out[v] <= out[u];
}

vi calc(int u, int v)
{
//    cerr << u << ' ' << v << '\n';
    vi res = combine(who[u], who[v]);
    for (int deg = maxd - 1; deg >= 0; --deg)
        if (!isPrev(p[deg][u], v))
        {
            res = combine(res, P[deg][u]);
            u = p[deg][u];
        }
    if (!isPrev(u, v))
    {
        int deg = 0;
        res = combine(res, P[deg][u]);
        u = p[deg][u];
    }
    for (int deg = maxd - 1; deg >= 0; --deg)
        if (!isPrev(p[deg][v], u))
        {
            res = combine(res, P[deg][v]);
            v = p[deg][v];
        }
    if (!isPrev(v, u))
        v = p[0][v];
    assert(v == u);
    return res;
}

int solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    forn (i, n - 1)
    {
        int u, v;
        scanf("%d%d", &u, &v), --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    forn (i, m)
    {
        int where;
        scanf("%d", &where), --where;
        vi cur(1, i);
        who[where] = combine(who[where], cur);
    }
    dfs(ROOT, ROOT);
    forn (deg, maxd - 1)
        forn (u, maxn)
        {
            p[deg + 1][u] = p[deg][p[deg][u]];
            P[deg + 1][u] = combine(P[deg][u], P[deg][p[deg][u]]);
        }
    forn (i, q)
    {
        int u, v, a;
        scanf("%d%d%d", &u, &v, &a), --u, --v;
        vi res = calc(u, v);
        if (sz(res) > a)
            res.resize(a);
        cout << sz(res);
        for (int x: res)
            cout << ' ' << x + 1;
        cout << '\n';

    }
    return 0;
}