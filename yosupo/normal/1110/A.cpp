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

    int b, k;
    cin >> b >> k;
    int sm = 0;
    for (int i = 0; i < k; i++) {
        sm *= b; sm %= 2;
        int x;
        cin >> x;
        sm += x; sm %= 2;
    }
    if (sm) cout << "odd" << endl;
    else cout << "even" << endl;
    return 0;
}