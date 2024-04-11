#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n-1); }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    V<int> par(n); par[0] = -1;
    for (int i = 1; i < n; i++) {
        cin >> par[i]; par[i]--;
    }
    V<ll> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];

    V<int> h(n);
    for (int i = 1; i < n; i++) {
        h[i] = h[par[i]] + 1;
    }

    V<ll> a(n, TEN(18)); a[0] = s[0];
    for (int i = 1; i < n; i++) {
        int p = par[i], pp = par[p];
        if (h[i] % 2) continue;
        if (s[i] < s[pp]) {
            cout << -1 << endl;
            return 0;
        }
        a[p] = min(a[p], s[i] - s[pp]);
    }
    for (int i = 1; i < n; i++) {
        int p = par[i], pp = par[p];
        if (h[i] % 2) {
            if (a[i] == TEN(18)) a[i] = 0;
        } else {
            a[i] = s[i] - s[pp] - a[p];
        }
    }
    assert(a[0] == s[0]);
    for (int i = 1; i < n; i++) {
        int p = par[i], pp = par[p];
        if (h[i] % 2 == 0) {
            assert(s[i] == s[pp] + a[p] + a[i]);
        }
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) ans += a[i];
    cout << ans << endl;

    return 0;
}