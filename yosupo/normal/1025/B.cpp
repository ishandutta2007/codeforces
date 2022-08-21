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

V<int> f(int x) {
    V<int> v;
    for (int i = 1; i * i <= x; i++) {
        if (x % i) continue;
        v.push_back(i);
        v.push_back(x / i);
    }
    return v;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int n;
    cin >> n;
    V<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    auto va = f(a[0]), vb = f(b[0]);
    for (int d: vb) va.push_back(d);
    sort(va.begin(), va.end());
    va.erase(unique(va.begin(), va.end()), va.end());
    for (int d: va) {
        if (d == 1) continue;
        bool ok = true;
        for (int i = 0; i < n; i++) {
            if (a[i] % d && b[i] % d) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << d << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}