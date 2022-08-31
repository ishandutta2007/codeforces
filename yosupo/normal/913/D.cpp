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

struct rng {
    struct A {
        int n;
        const bool operator!=(A r) { return n != r.n; }
        A& operator++() { n++; return *this; }
        int operator*() { return n; }
    };
    int l, r;
    rng(int r) : l(0), r(max(0, r)) {}
    rng(int l, int r) : l(l), r(max(l, r)) {}
    A begin() { return A{l}; }
    A end() { return A{r}; }
};

struct P {
    int first, second, idx;
};

int n, t;
V<P> v;

V<int> res;
bool calc(int md) {
    res.clear();
    V<P> nv;
    for (P p: v) {
        if (p.first < md) continue;
        nv.push_back(p);
    }
    if (nv.size() < md) return false;
    sort(begin(nv), end(nv), [&](P l, P r){
        return l.second < r.second;
    });
    int sm = 0;
    for (int i = 0; i < md; i++) {
        sm += nv[i].second;
        res.push_back(nv[i].idx);
    }
    return sm <= t;
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);

    cin >> n >> t;
    v = V<P>(n);
    for (int i = 0; i < n; i++) {
        int a, t;
        cin >> a >> t;
        v[i] = P{a, t, i+1};
    }

    int l = 0, r = n+1;
    while (r-l > 1) {
        int md = (l+r)/2;

        if (calc(md)) {
            l = md;
        } else {
            r = md;
        }
    }
    calc(l);
    cout << l << endl;
    cout << l << endl;
    for (int d: res) {
        cout << d << " ";
    }
    cout << endl;
    return 0;
}