#include <bits/stdc++.h>
#include <ostream>

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
    int n, k;
    cin >> n >> k;
    auto rev = [&](int x) {
        return x ^ ((1<<k) - 1);
    };
    map<int, int> mp;
    int sm = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        sm ^= x;
        mp[(sm % 2 == 0) ? sm : rev(sm)]++;
//        cout << sm << endl;
    }
    auto c2 = [&](ll x) {
        return x * (x - 1) / 2;
    };
    ll ans = c2(n + 1);
    for (auto p: mp) {
        ll c = p.second;
//        cout << p.first << " " << p.second << endl;
        if (!p.first) c++;
        ans -= c2(c/2) + c2(c-c/2);
    }
    cout << ans << endl;
    return 0;
}