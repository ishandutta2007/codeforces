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
    int n;
    cin >> n;
    map<int, V<int>> mp;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        x = n - x;
        mp[x].push_back(i);
    }
    V<int> col(n, -1);
    int id = 1;
    for (auto p: mp) {
        int m = p.first;
        auto v = p.second;
        int k = int(v.size());
        if (k % m) {
            cout << "Impossible" << endl;
            return 0;
        }
        for (int ph = 0; ph < k / m; ph++) {
            for (int i = 0; i < m; i++) {
                col[v[ph * m + i]] = id;
            }
            id++;
        }
    }
    cout << "Possible" << endl;
    for (int d: col) cout << d << " ";
    cout << endl;
    return 0;
}