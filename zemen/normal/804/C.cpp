#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

const int maxn = 300300;
vector<int> col[maxn];
vector<int> g[maxn];
int deg[maxn];

int res[maxn];
int k = 1;

bool was[maxn];

int main() {
    #ifdef LOCAL
    assert(freopen("c.in", "r", stdin));
    #else
    #endif
    int n, m;
    cin >> n >> m;
    forn (i, n) {
        int c;
        scanf("%d", &c);
        forn (j, c) {
            int x;
            scanf("%d", &x);
            --x;
            col[i].push_back(x);
        }
    }

    forn (i, m)
        res[i] = -1;

    forn (i, n - 1) {
        int u, v;
        scanf("%d%d", &u, &v);
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    vector<int> q;
    forn (i, n)
        if (deg[i] <= 1)
            q.push_back(i);
    for (int ii = 0; ii < sz(q); ++ii) {
        int u = q[ii];
        for (auto v: g[u]) {
            if (--deg[v] == 1)
                q.push_back(v);
        }
    }
    assert(sz(q) == n);
    reverse(all(q));
    for (int u: q) {
        //cerr << "ver " << u << '\n';
        for (auto c: col[u]) {
            if (res[c] != -1)
                was[res[c]] = true;
        }

        int nc = 0;
        for (auto c: col[u]) {
            if (res[c] != -1)
                continue;
            while (was[nc])
                ++nc;
            //cerr << "nc " << nc << '\n';
            was[nc] = true;
            res[c] = nc;
            k = max(k, nc + 1);
        }

        for (auto c: col[u])
            was[res[c]] = false;
    }
    cout << k << '\n';
    forn (i, m) {
        if (res[i] == -1)
            res[i] = 0;
        cout << res[i] + 1 << ' ';
    }
    cout << '\n';
}