#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20) << fixed;

    int n, m;
    cin >> n >> m;
    V<ll> a(n), b(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    auto ck = [&](V<ll> c) {
        int k = int(c.size());
        V<ll> mi(k+1, TEN(9));
        mi[0] = 0;
        for (int l = 0; l < k; l++) {
            ll sm = 0;
            for (int r = l+1; r <= k; r++) {
                sm += c[r-1];
                mi[r-l] = min(mi[r-l], sm);
            }
        }
        return mi;
    };

    auto a_mi = ck(a), b_mi = ck(b);

    ll x;
    cin >> x;
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (a_mi[i] * b_mi[j] <= x) ans = max(ans, i * j);
        }
    }
    cout << ans << endl;
    return 0;
}