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

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int n; ll k;
    cin >> n >> k; n++;
    V<ll> deg(n);
    for (int i = 0; i < n; i++) cin >> deg[i];
    dbg(deg);
    V<ll> x(n + 1, TEN(18)); x[n] = 0;
    for (int i = n - 1; i >= 0; i--) {
        x[i] = 2 * x[i + 1] + deg[i];
        if (abs(x[i]) > TEN(18)) break;
    }
    dbg(x);
    ll ans = 0;
    ll le = 0;
    for (int i = 0; i < n; i++) {
        if (le % 2) break;
        le /= 2;
        ll ri = 2 * x[i + 1];
        // le + z + ri == 0
        ll z = -(le + ri);
        dbg(i, le, z, ri);
        if (abs(z) <= k && (i != n - 1 || z)) ans++;
        le += deg[i];
    }

    cout << ans << endl;
    return 0;
}