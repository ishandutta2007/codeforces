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
    V<int> av;
    av = a;
    sort(av.begin(), av.end());
    av.erase(unique(av.begin(), av.end()), av.end());
    int m = int(av.size());
    for (int i = 0; i < n; i++) {
        a[i] = int(lower_bound(av.begin(), av.end(), a[i]) - av.begin());
    }
    V<int> le(m, n), ri(m, -1);
    for (int i = 0; i < n; i++) {
        le[a[i]] = min(le[a[i]], i);
        ri[a[i]] = max(ri[a[i]], i);
    }
    int ans = 0;
    int l = 0;
    while (l < m) {
        int r = l + 1;
        while (r < m && ri[r - 1] < le[r]) r++;
        ans = max(ans, r - l);
        l = r;
    }
    cout << m - ans << endl;
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