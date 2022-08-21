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
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n==0) ? 1 : 10*TEN(n-1); }
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;

ll solve() {
    ll x, y, p, q;
    cin >> x >> y >> p >> q;
    if (p == 1 && q == 1) {
        if (x == y) return 0;
        return -1;
    }
    if (p == 0) {
        if (x == 0) return 0;
        return -1;
    }
    ll k = 0;
    k = max(k, (y+q-1)/q);
    k = max(k, (x+p-1)/p);
    k = max(k, (y-x+q-p-1)/(q-p));
    return k*q-y;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cout << solve() << endl;
    }
    return 0;
}