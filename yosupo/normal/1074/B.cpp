#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;


VV<int> g;
V<bool> ok;

int dfs(int p, int b) {
    if (ok[p]) return p;
    for (int d: g[p]) {
        if (d == b) continue;
        int u = dfs(d, p);
        if (u != -1) return u;
    }
    return -1;
}

void solve() {
    int n;
    cin >> n;
    g = VV<int>(n);
    ok = V<bool>(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b; a--; b--;
        g[a].push_back(b); g[b].push_back(a);
    }

    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x; x--;
        ok[x] = true;
    }
    cin >> k;
    set<int> b_pt;
    int st = -1;
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x; x--;
        st = x;
        b_pt.insert(x);
    }
    cout << "B " << st+1 << endl;
    cin >> st; st--;
    int nx = dfs(st, -1);
    cout << "A " << nx+1 << endl;
    int ck;
    cin >> ck; ck--;
    if (b_pt.count(ck)) {
        cout << "C " << nx+1 << endl;
    } else {
        cout << "C -1" << endl;
    }
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20) << fixed;

    int t;
    cin >> t;
    for (int ph = 0; ph < t; ph++) solve();
    return 0;
}