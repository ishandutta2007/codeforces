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

    string s;
    cin >> s;
    int cnt0 = 0, cnt1 = 0;
    for (char c: s) {
        if (c == '0') {
            if (!cnt0) {
                cout << 1 << " " << 1 << endl;
            } else {
                cout << 3 << " " << 1 << endl;
            }
            cnt0++;
            cnt0 %= 2;
        } else {
            cout << cnt1 + 1 << " " << 2 << endl;
            cnt1++;
            cnt1 %= 4;
        }
    }
    return 0;
}