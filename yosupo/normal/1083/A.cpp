#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n-1); }

struct E { int to; ll di; };
int n;
V<ll> w;
VV<E> g;
ll ans = 0;

ll dfs(int p, int b) {
    V<ll> v = {0, 0};
    for (auto e: g[p]) {
        int d = e.to;
        if (d == b) continue;
        ll x = dfs(d, p) - e.di;
        v.push_back(x);
        sort(v.begin(), v.end(), greater<>());
        v.pop_back();
    }
    ans = max(ans, v[0] + v[1] + w[p]);
    return v[0] + w[p];
}

int main() {
    ios::sync_with_stdio(false); // Warning!!!!!
    cin.tie(nullptr);

    cin >> n;
    w = V<ll>(n);
    g = VV<E>(n);
    for (int i = 0; i < n; i++) cin >> w[i];
    for (int i = 0; i < n-1; i++) {
        int a, b; ll c;
        cin >> a >> b >> c; a--; b--;
        g[a].push_back(E{b, c});
        g[b].push_back(E{a, c});
    }
    dfs(0, -1);
    cout << ans << endl;
    return 0;
}