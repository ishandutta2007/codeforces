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

const int maxn = 200001;

vector<pair<int, bool>> g[maxn];
int col[maxn];

bool FAIL = false;

void color(int u, int c)
{
    if (col[u])
    {
        if (col[u] != c)
            FAIL = true;
        return;
    }
    col[u] = c;
    for (auto p: g[u])
        color(p.first, p.second ? 3 - c : c);
}

const int mod = 1000000007;

int solve()
{
    int n, m;
    cin >> n >> m;
    forn (i, m)
    {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        w ^= 1;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }
    color(0, 1);
    int ans = 1;
    forn (i, n)
        if (col[i] == 0)
        {
            color(i, 1);
            ans *= 2;
            ans %= mod;
        }
    if (FAIL)
        ans = 0;
    cout << ans << '\n';
    return 0;
}