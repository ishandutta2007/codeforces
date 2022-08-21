#pragma GCC optimize("Ofast")
#pragma GCC target("avx,tune=native")
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

// bit op
int popcnt(uint x) { return __builtin_popcount(x); }
int popcnt(ull x) { return __builtin_popcountll(x); }
int bsr(uint x) { return 31 - __builtin_clz(x); }
int bsr(ull x) { return 63 - __builtin_clzll(x); }
int bsf(uint x) { return __builtin_ctz(x); }
int bsf(ull x) { return __builtin_ctzll(x); }

void solve() {
    int n, m;
    cin >> n >> m;
//    n = 12; m = 2000;
    VV<int> mp(m, V<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mp[j][i];
            // mp[j][i] = rand() % 100000;
        }
    }    
    sort(mp.begin(), mp.end(), [&](const V<int>& a, const V<int>& b) {
        int am = 0, bm = 0;
        for (int d: a) am = max(am, d);
        for (int d: b) bm = max(bm, d);
        return am > bm;
    });
    mp.resize(min(int(mp.size()), n)); // unti de gozaimasu

    V<int> base;

    for (int f = 0; f < (1 << n); f++) {
        int mi = f;
        int f2 = f;
        for (int i = 0; i < n; i++) {
            mi = min(mi, f2);
            if (f2 & 1) f2 |= (1 << n);
            f2 >>= 1;
        }
        base.push_back(mi);
    }

    sort(base.begin(), base.end());
    base.erase(unique(base.begin(), base.end()), base.end());


    V<int> dp(1 << n, 0);
    for (auto v: mp) {
        for (int i = 0; i < n; i++) {
            for (int fr = 0; fr < (1 << n); fr += (1 << (i + 1))) {
                for (int fl = 0; fl < (1 << i); fl++) {
                    int to = fl | (1 << i) | fr;
                    int from = fl | fr;
                    dp[to] = max(dp[to], dp[from] + v[i]);
                }
            }
        }

        for (int f2: base) {
            int ma = 0;
            for (int i = 0; i < n; i++) {
                ma = max(ma, dp[f2]);
                if (f2 & 1) f2 |= (1 << n);
                f2 >>= 1;
            }
            for (int i = 0; i < n; i++) {
                dp[f2] = ma;
                if (f2 & 1) f2 |= (1 << n);
                f2 >>= 1;
            }
        }
    }
    cout << dp[(1 << n) - 1] << endl;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int t;
    cin >> t;
    // t = 40;
    for (int ph = 0; ph < t; ph++) {
        solve();
    }
    return 0;
}