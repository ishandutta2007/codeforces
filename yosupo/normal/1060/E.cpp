#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;

ll sm = 0, odd = 0, even = 0;

int n;
VV<int> g;
V<int> sz;
void dfs(int p, int b = -1, int ndp = 0) {
    if (ndp) odd++;
    else even++;
    sz[p] = 1;
    for (int d: g[p]) {
        if (d == b) continue;
        dfs(d, p, 1 - ndp);
        sz[p] += sz[d];
    }
    sm += ll(sz[p]) * (n - sz[p]);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20) << fixed;
    cin >> n;
    g = VV<int>(n);
    sz = V<int>(n);
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b; a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(0, -1);
    sm += odd * even;
    cout << sm / 2 << endl;
    return 0;
}