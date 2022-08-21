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

    ll c = 1;
    while (10 * c - 1 <= n) c *= 10;
    c -= 1;
    ll d = n - c;

    auto s = [&](ll x) {
        auto t = to_string(x);
        int ans = 0;
        for (char c: t) ans += c - '0';
        return ans;
    };

    cout << s(c) + s(d) << endl;
    return 0;
}