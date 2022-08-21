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

    int n, k; ll m;
    cin >> n >> m >> k;
    V<ll> b(n);
    for (int i = 0; i < n; i++) cin >> b[i];

    ll ans = n;
    V<ll> c(n-1);
    for (int i = 0; i < n-1; i++) c[i] = b[i + 1] - b[i] - 1;
    sort(c.begin(), c.end());
    for (int i = 0; i < n - k; i++) ans += c[i];
    cout << ans << endl;
    return 0;
}