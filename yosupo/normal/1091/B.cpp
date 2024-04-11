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
    ll sx = 0, sy = 0;
    for (int i = 0; i < 2*n; i++) {
        ll x, y;
        cin >> x >> y;
        sx += x; sy += y;
    }
    cout << sx / n << " " << sy / n << endl;
    return 0;
}