#undef LOCAL
#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }

#ifdef LOCAL
#define show(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl
#else
#define show(x) true
#endif

template <class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
    return os << "P(" << p.first << ", " << p.second << ")";
}

template <class T> ostream& operator<<(ostream& os, const V<T>& v) {
    os << "[";
    for (auto d : v) os << d << ", ";
    return os << "]";
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    ll m, a, b;
    cin >> m >> a >> b;

    V<ll> dp(a, TEN(18));
    dp[0] = 0;
    ll now = 0;
    do {
        ll nx = ((now - b) % a + a) % a;
        ll k = max(0LL, (b - now + a - 1) / a);
        dp[nx] = min(dp[nx], max(now + k * a, dp[now]));
        now = nx;
    } while (now != 0);

    ll ans = 0;
    for (ll ph = 0; ph < a; ph++) {
        if (m < dp[ph]) continue;
        auto solve = [&](ll z) {
            if (z <= ph) return 0LL;
            ll sm = (z - ph) % a * ((z - ph) / a + 1);
            z = (z - ph) / a;
            sm += a * (z + 1) * z / 2;
            return sm;
        };
        show(ph);
        show(solve(m + 1));
        show(solve(dp[ph]));
        ans += solve(m + 1) - solve(dp[ph]);
    }
    show(dp);
    cout << ans << endl;
    return 0;
}