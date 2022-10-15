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
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;
const int mod = 1e9 + 7;

vi tovi(int x) {
  if (x < 10) return vi(1, x);
  vi v;
  while (x) {
    v.push_back(x % 10);
    x /= 10;
  }
  reverse(v.begin(), v.end());
  return v;
}

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<array<vi, 10>> g(n + 5 * m);
  int it = n;
  for (int i = 1; i <= m; ++i) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    if (i < 10) {
      g[a][i].emplace_back(b);
      g[b][i].emplace_back(a);
    } else {
      vi v = tovi(i);
      for (int x : {a, b}) {
        int y = x == a ? b : a;
        g[x][v[0]].emplace_back(it);
        for (int j = 0; j + 2 < v.size(); ++j) {
          g[j + it][v[j + 1]].emplace_back(j + 1 + it);
        }
        g[v.size() - 2 + it][v.back()].emplace_back(y);
      }
      it += v.size() - 1;
    }
  }
  vl res(it);
  g.resize(res.size());
  vi d(res.size(), 1e9);
  d[0] = 0;
  vvi q(1, vi(1, 0));
  while (!q.empty()) {
    vvi nq;
    for (const vi& v : q) {
      for (int t = 0; t < 10; ++t) {
        vi added;
        for (int from : v) for (int to : g[from][t]) {
          if (d[to] > d[from] + 1) {
            d[to] = d[from] + 1;
            res[to] = (10 * res[from] + t) % mod;
            added.push_back(to);
          }
        }
        if (!added.empty()) nq.push_back(added);
      }
    }
    q.swap(nq);
  }
  for (int i = 1; i < n; ++i) {
    cout << res[i] << '\n';
  }
  return 0;
}