#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }

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

void solve() {
    int n;
    cin >> n;

    int ans = -1;
    for (int ph = 0; ph < 9; ph++) {
        V<int> a, b;
        for (int i = 0; i < n; i++) {
            if (i & (1<<ph)) a.push_back(i);
            else b.push_back(i);
        }
        if (a.empty() || b.empty()) continue;
        cout << a.size() << " " << b.size();
        for (int d : a) cout << " " << d + 1;
        for (int d : b) cout << " " << d + 1;
        cout << endl;

        int x;
        cin >> x;
        ans = max(ans, x);
    }
    cout << -1 << " " << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) solve();
    return 0;
}