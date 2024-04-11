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
vector<int> g[maxn];
vector<int> ans[2];
int col[maxn];
bool used[maxn];

void dfs(int u, int c = 0) {
    col[u] = c;
    ans[c].push_back(u);
    used[u] = true;
    for (int v: g[u]) {
        if (used[v]) {
            if (col[v] == c) {
                cout << -1 << '\n';
                exit(0);
            }
        }
        else
            dfs(v, c ^ 1);
    }
}

int main() {
    #ifdef LOCAL
    assert(freopen("a.in", "r", stdin));
    #else
    #endif
    int n, m;
    cin >> n >> m;
    forn (i, m) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    forn (i, n)
        if (!used[i])
            dfs(i);
    forn (q, 2) {
        cout << ans[q].size() << '\n';
        for (auto p: ans[q])
            cout << p + 1 << ' ';
        cout << '\n';
    }
}