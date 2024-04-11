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

    int n, m;
    cin >> n >> m;
    if (m == n * (n-1) / 2) {
        cout << 0 << endl;
        return 0;
    }

    V<int> g(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b; a--; b--;
        g[a] |= (1<<b);
        g[b] |= (1<<a);
    }

    int ans = 1000, af = 0;
    for (int f = 1; f < (1<<n); f++) {
        int near = f;
        for (int i = 0; i < n; i++) {
            if (!(f & (1<<i))) continue;
            near |= g[i];
        }
        if (near != (1<<n)-1) continue;

        int fi = __builtin_ctz(f);
        int can = (1<<fi);
        int vis = 0;
        while (vis != can) {
            int i = __builtin_ctz(vis ^ can);
            vis |= (1<<i);
            can |= g[i] & f;
        }
        if (can != f) continue;

        int nans = __builtin_popcount(f);
        if (nans < ans) {
            ans = nans;
            af = f;
        }
    }

    cout << ans << endl;

    V<int> q;
    int fi = __builtin_ctz(af);
    int can = (1<<fi);
    int vis = 0;
    while (vis != can) {
        int i = __builtin_ctz(vis ^ can);
        q.push_back(i);
        vis |= (1<<i);
        can |= g[i] & af;
    }

    for (int d: q) {
        cout << d+1 << " ";
    }
    cout << endl;

    return 0;
}