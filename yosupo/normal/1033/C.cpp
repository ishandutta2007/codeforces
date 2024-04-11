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

    int n;
    cin >> n;
    V<int> a(n);
    V<int> pos(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }

    V<int> win(n);
    for (int d = n; d >= 1; d--) {
        int i = pos[d];
        for (int j = i + d; j < n; j += d) {
            if (a[i] < a[j] && !win[j]) {
                win[i] = 1;
                break;
            }
        }
        for (int j = i - d; j >= 0; j -= d) {
            if (a[i] < a[j] && !win[j]) {
                win[i] = 1;
                break;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (win[i]) cout << "A";
        else cout << "B";
    }
    cout << endl;
    return 0;
}