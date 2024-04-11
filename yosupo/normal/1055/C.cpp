#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

ll solve(ll l1, ll r1, ll t1, ll l2, ll r2, ll t2) {
    r1++; r2++;
    ll g = gcd(t1, t2);
    ll x = l1 / g * g + (l2 % g);
    if (x < l1) x += g;
    return max(0LL, min({r1 - l1, r2 - l2, r1 - x}));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll l1, r1, t1, l2, r2, t2;
    cin >> l1 >> r1 >> t1 >> l2 >> r2 >> t2;
    cout << max(
            solve(l1, r1, t1, l2, r2, t2), solve(l2, r2, t2, l1, r1, t1)) << endl;
    return 0;
}