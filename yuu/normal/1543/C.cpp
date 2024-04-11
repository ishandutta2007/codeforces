#include <bits/stdc++.h>
using namespace std;
long double c, m, p, v;
long double ans;

constexpr long double factor = 65536;

void backtrack(long double c, long double m, long double prob) {
    ans += prob;
    if (c > 1e-6) {
        if (m > 1e-6) {
            backtrack(c - v, m + min(c, v) / 2, prob * c);
            backtrack(c + min(m, v) / 2, m - v, prob * m);
        } else {
            backtrack(c - v, -1, prob * c);
        }
    } else if (m > 0) {
        backtrack(-1, m - v, prob * m);
    }
}

void solve() {
    cin >> c >> m >> p >> v;
    ans = 0;
    backtrack(c, m, factor);
    cout << setprecision(16) << fixed << ans/factor << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}