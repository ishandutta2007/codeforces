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

    int n;
    cin >> n;

    VV<ll> g(n, V<ll>(n, TEN(18)));
    V<ll> di(n, TEN(18));
    V<int> pre(n, -1);

    V<ll> x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }    
    for (int i = 0; i < n; i++) {
        ll c;
        cin >> c;
        di[i] = c;
    }

    V<ll> k(n);
    for (int i = 0; i < n; i++) {
        cin >> k[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ll dis = abs(x[i] - x[j]) + abs(y[i] - y[j]);
            g[i][j] = dis * (k[i] + k[j]);
        }
    }

    
    ll sm = 0;

    V<bool> used(n);
    V<int> use, eu, ev;
    for (int ph = 0; ph < n; ph++) {
        int mi = -1;
        for (int i = 0; i < n; i++) {
            if (used[i]) continue;
            if (mi == -1 || di[i] < di[mi]) mi = i;
        }
        assert(mi != -1 && di[mi] != TEN(18));
        sm += di[mi];
        used[mi] = true;
        if (pre[mi] == -1) {
            use.push_back(mi);
        } else {
            eu.push_back(pre[mi]);
            ev.push_back(mi);
        }

        for (int i = 0; i < n; i++) {
            if (di[i] > g[mi][i]) {
                di[i] = g[mi][i];
                pre[i] = mi;
            }
        }
    }

    cout << sm << endl;
    cout << use.size() << endl;
    for (auto e: use) cout << e + 1 << " ";
    cout << endl;
    int m = int(eu.size());
    cout << m << endl;
    for (int i = 0; i < m; i++) {
        cout << eu[i] + 1 << " " << ev[i] + 1 << endl;
    }
    return 0;
}