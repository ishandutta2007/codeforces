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

using P = pair<ll, ll>; // top k, top k-1
struct E {
    int to; ll dist;
};

int k;
VV<E> g;

P solve(int p, int b) {
    ll base = 0;
    V<ll> inc;
    for (auto e: g[p]) {
        int d = e.to;
        if (d == b) continue;
        P dp = solve(d, p);
        ll ex = max(0LL, dp.second + e.dist - dp.first);
        base += dp.first;
        inc.push_back(ex);
    }
    sort(inc.begin(), inc.end(), greater<ll>());
    int m = int(inc.size());    
    for (int i = 0; i < min(m, k - 1); i++) {
        base += inc[i];
    }
    ll ex = (k <= m ? inc[k - 1] : 0LL);
    return {base + ex, base};
}

void solve() {
    int n;
    cin >> n >> k;
    g = VV<E>(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b; ll w;
        cin >> a >> b >> w; a--; b--;
        g[a].push_back({b, w});
        g[b].push_back({a, w});
    }
//    dbg(solve(0, -1));
    cout << solve(0, -1).first << "\n";
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