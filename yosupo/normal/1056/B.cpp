#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m; n++;
    int k = n / m;
    n %= m;
    V<ll> cnt(m);
    for (int i = 0; i < m; i++) {
        cnt[(i * i) % m] += k;
    }
    for (int i = 0; i < n; i++) {
        cnt[(i * i) % m] += 1;
    }
    cnt[0] --;

    ll ans = 0;
    for (int i = 0; i < m; i++) {
        ans += cnt[i] * cnt[(m - i) % m];
    }
    cout << ans << endl;
    return 0;
}