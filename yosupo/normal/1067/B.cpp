#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;

VV<int> g;

int ma_v, ma_dps;
void dfs(int p, int b, int ndp = 0) {
    if (ma_dps < ndp) {
        ma_dps = ndp;
        ma_v = p;
    }
    for (int d: g[p]) {
        if (d == b) continue;
        dfs(d, p, ndp + 1);
    }
}

V<int> path, buf;
void dfs2(int p, int b, int t) {
    buf.push_back(p);
    if (p == t) path = buf;
    for (int d: g[p]) {
        if (d == b) continue;
        dfs2(d, p, t);
    }
    buf.pop_back();
}

void fu() {
    cout << "No" << endl;
    exit(0);
}
void gg() {
    cout << "Yes" << endl;
    exit(0);
}

int k;
void check(int p, int b, int ndp = 0) {
    int deg = int(g[p].size());
    if (ndp == 0) {
        if (deg < 3) fu();
    } else if (ndp < k) {
        if (deg < 4) fu();
    } else {
        if (deg != 1) fu();
    }
    for (int d: g[p]) {
        if (d == b) continue;
        check(d, p, ndp + 1);
    }
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20) << fixed;
    int n;
    cin >> n >> k;
    g = VV<int>(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b; a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    ma_dps = 0;
    dfs(0, -1);
    int u = ma_v; ma_dps = 0;
    dfs(u, -1);
    int v = ma_v; ma_dps = 0;
    dfs2(u, -1, v);

    int m = int(path.size());
    //cout << path.size() << " " << path[m/2] << endl;
    int mid = path[m/2];
    check(mid, -1);
    gg();
    return 0;
}