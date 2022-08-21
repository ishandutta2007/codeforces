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

bool check(V<int> s, V<int> ty) {
    int n = int(s.size());
    V<int> v;
    for (int i = 0; i < n; i++) {
        if (ty[i] == 1) v.push_back(s[i]);
    }
    for (int i = 0; i < n; i++) {
        if (ty[i] == 2) v.push_back(s[i]);
    }
    for (int i = 0; i < n - 1; i++) {
        if (v[i] > v[i + 1]) return false;
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    string _s;
    cin >> _s;
    V<int> s;
    for (auto c: _s) s.push_back(c - '0');
    V<int> ty(n);
    int ma = -1;
    for (int i = 0; i < n; i++) {
        if (ma > s[i]) ty[i] = 1;
        ma = max(ma, s[i]);        
    }
    int mi = 10;
    for (int i = n - 1; i >= 0; i--) {
        if (mi < s[i]) ty[i] = 2;
        mi = min(mi, s[i]);
    }
    bool two = false;
    for (int i = 0; i < n; i++) {
        if (ty[i] == 2) two = true;
        if (ty[i]) continue;
        ty[i] = two ? 2 : 1;
    }

//    dbg(s);
//    dbg(ty);

    if (!check(s, ty)) {
        cout << "-" << endl;
        return;
    }
    for (int d: ty) cout << d;
    cout << endl;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int t;
    cin >> t;
    for (int ph = 0; ph < t; ph++) {
        solve();
    }
    return 0;
}