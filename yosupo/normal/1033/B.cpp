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
#define show(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl
#else
#define show(x)
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

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        ll a, b;
        cin >> a >> b;
        if (a - b > 1) {
            cout << "NO" << endl;
            continue;
        }
        ll c = a + b;
        bool f = true;
        for (ll j = 2; j * j <= c; j++) {
            if (c % j == 0) {
                f = false;
                break;
            }
        }
        if (f) {
            cout << "YES" << endl;
            continue;
        } else {
            cout << "NO" << endl;
        }

    }
    return 0;
}