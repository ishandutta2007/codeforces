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


//bit op
int bsr(uint x) { return 31 - __builtin_clz(x); }
int bsr(ull x) { return 63 - __builtin_clzll(x); }
int bsf(uint x) { return __builtin_ctz(x); }
int bsf(ull x) { return __builtin_ctzll(x); }

template<class T>
struct Fenwick {
    int N, lg;
    V<T> seg;
    Fenwick() {}
    Fenwick(int N) : N(N) {
        seg.resize(N+1);
        lg = bsr(uint(N));
        fill(begin(seg), end(seg), T(0));
    }
    /// ix
    void add(int i, T x) {
        i++;
        while (i <= N) {
            seg[i] += x;
            i += i & -i;
        }
    }
    /// [0, i)sum
    T sum(int i) {
        T s{0};
        while (i > 0) {
            s += seg[i];
            i -= i & -i;
        }
        return s;
    }
    /// [a, b)sum
    T sum(int a, int b) {
        return sum(b) - sum(a);
    }
    /// sum[0, idx) >= xidx
    int sum_lower_bound(T x) {
        if (x <= 0) return 0;
        int res = 0;
        for (int len = 1<<lg; len >= 1; len /= 2) {
            if (res + len <= N && seg[res + len] < x) {
                x -= seg[res+len];
                res += len;
            }
        }
        return res + 1;
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);

    int n;
    cin >> n;

    V<ll> a;
    map<int, V<ll>> mp;
    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        a.push_back(c);
        mp[c].push_back(i);
    }

    Fenwick<int> fw(2*n);
    for (int i = 0; i < 2*n; i++) fw.add(i, 1);
    sort(begin(a), end(a));
    a.erase(unique(begin(a), end(a)), end(a));
    
    ll sm = 0;
    int po = 0;
    for (int d: a) {
        auto v = mp[d];
        auto it = lower_bound(begin(v), end(v), po);
        int ba;
        if (it == begin(v)) ba = v.back();
        else {
            it--; ba = *it;
        }
        if (ba < po) ba += n;
        sm += fw.sum(po, ba+1);
        po = ba % n;
        for (int d: v) {
            fw.add(d, -1); fw.add(n+d, -1);
        }
    }
    cout << sm << endl;
    return 0;
}