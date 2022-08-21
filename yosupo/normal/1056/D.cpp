#include <bits/stdc++.h>
#include <ostream>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;

V<int> sz;
VV<int> g;

int dfs(int p) {
    int s = (g[p].size()) ? 0 : 1;
    for (int d: g[p]) {
        s += dfs(d);
    }
    sz.push_back(s);
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    g = VV<int>(n);
    for (int i = 1; i < n; i++) {
        int p;
        cin >> p; p--;
        g[p].push_back(i);
    }
    dfs(0);
    sort(sz.begin(), sz.end());

    for (int a: sz) {
        cout << a << " ";
    }
    cout << endl;
    return 0;
}