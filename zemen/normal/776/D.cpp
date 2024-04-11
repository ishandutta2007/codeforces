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
int r[maxn];
vector<int> which[maxn];

vector<pair<int, int>> g[maxn];

int col[maxn];
bool used[maxn];
void dfs(int u, int c = 0) {
    used[u] = true;
    col[u] = c;
    for (auto p: g[u]) {
        int nc = c ^ p.second;
        int v = p.first;
        if (used[v]) {
            if (nc != col[v]) {
                cout << "NO\n";
                exit(0);
            }
        } else {
            dfs(v, nc);
        }
    }
}

int main() {
    #ifdef LOCAL
    assert(freopen("d.in", "r", stdin));
    #else
    #endif
    int n, m;
    cin >> n >> m;
    forn (i, n)
        cin >> r[i];
    forn (i, m) {
        int cnt;
        cin >> cnt;
        forn (j, cnt) {
            int k;
            cin >> k;
            --k;
            which[k].push_back(i);
        }
    }
    forn (i, n) {
        assert(sz(which[i]) == 2);
        int u = which[i][0];
        int v = which[i][1];
        g[u].emplace_back(v, !r[i]);
        g[v].emplace_back(u, !r[i]);
        //cerr << "edge " << u << ' ' << v << '\n';
    }
    forn (i, m)
        if (!used[i])
            dfs(i);
    cout << "YES\n";
}