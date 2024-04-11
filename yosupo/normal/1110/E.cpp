#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20) << fixed;

    int n;
    cin >> n;
    V<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    if (a[0] != b[0]) {
        cout << "No" << endl;
        return 0;
    }
    V<int> c, d;
    for (int i = 0; i < n-1; i++) c.push_back(a[i + 1] - a[i]);
    for (int i = 0; i < n-1; i++) d.push_back(b[i + 1] - b[i]);

    sort(c.begin(), c.end());
    sort(d.begin(), d.end());

    if (c == d) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}