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

    int n, m; ll l;
    cin >> n >> m >> l;
    V<ll> a(n);
    int ans = 0;
    V<bool> used(n+2);
    auto on = [&](int p) {
        if (used[p]) return;
        if (used[p-1]) ans--;
        if (used[p+1]) ans--;
        used[p] = true;
        if (!used[p-1]) ans++;
        if (!used[p+1]) ans++;
    };
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] > l) on(i + 1);
    }
    for (int ph = 0; ph < m; ph++) {
        int ty;
        cin >> ty;
        if (ty == 0) {
            cout << ans / 2 << endl;
        } else {
            int p, d;
            cin >> p >> d; p--;
            a[p] += d;
            if (a[p] > l) on(p + 1);
        }
    }
    return 0;
}