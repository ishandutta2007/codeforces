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

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

const int MN = 710;
bool dpl[MN][MN], dpr[MN][MN];
bool usl[MN][MN], usr[MN][MN];

int n;
int a[MN];
bool g[MN][MN];

bool soll(int l, int r);
bool solr(int l, int r);

// [l, r], top is l
bool soll(int l, int r) {
    if (l == r) return true;
    if (usl[l][r]) return dpl[l][r];
    usl[l][r] = true;
    bool ok = false;
    for (int i = l + 1; i <= r; i++) {
        if (!g[l][i]) continue;
        if (solr(l + 1, i) && soll(i, r)) {
            ok = true;
            break;
        }
    }
    return dpl[l][r] = ok;
}

bool solr(int l, int r) {
    if (l == r) return true;
    if (usr[l][r]) return dpr[l][r];
    usr[l][r] = true;
    bool ok = false;
    for (int i = l; i < r; i++) {
        if (!g[r][i]) continue;
        if (solr(l, i) && soll(i, r - 1)) {
            ok = true;
            break;
        }
    }
    return dpr[l][r] = ok;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            g[i][j] = (gcd(a[i], a[j]) > 1);
        }
    }

    for (int i = 0; i < n; i++) {
        if (solr(0, i) && soll(i, n - 1)) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}