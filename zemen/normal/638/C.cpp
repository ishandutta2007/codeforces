#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define forab(i,a,b) for (int i = int(a); i < int(b); ++i)

typedef long long ll;
typedef long long i64;
typedef long double ld;

const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

const int maxn = 200200;
vector<int> g[maxn];
vector<int> id[maxn];
const int ROOT = 0;

vector<int> res[maxn];
int worst = 0;

void dfs(int u, int prev = -1, int badt = -1) {
    worst = max(worst, sz(g[u]));
    int t = 0;
    if (t == badt)
        ++t;
    forn (i, sz(g[u])) {
        int v = g[u][i];
        if (v == prev)
            continue;
        int ct = t;
        res[t].push_back(id[u][i]);
        ++t;
        if (t == badt)
            ++t;
        dfs(v, u, ct);
    }
}

int main() {
    cout.precision(10);
    cout.setf(ios::fixed);
    #ifdef LOCAL
    assert(freopen("c.in", "r", stdin));
    #else
    #endif
    int n;
    cin >> n;
    forn (i, n - 1) {
        int u, v;
        scanf("%d%d", &u, &v);
        --u, --v;
        g[u].push_back(v);
        id[u].push_back(i);
        g[v].push_back(u);
        id[v].push_back(i);
    }
    dfs(ROOT);
    cout << worst << '\n';
    forn (i, worst) {
        cout << sz(res[i]);
        for (int c: res[i])
            cout << ' ' << c + 1;
        cout << '\n';
    }

    #ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
    #endif
}