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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);
    int n;
    cin >> n;
    V<int> a(n);
    V<int> g[30];
    for (int b = 0; b < 30; b++) {
        g[b].push_back(-1);
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        for (int b = 0; b < 30; b++) {
            if (a[i] & (1<<b)) g[b].push_back(i);
        }
    }
    for (int b = 0; b < 30; b++) {
        g[b].push_back(n);
    }

    V<int> idx(n);
    iota(begin(idx), end(idx), 0);
    sort(begin(idx), end(idx), [&](int x, int y){
        if (a[x] != a[y]) return a[x] > a[y];
        return x > y;
    });
    set<int> s;
    s.insert(-1);
    s.insert(n);

    ll sm = 0;
    for (int i: idx) {
        //add a[i] -> i
        auto it = s.lower_bound(i);
        int R = *it; it--;
        int L = *it;
        int l = L, r = R;
        for (int b = 0; b < 30; b++) {
            if (a[i] & (1<<b)) continue;
            auto it = lower_bound(begin(g[b]), end(g[b]), i);
            r = min(r, *it);
            it--;
            l = max(l, *it);
        }
        s.insert(i);
        sm += ll(i-L)*ll(R-i);
        sm -= ll(i-l)*ll(r-i);
    }
    cout << sm << endl;
    return 0;
}