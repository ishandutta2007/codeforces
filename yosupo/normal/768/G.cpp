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
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;
constexpr ll TEN(int n) { return (n==0) ? 1 : 10*TEN(n-1); }
int bsr(int x) { return 31 - __builtin_clz(x); }
int bsr(ll x) { return 63 - __builtin_clzll(x); }
int bsf(int x) { return __builtin_ctz(x); }
int bsf(ll x) { return __builtin_ctzll(x); }

int n, r;
VV<int> g;

using P = pair<int, int>; //max, second max
V<int> sz;
V<int> minsz;
V<P> dp;
V<bool> par_max; //is parent max?

void ins(P &p, int x) {
    if (p.first < x) {
        p.second = p.first;
        p.first = x;
    } else if (p.second < x) {
        p.second = x;
    }
}

void first(int p) {
    minsz[p] = TEN(8);
    dp[p] = P(-TEN(8), -TEN(8));
    sz[p] = 1;
    for (int d: g[p]) {
        first(d);
        sz[p] += sz[d];
        minsz[p] = min(minsz[p], sz[d]);
        ins(dp[p], sz[d]);
    }
    int psz = n - sz[p];
    if (psz == 0) return;
    minsz[p] = min(minsz[p], psz);
    ins(dp[p], psz);
    par_max[p] = (dp[p].first == psz);
}


template<class T>
int mid(const T &s, int di) {
    int la = -TEN(8), ra = TEN(8);
    assert(s.size());
    auto it = s.lower_bound((di+1)/2);
    if (it != s.end()) {
        ra = *it;
    }
    if (it != s.begin()) {
        it--;
        la = *it;
    }
    if (2*ra-di < di-2*la) return ra;
    return la;
}

V<int> res;

set<int> dfs1(int p) {
    set<int> u;
    int di = dp[p].first-minsz[p];
    int z = TEN(8);
    for (int d: g[p]) {
        auto v = dfs1(d);
        if (!par_max[p] && dp[p].first == sz[d]) {
            z = mid(v, di);
        }
        if (u.size() < v.size()) swap(u, v);
        for (int d: v) u.insert(d);
    }
    if (!par_max[p]) {
        res[p] = min(res[p], max(dp[p].second, max(dp[p].first-z, minsz[p]+z)));
    }
    u.insert(sz[p]);
    return u;
}

multiset<int> buf;
void dfs(int p) {
    int di = dp[p].first-minsz[p];
    if (par_max[p] && buf.size()) {
        int z = mid(buf, di);
        res[p] = min(res[p], max(dp[p].second, max(dp[p].first-z, minsz[p]+z)));
    }
    for (int d: g[p]) {
        dfs(d);
    }
    buf.insert(sz[p]);
}

void dfs_front(int p) {
    int di = dp[p].first+minsz[p];
    if (par_max[p] && buf.size()) {
        int z = mid(buf, di);
        res[p] = min(res[p], max(dp[p].second, max(z, dp[p].first-z+minsz[p])));
    }
    for (int d: g[p]) {
        buf.insert(n-sz[p]);
        dfs_front(d);
        buf.erase(buf.find(n-sz[p]));
    }
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);
    cin >> n;
    g = VV<int>(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b; a--; b--;
        if (a != -1) {
            g[a].push_back(b);
        } else {
            r = b;
        }
    }
    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }
    sz = V<int>(n);
    res = V<int>(n, TEN(8));
    minsz = V<int>(n);
    dp = V<P>(n);
    par_max = V<bool>(n);
    first(r);

//    for (int i = 0; i < n; i++) {
//        cout << minsz[i] << " " << dp[i].first << " " << dp[i].second << endl;
//    }
    dfs1(r);
    dfs_front(r);
    buf.clear(); dfs(r);
    for (int i = 0; i < n; i++) {
        reverse(begin(g[i]), end(g[i]));
    }
    buf.clear(); dfs(r);
    for (int i = 0; i < n; i++) {
        if (dp[i].first == minsz[i]) res[i] = minsz[i];
        if (dp[i].first == dp[i].second) res[i] = dp[i].second;
        res[i] = min(res[i], dp[i].first);
    }
    for (int i = 0; i < n; i++) {
        cout << res[i] << " ";
    } cout << endl;
    return 0;
}