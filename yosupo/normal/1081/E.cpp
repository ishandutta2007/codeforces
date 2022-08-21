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
    int n;
    cin >> n;
    ll prev = 0;
    V<ll> c(n);
    for (int ph = 0; ph < n/2; ph++) {
        ll x;
        cin >> x;
        ll na = -1, nb = -1;
        for (ll i = 1; i*i <= x; i++) {
            if (x % i) continue;
            ll b = i;
            ll a = (x / i - i);
            if (a % 2) continue;
            a /= 2;
            if (a <= prev) continue;
            na = a; nb = b;
        }
        if (na == -1) {
            cout << "No" << endl;
            exit(0);
        }
        c[2 * ph] = na * na - prev * prev;
        c[2 * ph + 1] = x;
        prev = na + nb;
    }

    cout << "Yes" << endl;
    for (ll d: c) cout << d << " ";
    cout << endl;
    return 0;
}