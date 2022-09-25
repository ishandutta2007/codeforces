#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

#define int ll

const int maxn = 100100;
vector<int> g[maxn];
bool used[maxn];

int dfs(int u) {
    used[u] = true;
    int res = 1;
    for (int v: g[u]) {
        if (used[v])
            continue;
        res += dfs(v);
    }
    return res;
}

signed main() {
    #ifdef LOCAL
    assert(freopen("a.in", "r", stdin));
    #endif
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> s(k);
    forn (i, k) {
        cin >> s[i];
        --s[i];
    }
    forn (i, m) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int mx = 0;
    int res = 0;
    int e = n;
    forn (i, k) {
        int cur = dfs(s[i]);
        mx = max(mx, cur);
        res += cur * (cur - 1) / 2;
        e -= cur;
    }
    res += e * (e - 1) / 2;
    res += e * mx;
    res -= m;
    cout << res << '\n';
}