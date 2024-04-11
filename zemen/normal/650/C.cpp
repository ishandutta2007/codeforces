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

const int maxSize = 1000100;
int n, m;
int buf[maxSize];
vector<int> g[maxSize];
vector<int> ge[maxSize];
int N = 0;

pair<int, int> sorted[maxSize];
void buildRow(int x) {
    forn (y, m)
        sorted[y] = make_pair(buf[x * m + y], x * m + y);
    sort(sorted, sorted + m);
    forab (i, 1, m) {
        int u = sorted[i].second;
        int v = sorted[i - 1].second;
        if (sorted[i].first == sorted[i - 1].first) {
            ge[u].push_back(v);
            ge[v].push_back(u);
        } else {
            g[u].push_back(v);
        }
    }
}

void buildColumn(int y) {
    forn (x, n)
        sorted[x] = make_pair(buf[x * m + y], x * m + y);
    sort(sorted, sorted + n);
    forab (i, 1, n) {
        int u = sorted[i].second;
        int v = sorted[i - 1].second;
        if (sorted[i].first == sorted[i - 1].first) {
            ge[u].push_back(v);
            ge[v].push_back(u);
        } else {
            g[u].push_back(v);
        }
    }
}

bool used[maxSize];
int res[maxSize];

void dfs(int);

void colore(int u, int val) {
    res[u] = val;
    for (int v: ge[u]) {
        if (res[v] != val)
            colore(v, val);
    }
}

int dfse(int u) {
    used[u] = true;
    int vmin = 1;
    for (int v: g[u]) {
        if (!used[v]) {
            dfs(v);
        }
        vmin = max(vmin, res[v] + 1);
    }
    for (int v: ge[u]) {
        if (!used[v])
            vmin = max(vmin, dfse(v));
    }
    return vmin;
}

void dfs(int u) {
    int col = dfse(u);
    colore(u, col);
}

int main() {
    cout.precision(10);
    cout.setf(ios::fixed);
    #ifdef LOCAL
    assert(freopen("c.in", "r", stdin));
    #else
    #endif
    cin >> n >> m;
    forn (i, n)
        forn (j, m)
            scanf("%d", &buf[i * m + j]);
    N = n * m;
    forn (i, n)
        buildRow(i);
    forn (i, m)
        buildColumn(i);
    forn (i, N)
        if (!used[i])
            dfs(i);
    forn (i, n) {
        forn (j, m)
            cout << res[i * m + j] << ' ';
        cout << '\n';
    }
    
    #ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
    #endif
}