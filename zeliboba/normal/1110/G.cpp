#include <stdio.h>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <complex>
#include <map>
#include <unordered_map>
#include <queue>
#include <array>
#include <bitset>
#include <chrono>
#include <random>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef long double ld;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;
//const int mod = ;

void dfs(int v, int color, const vvi& g, vi& col) {
  if (col[v]) return;
  col[v] = color;
  for (int nv : g[v]) dfs(nv, 3 - color, g, col);
}

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int T;
  cin >> T;
  for (int test = 1; test <= T; ++test) {
    int n;
    cin >> n;
    vvi g(n);
    for (int i = 0; i < n - 1; ++i) {
      int a, b;
      cin >> a >> b;
      --a; --b;
      g[a].push_back(b);
      g[b].push_back(a);
    }
    string s;
    cin >> s;
    vi w(n);
    for (int i = 0; i < n; ++i) w[i] = s[i] == 'W';
    if (n <= 2) {
      cout << "Draw\n"; continue;
    }
    bool win = false;
    for (int v = 0; v < n; ++v) if (w[v]) {
      int cur = v;
      vi was(n);
      was[cur] = 1;
      while (!win) {
        int cnt = 0, c2 = 0, wasw = false;
        for (int nv : g[cur]) {
          if (!was[nv]) {
            if (w[nv] && g[nv].size() >= 2) {
              win = true; break;
            }
            if (w[nv]) wasw = true;
            cnt += 1;
            if (g[nv].size() >= 3) win = true;
            if (g[nv].size() == 2) {
              ++c2;
              for (int v2 : g[nv]) if (!was[v2] && w[v2]) win = true;
            }
          }
        }
        if (cnt >= 3 || (cnt == 2 && c2 > 0) || (wasw && cnt >= 2)) {
          win = true; break;
        }
        if (c2 == 0) break;
        for (int nv : g[cur]) {
          if (!was[nv] && g[nv].size() == 2) {
            for (int v2 : g[nv]) if (!was[v2]) {
              was[nv] = was[v2] = 1;
              cur = v2;
              break;
            }
          }
        }
      }
      break;
    }
    for (int v = 0; v < n && !win; ++v) {
      if (g[v].size() > 3) {
        win = true; break;
      }
    }
    for (int v = 0; v < n && !win; ++v) {
      if (g[v].size() == 3) {
        int cnt = 0;
        for (int nv : g[v]) {
          if (g[nv].size() >= 2) {
            ++cnt;
            for (int v2 : g[nv]) if (v2 != v) {
              if (g[v2].size() >= 3) win = true;
            }
          }
        }
        if (cnt >= 2) {
          win = true; break;
        }
      }
    }
    vi col(n);
    dfs(0, 1, g, col);
    vi c(3);
    for (int v = 0; v < n && !win; ++v) {
      if (g[v].size() == 3) {
        ++c[col[v]];
      }
    }
    if (win || c[1] > 1 || c[2] > 1) {
      cout << "White\n"; continue;
    } else {
      cout << "Draw\n"; continue;
    }
  }
  return 0;
}