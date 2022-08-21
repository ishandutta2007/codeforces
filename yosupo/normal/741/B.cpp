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
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n==0) ? 1 : 10*TEN(n-1); }
int bsr(int x) { return 31 - __builtin_clz(x); }

struct UnionFind {
    vector<int> ig;
    vector<vector<int>> gi;
    int gn;
    UnionFind(int N) {
        ig.resize(N); gi.resize(N);
        for (int i = 0; i < N; i++) {
            ig[i] = i; gi[i] = {i};
        }
        gn = N;
    }
    void merge(int a, int b) {
        if (same(a, b)) return;
        gn--;
        int x = ig[a], y = ig[b];
        if (gi[x].size() < gi[y].size()) swap(x, y);
        for (int j: gi[y]) {
            ig[j] = x;
        }
        gi[x].insert(gi[x].end(), gi[y].begin(), gi[y].end());
        gi[y].clear();
    }
    bool same(int a, int b) {
        return ig[a] == ig[b];
    }
};

const int MW = 1010;



int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);
    int n, m, W;
    cin >> n >> m >> W;
    UnionFind uf(n);
    int w[n];
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }

    ll b[n];
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b; a--; b--;
        uf.merge(a, b);
    }

    vector<ll> dp1(MW), dp2(MW);
    for (int i = 0; i < n; i++) {
        auto v = uf.gi[i];
        if (v.size() == 0) continue;
        dp2 = dp1;
        int sw = 0; ll sb = 0;
        for (int d: v) {
            int nw = w[d];
            ll nb = b[d];
            sw += nw; sb += nb;

            for (int j = nw; j < MW; j++) {
                dp2[j] = max(dp2[j], dp1[j-nw]+nb);
            }
        }

        for (int j = sw; j < MW; j++) {
            dp2[j] = max(dp2[j], dp1[j-sw]+sb);
        }

        dp1 = dp2;
    }

    cout << dp1[W] << endl;
    return 0;
}