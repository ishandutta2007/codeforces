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
    ll ans = 2 * n;
    struct E { ll x; int ty; };
    V<E> ev;
    for (int i = 0; i < n; i++) {
        ll l, r;
        cin >> l >> r;
        ans += l + r;
        ev.push_back(E{l, 0});
        ev.push_back(E{r, 1});
    }

    sort(ev.begin(), ev.end(), [&](E a, E b) { return a.x < b.x; });

    V<ll> lst, rst;
    for (auto e: ev) {
        if (e.ty == 0) {
            if (rst.empty()) lst.push_back(e.x);
            else {
                ans += e.x - rst.back();
                rst.pop_back();
            }
        } else {
            if (lst.empty()) rst.push_back(e.x);
            else {
                ans += e.x - lst.back();
                lst.pop_back();
            }
        }
    }
    cout << ans / 2 << endl;
    return 0;
}