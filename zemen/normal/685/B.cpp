#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

const int maxn = 300300;
vector<int> g[maxn];
int pr[maxn];
int ans[maxn];
int cnt[maxn];

void dfs(int u) {
    cnt[u] = 1;
    pair<int, int> maxCnt = {0, -1};
    for (int v: g[u]) {
        dfs(v);
        cnt[u] += cnt[v];
        maxCnt = max(maxCnt, {cnt[v], v});
    }
    if (2 * maxCnt.first <= cnt[u]) {
        ans[u] = u;
        return;
    }
    ans[u] = ans[maxCnt.second];
    while (2 * (cnt[u] - cnt[ans[u]]) > cnt[u])
        ans[u] = pr[ans[u]];
}

int main() {
    #ifdef LOCAL
    assert(freopen("b.in", "r", stdin));
    #else
    #endif
    int n, q;
    cin >> n >> q;
    forn (i, n - 1) {
        int p;
        scanf("%d", &p);
        --p;
        pr[i + 1] = p;
        g[p].push_back(i + 1);
    }
    dfs(0);
    forn (i, q) {
        int u;
        scanf("%d", &u);
        --u;
        cout << ans[u] + 1 << '\n';
    }
}