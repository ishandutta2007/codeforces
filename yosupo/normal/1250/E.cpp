//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx")
//#undef LOCAL
#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;

#ifdef LOCAL
struct PrettyOS {
    ostream& os;
    bool first;
    template <class T> auto operator<<(T&& x) {
        if (!first) os << ", ";
        first = false;
        os << x;
        return *this;
    }
};
template <class... T> void dbg0(T&&... t) {
    (PrettyOS{cerr, true} << ... << t);
}
#define dbg(...)                                            \
    do {                                                    \
        cerr << __LINE__ << " : " << #__VA_ARGS__ << " = "; \
        dbg0(__VA_ARGS__);                                  \
        cerr << endl;                                       \
    } while (false);
#else
#define dbg(...)
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

ll solve(ll up0, ll up1) {
    array<ll, 4> dp = {};
    dp[3] = 1;
    for (int h = 32; h >= 0; h--) {
        array<ll, 4> ndp = {};
        int x0 = (up0 >> h) & 1;
        int x1 = (up1 >> h) & 1;
        for (int f = 0; f <= 3; f++) {
            for (int g = 0; g <= 2; g++) {
                int bf0 = f & 1;
                int nf0 = g & 1;
                int bf1 = (f >> 1) & 1;
                int nf1 = (g >> 1) & 1;

                if (x0 == 0 && bf0 && nf0 == 1) continue;
                if (x1 == 0 && bf1 && nf1 == 1) continue;

                int nf = 0;
                if (bf0 && x0 == nf0) nf |= 1;
                if (bf1 && x1 == nf1) nf |= 2;

                ndp[nf] += dp[f];
            }
        }
        dp = ndp;
    }
    dbg(up0, up1, dp[0]);
    return dp[0];
}
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        ll l, r;
        cin >> l >> r; r++;
        ll ans = 0;
        ans += solve(r, r);
        ans -= 2 * solve(l, r);
        ans += solve(l, l);
        cout << ans << endl;
    }
    return 0;
}