#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

const int maxn = 200200;
int cnt[maxn];
vector<int> g[maxn];
int N;
ll ans;

int dfs(int u, int prev = -1) {
    int res = cnt[u];
    for (int v: g[u]) {
        if (v == prev)
            continue;
        int cres = dfs(v, u);
        ans += min(cres, N - cres);
        res += cres;
    }
    return res;
}

int main() {
    #ifdef LOCAL
    assert(freopen("b.in", "r", stdin));
    #else
    #endif
    int n, k;
    cin >> n >> k;
    N = 2 * k;
    forn (i, 2 * k) {
        int x;
        scanf("%d", &x);
        --x;
        cnt[x]++;
    }
    forn (i, n - 1) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0);
    cout << ans << '\n';
}