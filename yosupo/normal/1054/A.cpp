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
    cout << setprecision(20);
    int x, y, z, t1, t2, t3;
    cin >> x >> y >> z >> t1 >> t2 >> t3;
    int e = abs(x - y) * t1;
    int f = abs(x - z) * t2 + t3 + t3 + abs(x - y) * t2 + t3;
    //cout << e << " " << f << endl;
    if (f <= e) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}