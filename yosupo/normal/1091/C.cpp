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
    ll n;
    cin >> n;
    set<ll> st;
    auto check = [&](ll k) {
        st.insert(k + (k - 1) * k / 2 * (n / k));
    };
    for (ll i = 1; i*i <= n; i++) {
        if (n % i) continue;
        check(i); check(n/i);
    }
    for (ll d: st) {
        cout << d << " ";
    }
    cout << endl;
    return 0;
}