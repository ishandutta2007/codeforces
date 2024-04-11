#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n-1); }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    V<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int ph = 0; ph < (1<<n); ph++) {
        int sm = 0;
        for (int i = 0; i < n; i++) {
            if (ph & (1<<i)) sm += a[i];
            else sm -= a[i];
        }
        sm = (sm % 360 + 360) % 360;
        if (sm == 0) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;

    return 0;
}