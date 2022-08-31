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
    V<ll> a(n), b(n);
    map<ll, V<int>> mp;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]].push_back(i);
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    V<int> used(n);
    for (auto p: mp) {
        auto v = p.second;
        if (v.size() <= 1) continue;
        for (int i: v) {
            used[i] = true;
        }
    }
    for (int i = 0; i < n; i++) {
        if (used[i]) continue;
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if (!used[j]) continue;
            if (a[i] & ~a[j]) continue;
            used[i] = true;
        }
    }
    ll sm = 0;
    for (int i = 0; i < n; i++) {
        if (used[i]) sm += b[i];
    }

    cout << sm << endl;
    return 0;
}