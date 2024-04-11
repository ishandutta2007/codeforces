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

int n;
bool er;
V<int> a, p;
void dfs(int le, int ri, int dw, int up) {
//    show(to_string(le) + to_string(dw) + to_string(up));
    if (le >= ri) return;
    if (a[le] == -1) {
        p[le] = up - 1;
        dfs(le + 1, ri, dw, up - 1);
        return;
    }
    if (ri < a[le]) {
        er = true;
        return;
    }
    p[le] = dw + (a[le] - le) - 1;
    dfs(a[le], ri, p[le] + 1, up);
    dfs(le + 1, a[le], dw, p[le]);
}

void solve() {
    cin >> n;
    a = V<int>(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] != -1) a[i]--;
    }
    p = V<int>(n);
    er = false;
    dfs(0, n, 0, n);
    if (er) {
        cout << -1 << endl;
        return;
    }
    for (int d: p) {
        cout << d + 1 << " ";
    }
    cout << endl;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) solve();
    return 0;
}