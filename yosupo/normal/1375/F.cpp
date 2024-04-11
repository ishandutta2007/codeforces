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

int get() {
    int x;
    cin >> x;
    return x - 1;
}
int main() {
    V<ll> v(3);
    cin >> v[0] >> v[1] >> v[2];

    cout << "First" << endl;
    cout << TEN(10) << endl;
    v[get()] += TEN(10);
    ll ma = 0;
    for (int i = 0; i < 3; i++) {
        ma = max(ma, v[i]);
    }
    V<ll> vs;
    for (int i = 0; i < 3; i++) {
        vs.push_back(ma - v[i]);
    }
    sort(vs.begin(), vs.end());
    ll x = vs[1], y = vs[2];
    // big ... big - x ... big - y
    cout << x + y << endl;
    v[get()] += x + y;
    // big + y ... big ... big - y, or 
    // big + x ... big ... big - x
    ma = 0;
    ll mi = TEN(18);
    for (int i = 0; i < 3; i++) {
        ma = max(ma, v[i]);
        mi = min(ma, v[i]);
    }

    cout << (ma - mi) / 2 << endl;
    assert(get() == -1);
    return 0;
}