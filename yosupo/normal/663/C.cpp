#include <iostream>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <vector>
#include <valarray>
#include <array>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <complex>
#include <random>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
template<class T = ll> constexpr T TEN(int n) {return (n==0)?1:10*TEN<T>(n-1);}

template <class E>
using Graph = vector<vector<E>>;

const int MN = 100100;

struct Edge{ int to; char color; };
int n;
Graph<Edge> g;

bool can;
bool used[2][MN];
int co[MN];

vector<int> buf;
void dfs(int p, char base, int c, int idx) {
    if (used[idx][p]) {
        if (co[p] != c) {
            can = false;
        }
        return;
    }
    used[idx][p] = true;
    co[p] = c;
    if (c) {
        buf.push_back(p);
    }
    for (Edge e: g[p]) {
        int cc = c;
        if (e.color != base) {
            cc = 1-cc;
        }
        dfs(e.to, base, cc, idx);
    }
}

vector<int> res;
bool calc(char base) {
    fill_n(used[0], MN, false);
    fill_n(used[1], MN, false);
    res.clear();
    for (int i = 0; i < n; i++) {
        if (used[0][i]) continue;
        can = true; buf.clear();
        int a = TEN(9), b = TEN(9);
        vector<int> v1, v2;
        dfs(i, base, 0, 0);
        if (can) {
            v1 = buf;
            a = v1.size();
        }
        can = true; buf.clear();
        dfs(i, base, 1, 1);
        if (can) {
            v2 = buf;
            b = v2.size();
        }
        if (min(a, b) == TEN(9)) {
            return false;
        }
        vector<int> an;
        if (a < b) {
            an = v1;
        } else {
            an = v2;
        }
        for (int d: an) {
            res.push_back(d);
        }
    }
    return true;
}

int main() {
    int m;
    cin >> n >> m;
    g = Graph<Edge>(n);
    for (int i = 0; i < m; i++) {
        int a, b; char c;
        cin >> a >> b >> c; a--; b--;
        g[a].push_back(Edge{b, c});
        g[b].push_back(Edge{a, c});
    }
    int ans = TEN(9);
    vector<int> av;

    
    if (calc('R') && res.size() < ans) {
        ans = res.size();
        av = res;
    }

    if (calc('B') && res.size() < ans) {
        ans = res.size();
        av = res;
    }

    if (ans == TEN(9)) {
        cout << -1 << endl;
        return 0;
    }
    cout << ans << endl;
    if (av.size()) {
        for (int d: av) {
            cout << d+1 << " ";
        }
        cout << endl;
    }
    return 0;
}