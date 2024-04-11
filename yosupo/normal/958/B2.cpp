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

int n;
VV<int> g;

int md, mp;
void dfs(int p, int b = -1, int ndp = 0) {
    if (md < ndp) {
        md = ndp;
        mp = p;
    }
    for (int d: g[p]) {
        if (d == b) continue;
        dfs(d, p, ndp+1);
    }
}

V<int> buf;
using S = multiset<int, greater<int>>;

S* dfs2(int p, int b = -1) {
    if (b != -1 && g[p].size() == 1) {
        return new S({1});
    }
    auto s = new S();
    for (int d: g[p]) {
        if (d == b) continue;
        auto t = dfs2(d, p);
        if (s->size() < t->size()) swap(s, t);
        for (auto x: *t) s->insert(x);
    }
    if (b != -1) {
        int v = *(s->begin());
        s->erase(s->begin());
        s->insert(v+1);
    }
    return s;
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);

    cin >> n;
    g = VV<int>(n);
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b; a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    if (n == 1) {
        cout << "1" << endl;
        return 0;
    }

    md = -1; dfs(0);
    int u = mp;

    auto s = dfs2(u);

    V<int> buf; buf.push_back(1);
    for (int d: *s) {
        int x = buf.back() + d;
        buf.push_back(x);
    }
    while (buf.size() < n) {
        int x = buf.back();
        buf.push_back(x);
    }

    for (int d: buf) {
        cout << d << " ";
    }
    cout << endl;
    return 0;
}