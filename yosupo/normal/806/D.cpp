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

#define tm f__k
using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n==0) ? 1 : 10*TEN(n-1); }
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;

int bsr(uint x) { return 31 - __builtin_clz(x); }
int bsr(ull x) { return 63 - __builtin_clzll(x); }
int bsf(uint x) { return __builtin_ctz(x); }
int bsf(ull x) { return __builtin_ctzll(x); }

const int MN = 2020;
int n;
ll g[MN][MN];
ll ans[MN];

void calc(int r) {
    ll dist[MN];
    fill(dist, dist+MN, TEN(18));
    dist[r] = 0;
    for (int i = 0; i < n; i++) {
        if (i == r) continue;
        for (int j = 0; j < n; j++) {
            if (j == r || i == j) continue;
            dist[j] = min(dist[j], 2*g[i][j]);
        }
    }
    bool used[MN] = {};
    while (true) {
        ll mi = TEN(18), midx = -1;
        for (int i = 0; i < n; i++) {
            if (used[i]) continue;
            if (dist[i] < mi) {
                mi = dist[i];
                midx = i;
            }
        }
        if (midx == -1) break;
        int i = midx;
        used[i] = true;
        for (int j = 0; j < n; j++) {
            dist[j] = min(dist[j], dist[i]+g[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        ans[i] = min(ans[i], dist[i]);
    }
/*    for (int i = 0; i < n; i++) {
        cout << dist[i] << ", ";
    }
    cout << endl;*/
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);
    cin >> n;
    for (int i = 0; i < n; i++) {
        g[i][i] = 0;
        for (int j = i+1; j < n; j++) {
            ll x;
            cin >> x;
            g[i][j] = g[j][i] = x;
        }
    }

    ll mi = TEN(18);
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            mi = min(mi, g[i][j]);
        }
    }

    int a;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (g[i][j] == mi) {
                a = i;
            }
            g[i][j] -= mi;
            g[j][i] -= mi;
        }
    }
    for (int i = 0; i < n; i++) {
        ans[i] = TEN(18);
    }
    calc(a);

    for (int i = 0; i < n; i++) {
        cout << ans[i] + mi * (n-1) << endl;
    }
    return 0;
}