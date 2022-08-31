#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <numeric>
#include <random>
#include <vector>
#include <array>
#include <bitset>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n==0) ? 1 : 10*TEN(n-1); }
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);
    int n, k;
    cin >> n >> k;
    V<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i]; a[i]--;
    }

    V<int> tar(k);
    for (int i = 0; i < k; i++) cin >> tar[i];
    for (int l = 0; l < n; l++) {
        for (int r = l+1; r <= n; r++) {
            V<int> cnt(k);
            for (int i = l; i < r; i++) cnt[a[i]]++;
            if (tar == cnt) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}