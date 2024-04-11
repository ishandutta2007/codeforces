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
int c[maxn];
vector<int> g[maxn];

bool check(int u, int prev = -1) {
    for (int v: g[u]) {
        if (v == prev)
            continue;
        if (c[u] != c[v] && prev != -1)
            return false;
        if (!check(v, u))
            return false;
    }
    return true;
}

int main() {
    #ifdef LOCAL
    assert(freopen("a.in", "r", stdin));
    #else
    #endif
    int n;
    cin >> n;
    forn (i, n - 1) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    forn (i, n)
        cin >> c[i];
    if (check(0)) {
        cout << "YES\n1\n";
        return 0;
    }
    forn (u, n) {
        for (int v: g[u]) {
            if (c[u] != c[v]) {
                if (check(u)) {
                    cout << "YES\n" << u + 1 << '\n';
                    return 0;
                }
                if (check(v)) {
                    cout << "YES\n" << v + 1 << '\n';
                    return 0;
                }
                cout << "NO\n";
                return 0;
            }
        }
    }
    cout << "NO\n";
    return 0;
}