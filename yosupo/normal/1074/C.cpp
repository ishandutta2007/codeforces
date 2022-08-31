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
    using A = array<ll, 5>;
    V<A> dp(16, {-TEN(18), -TEN(18), -TEN(18), -TEN(18), -TEN(18)});
    dp[0].fill(0LL);
    for (int ph = 0; ph < n; ph++) {
        V<A> ndp = dp;
        auto add = [&](int f, ll x) {
            for (int i = 0; i < 16; i++) {
                if (f & i) continue;
                for (int c = 0; c <= 3; c++) {
                    ndp[f | i][c+1] = max(ndp[f | i][c+1], dp[i][c] + x);
                }
            }
        };
        ll x, y;
        cin >> x >> y; x *= 2; y *= 2;
        add(1, -x);
        add(2, x);
        add(4, -y);
        add(8, y);
        add(1+4, -x-y);
        add(1+8, -x+y);
        add(2+4, x-y);
        add(2+8, x+y);
        dp = ndp;
    }
    cout << dp[15][3];
    for (int i = 4; i <= n; i++) {
        cout << " " << dp[15][4];
    }
    cout << endl;
    return 0;
}