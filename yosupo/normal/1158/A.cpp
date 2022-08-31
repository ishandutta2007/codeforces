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
#define show(x) true
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

    int n, m;
    cin >> n >> m;
    ll a_sm = 0, b_sm = 0;
    V<ll> a(n), b(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a_sm += a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
        b_sm += b[i];
    }
    sort(a.begin(), a.end(), greater<ll>());
    sort(b.begin(), b.end());

    if (a[0] > b[0]) {
        cout << -1 << endl;
        return 0;
    }

    if (a[0] == b[0]) {
        cout << a_sm * m + b_sm - a[0] * m << endl;
        return 0;
    }

    cout << a_sm * m + b_sm - a[0] * m + (a[0] - a[1]) << endl;

    return 0;
}