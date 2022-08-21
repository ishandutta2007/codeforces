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
    rng(int r) : l(0), r(r) {}
    rng(int l, int r) : l(l), r(r) {}
    A begin() { return A{l}; }
    A end() { return A{r}; }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);
    int n;
    cin >> n;
    V<int> a(n), b(n);
    for (int i: rng(n)) cin >> a[i];
    for (int i: rng(n)) cin >> b[i];
    sort(begin(a), end(a));
    V<int> idx(n);
    iota(begin(idx), end(idx), 0);
    sort(begin(idx), end(idx), [&](int l, int r){ return b[l] < b[r]; });
    V<int> res(n);
    for (int i: rng(n)) {
        res[idx[i]] = a[n-1-i];
    }
    for (int d: res) {
        cout << d << " ";
    }
    cout << endl;
    return 0;
}