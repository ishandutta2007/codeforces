//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx")
//#undef LOCAL




#include <algorithm>

#include <array>

#include <bitset>

#include <cassert>

#include <complex>

#include <cstdio>

#include <cstring>

#include <iostream>

#include <map>

#include <numeric>

#include <queue>

#include <set>

#include <string>

#include <unordered_map>

#include <unordered_set>

#include <vector>

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

    if (n % 2 == 0) {
        cout << "First" << endl;
        for (int i = 0; i < 2 * n; i++) {
            cout << i % n + 1 << " ";
        }
        cout << endl;
        int x;
        cin >> x;
        assert(x == 0);
        return 0;
    }


    cout << "Second" << endl;
    V<int> id(2 * n);
    V<int> to(n);
    for (int i = 0; i < 2 * n; i++) {
        cin >> id[i];
        id[i]--;
        to[id[i]] ^= i;
    }

    V<int> vis(2 * n);
    V<int> used(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        int j = i;
        while (!vis[j]) {
            vis[j] = true;
            used[j] = true;
            j = (j < n ? j + n : j - n);
            vis[j] = true;
            j ^= to[id[j]];
        }
    }
                  ;
    int sum = 0;
    for (int i = 0; i < 2 * n; i++) {
        if (used[i]) {
            sum += (i + 1);
            sum %= 2 * n;
        }
    }
    if (sum) {
        for (auto &x: used) x = 1 - x;
    }

    for (int i = 0; i < 2 * n; i++) {
        if (used[i]) {
            cout << i + 1 << " ";
        }
    }
    cout << endl;
    return 0;
}