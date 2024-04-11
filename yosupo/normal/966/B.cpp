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

using PV = pair<V<int>, V<int>>;

PV solve(ll x1, ll x2, V<ll> v_) {
    using P = pair<ll, int>;
    int n = int(v_.size());
    V<P> v;
    for (int i = 0; i < n; i++) {
        v.push_back(P(v_[i], i));
    }
    sort(begin(v), end(v), greater<P>());

    for (int i = 1; i <= n; i++) {
        ll z = v[i-1].first;
        ll k2 = (x2+z-1)/z;
        if (i-k2 <= 0) continue;
        // 2: [i-k2, i)
        ll y = v[i-k2-1].first;
        ll k1 = (x1+y-1)/y;
        if (i-k2-k1 < 0) continue;
        // 1: [i-k2-k1, i-k2)
        PV pv;
        for (int j = i-k2-k1; j < i-k2; j++) {
            pv.first.push_back(v[j].second);
        }
        for (int j = i-k2; j < i; j++) {
            pv.second.push_back(v[j].second);
        }
        return pv;
    }
    return PV();
}

void pr(PV pv) {
    V<int> v1, v2;
    tie(v1, v2) = pv;
    cout << "Yes" << endl;
    cout << v1.size() << " " << v2.size() << endl;
    for (auto idx: v1) {
        cout << idx+1 << " ";
    } cout << endl;
    for (auto idx: v2) {
        cout << idx+1 << " ";
    } cout << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);

    int n; ll x1, x2;
    cin >> n >> x1 >> x2;
    V<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    PV res;
    res = solve(x1, x2, v);
    if (res.first.size()) {
        pr(res);
        return 0;
    }
    res = solve(x2, x1, v);
    if (res.first.size()) {
        swap(res.first, res.second);
        pr(res);
        return 0;
    }

    cout << "No" << endl;
    return 0;
}