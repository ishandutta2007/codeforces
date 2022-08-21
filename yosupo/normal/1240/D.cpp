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

void solve() {
    int n;
    cin >> n;
    V<int> a(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];        
    }

//    V<int> nx(n);
    V<ll> cnt(n + 1);
    ll ans = 0;
    V<map<int, int>> dp(n + 1);
    for (int l = n - 1; l >= 0; l--) {
        int r = -1;
        if (dp[l + 1].count(a[l])) {
            r = dp[l + 1][a[l]] + 1;
        }
//        nx[l] = r;
        if (r != -1) {
            cnt[l] = cnt[r] + 1;
            ans += cnt[l];
            swap(dp[l], dp[r]);
        }
        dp[l][a[l]] = l;
    }
//    dbg(nx);
    cout << ans << "\n";
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int q;
    cin >> q;
    for (int ph = 0; ph < q; ph++) {
        solve();
    }
    return 0;
}