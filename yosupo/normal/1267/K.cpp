#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }
#define FOR(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, N) for (int i = 0; i < (int)(N); i++)
#define rep1(i, N) for (int i = 1; i <= (int)(N); i++)
#define fs first
#define sc second
#define eb emplace_back
#define pb push_back
#define all(x) x.begin(), x.end()
template <class T, class U> void chmin(T& t, const U& u) { if (u < t) t = u; }
template <class T, class U> void chmax(T& t, const U& u) { if (t < u) t = u; }

#ifdef LOCAL
#define show(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl
#else
#define show(x)
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

ll calc(V<ll> on) {
    int n = int(on.size());
    ll ans = 1;
    ll cnt = 0;
    for (int i = 0; i < n - 1; i++) {
        cnt += on[i];
        if (i) {
            if (cnt == 0) return 0;
            ans *= cnt;
            cnt--;
        }
    }
    show(ans);
    return ans;
}

ll solve(V<ll> v) {
    int n = int(v.size());
    V<ll> on(n + 1);
    for (auto d: v) {
        on[d]++;
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        if (!on[i]) continue;
        on[i]--;
        show(on);
        ans += calc(on) * (1 + on[i]);
        on[i]++;
    }
    for (int i = 0; i <= n; i++) {
        ll u = 1;
        for (int j = 1; j <= on[i]; j++) {
            u *= j;
        }
        assert(ans % u == 0);
        show(u);
        ans /= u;
    }
    return ans;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        ll x;
        cin >> x;
        V<ll> v;
        for (int j = 2; j <= 100; j++) {
            v.push_back(x % j);
            x /= j;
            if (x == 0) break;
        }
        show(v);
        cout << solve(v) - 1 << "\n";
//        solve();
    }
    return 0;
}