#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    V<int> sm(1000);
    for (int i = 0; i < n; i++) {
        int r;
        cin >> r;
        for (int j = 0; j < r; j++) {
            int x;
            cin >> x; sm[x]++;
        }
    }
    V<int> ans;
    for (int i = 0; i < 1000; i++) {
        if (sm[i] == n) ans.push_back(i);
    }
    for (int d: ans) {
        cout << d << " ";
    } cout << endl;
    return 0;

}