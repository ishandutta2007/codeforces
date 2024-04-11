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
ld res[maxn];
int cnt[maxn];

void pre(int u) {
    cnt[u] = 1;
    for (int v: g[u]) {
        pre(v);
        cnt[u] += cnt[v];
    }
}

void dfs(int u, ld cres = 1) {
    res[u] = cres;
    for (int v: g[u]) {
        dfs(v, cres + (cnt[u] - cnt[v] - 1) / 2. + 1);
    }
}

int main() {
    #ifdef LOCAL
    assert(freopen("b.in", "r", stdin));
    #else
    #endif
    int n;
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int p;
        scanf("%d", &p);
        --p;
        g[p].push_back(i);
    }
    pre(0);
    dfs(0);
    cout << fixed;
    cout.precision(8);
    forn (i, n)
        cout << res[i] << ' ';
    cout << '\n';
}