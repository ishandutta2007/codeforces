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
    assert(freopen("d.in", "r", stdin));
    #else
    #endif
    int tn = 1;
    for (int i = 0; i < tn; ++i)
        solve();
    #ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
    #endif
}

const int maxn = 200001;

bool bad[maxn];

vector<int> g[maxn];
int good[maxn];

struct Vertex
{
    int u, p, q;
    
    Vertex(int u, int p, int q): u(u), p(p), q(q) {}

    bool operator<(const Vertex &v) const
    {
        ll x = (ll) p * v.q;
        ll y = (ll) v.p * q;
        return x > y || (x == y && u < v.u);
    }

};

set<Vertex> o;

vector<int> deleted;
int bestp = -1, bestq = 1, best = 0;

void update()
{
    if (o.empty())
        return;
    auto it = o.end();
    --it;
    int p = it->p, q = it->q;
    if ((ll) bestp * q < (ll) p * bestq)
        bestp = p, bestq = q, ::best = sz(deleted);
}

int solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    forn (i, k)
    {
        int t;
        cin >> t;
        bad[t - 1] = true;
        deleted.push_back(t - 1);
    }
    forn (i, m)
    {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    forn (i, n)
        if (!bad[i])
        {
            int p = 0;
            for (int v: g[i])
                if (!bad[v])
                    ++p;
            good[i] = p;
            o.emplace(i, p, sz(g[i]));
        }
    update();
    while (!o.empty())
    {
        auto it = o.end();
        --it;
        int u = it->u;
        o.erase(it);
        assert(!bad[u]);
        bad[u] = true;
        deleted.push_back(u);
        for (int v: g[u])
        {
            if (bad[v])
                continue;
            o.erase(Vertex(v, good[v], sz(g[v])));
            --good[v];
            o.emplace(v, good[v], sz(g[v]));
        }
        update();
    }
    cout << n - best << '\n';
    forn (i, best)
        bad[deleted[i]] = false;
    forn (i, n)
        if (bad[i])
            cout << i + 1 << ' ';
    cout << '\n';
    return 0;
}