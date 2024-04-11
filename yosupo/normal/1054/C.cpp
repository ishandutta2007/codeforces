#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;

int main() {
    int n;
    cin >> n;
    V<int> l(n), r(n), x(n);
    for (int i = 0; i < n; i++) cin >> l[i];
    for (int i = 0; i < n; i++) cin >> r[i];
    for (int i = 0; i < n; i++) x[i] = n - l[i] - r[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j || x[j] <= x[i]) continue;
            if (j < i) l[i]--;
            else r[i]--;
        }
        if (l[i] || r[i]) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    for (int d: x) {
        cout << d << " ";
    }
    cout << endl;
    return 0;
}