#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int ma = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (ma < x) {
            cout << i+1 << endl;
            return 0;
        }
        ma = max(ma, x+1);
    }
    cout << -1 << endl;
    return 0;
}