#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

const int maxn = 100100;
vector<pair<int, ll>> g[maxn];
int used[maxn];
const int B = 60;
ll all0 = (1ll << B) - 1;
ll X[maxn];

vector<ll> v;
void append(ll x) {
    int cur = 0;
    for (int b = B - 1; b >= 0; --b) {
        if (!(x & (1ll << b)))
            continue;
        while (cur < sz(v) && v[cur] >= (2ll << b))
            ++cur;
        if (cur == sz(v) || !(v[cur] & (1ll << b))) {
            v.insert(v.begin() + cur, x);
            //cerr << "added " << x << '\n';
            return;
        }
        x ^= v[cur];
        assert(x < (1ll << b));
    }
    //cerr << "zero " << '\n';
}

void addX(ll x) {
    //cerr << "add " << x << '\n';
    all0 &= ~x;
    append(x);
}

int in[maxn];
int timer;
int pre(int u, int prev = -1) {
    in[u] = timer++;
    used[u] = 1;
    int s = 1;
    for (auto p: g[u]) {
        int v = p.first;
        ll t = p.second;
        if (v == prev)
            continue;
        if (used[v]) {
            if (in[v] < in[u]) {
                ll xx = X[u] ^ X[v] ^ t;
                addX(xx);
            }
            continue;
        }
        X[v] = X[u] ^ t;
        s += pre(v, u);
    }
    return s;
}

const int mod = 1e9 + 7;

int n;
int BIT;
ll ans;
int nodd[maxn], neven[maxn];
int ver = 5;

void dfs(int u) {
    used[u] = ver;
    neven[u] = 1;
    nodd[u] = 0;
    for (auto p: g[u]) {
        int v = p.first;
        bool t = p.second & (1ll << BIT);
        if (used[v] == ver)
            continue;
        dfs(v);
        int c0 = neven[v], c1 = nodd[v];
        if (t)
            swap(c0, c1);
        ans += ll(c1) * ll(neven[u]);
        ans += ll(c0) * ll(nodd[u]);
        neven[u] += c0;
        nodd[u] += c1;
    }
}

ll countPaths(int b, int u) {
    ans = 0;
    BIT = b;
    ++ver;
    dfs(u);
    //cerr << "count " << b << ' ' << ans << '\n';
    return ans;
}

ll res = 0;
void solve(int u, int s) {
    int dim = sz(v);
    //cerr << "dim " << dim << '\n';
    forn (i, B) {
        if (all0 & (1ll << i)) {
            ll cnt = countPaths(i, u);
            cnt %= mod;
            forn (j, dim + i)
                cnt = (cnt * 2) % mod;
            res += cnt;
        } else {
            ll cnt = ll(s) * ll(s - 1) / 2;
            cnt %= mod;
            forn (j, dim + i - 1)
                cnt = (cnt * 2) % mod;
            res += cnt;
        }
    }
}

int main() {
    #ifdef LOCAL
    assert(freopen("g.in", "r", stdin));
    #else
    #endif
    int m;
    cin >> n >> m;
    forn (i, m) {
        int u, v;
        ll t;
        cin >> u >> v >> t;
        --u, --v;
        g[u].emplace_back(v, t);
        g[v].emplace_back(u, t);
    }
    forn (i, n)
        if (!used[i]) {
            all0 = (1ll << B) - 1;
            v.clear();
            int cnt = pre(i);
            solve(i, cnt);
        }
    res %= mod;
    cout << res << '\n';
}