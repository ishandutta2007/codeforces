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
    V<ll> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    sort(p.begin(), p.end(), greater<ll>());
    V<ll> psm(n + 1);
    for (int i = 0; i < n; i++) {
        psm[i + 1] = psm[i] + p[i];
    }

    int x, a, y, b;
    cin >> x >> a >> y >> b;
    if (x > y) {
        swap(a, b);
        swap(x, y);
    }

    ll k;
    cin >> k;

    ll per[4] = {0, x, y, x + y};
    int cnt[4] = {};
    for (int i = 0; i < n; i++) {
        int fl = 0;
        if (i % a == a - 1) fl += 1;
        if (i % b == b - 1) fl += 2;
        cnt[fl]++;
        ll now = 0;
        int pos = 0;
        for (int f = 3; f >= 0; f--) {
            now += per[f] * (psm[pos + cnt[f]] - psm[pos]) / 100;
            pos += cnt[f];
        }
        dbg(now);
        if (now >= k) {
            cout << i + 1 << "\n";
            return;
        }
    }
    cout << -1 << "\n";
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