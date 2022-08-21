#include <bits/stdc++.h>
#include <ostream>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;

using D = double;
V<D> pw = V<D>(1000);
void first() {
    for (int i = 0; i < 1000; i++) pw[i] = pow(1.0 / 0.9, i);
}

using P = pair<D, int>;

void solve() {
    int n;
    cin >> n;
    D f, t;
    cin >> f >> t;
    V<P> probs;
    for (int i = 0; i < n; i++) {
        D a; int p;
        cin >> a >> p;
        probs.push_back(P(a, p));
    }
    sort(probs.begin(), probs.end(), greater<P>());

    VV<D> dp(n + 1, V<D>(n * 10 + 1, 1e100));
    dp[0][0] = 0;
    for (auto pro: probs) {
        D a; int p;
        tie(a, p) = pro;
        auto ndp = dp;
        for (int k = 0; k <= n - 1; k++) {
            for (int l = 0; l <= (n - 1) * 10; l++) {
                ndp[k + 1][l + p] = min(ndp[k + 1][l + p],
                        dp[k][l] + a * pw[k + 1]);
            }
        }
        dp = ndp;
    }

    int ans = 0;
    for (int k = 1; k <= n; k++) {
        for (int l = 0; l <= n * 10; l++) {
            if (dp[k][l] >= 1e100) continue;
            D c = max(0.0, (sqrt(f * dp[k][l]) - 1) / f);
            D sm = 10 * k + c + dp[k][l] / (f * c + 1);
//            cerr << k << " " << l << " " << c << " " << dp[k][l] << " " << sm << endl;
            if (sm <= t) ans = max(ans, l);
        }
    }
    cout << ans << endl;
}


int main() {
    first();
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(20) << fixed;
    int t;
    cin >> t;
    for (int ph = 0; ph < t; ph++) solve();
    return 0;
}