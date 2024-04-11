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

struct Edge {
    int to, id;
    char col;
};

const int maxn = 100100;
vector<Edge> g[maxn];
bool used[maxn];
int t[maxn];
int n, m;
char COL;

bool shit;
vector<int> cres[2];
void dfs(int u, int c) {
    used[u] = true;
    cres[c].push_back(u);
    t[u] = c;
    for (auto e: g[u]) {
        int cc = c ^ (e.col != COL);
        if (!used[e.to]) {
            dfs(e.to, cc);
        }
        if (t[e.to] != cc)
            shit = true;
    }
}

vector<int> solve(char _COL) {
    shit = false;
    COL = _COL;
    forn (i, n)
        used[i] = false;
    vector<int> res;
    forn (i, n)
        if (!used[i]) {
            cres[0].clear();
            cres[1].clear();
            dfs(i, 0);
            if (sz(cres[0]) > sz(cres[1]))
                cres[0] = cres[1];
            for (auto x: cres[0])
                res.push_back(x);
        }
    if (shit)
        return vector<int>(n + 5, -1);
    return res;
}

int main() {
    cout.precision(10);
    cout.setf(ios::fixed);
    #ifdef LOCAL
    assert(freopen("c.in", "r", stdin));
    #else
    #endif

    cin >> n >> m;
    forn (i, m) {
        int u, v;
        char col;
        cin >> u >> v >> col;
        --u, --v;
        g[u].push_back(Edge{v, i, col});
        g[v].push_back(Edge{u, i, col});
    }
    auto res1 = solve('B');
    auto res2 = solve('R');
    if (sz(res1) > sz(res2))
        res1 = res2;
    if (sz(res1) > n) {
        cout << -1 << '\n';
        return 0;
    }
    cout << sz(res1) << '\n';
    for (auto x: res1)
        cout << x + 1 << ' ';
    cout << '\n';

    #ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
    #endif
}