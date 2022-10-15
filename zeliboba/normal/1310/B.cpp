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
//const int mod = ;

void f(vi& l, int& res) {
  vi nl(l.size() / 2);
  for (int i = 0; i < l.size(); i += 2) {
    if (l[i] || l[i + 1]) {
      ++res;
      nl[i / 2] = 1;
    }
  }
  l.swap(nl);
}

void upd(int& x, int y) {
  x = max(x, y);
}

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n, k;
  cin >> n >> k;
  vi a(k);
  vi v(1 << n);
  for (int i = 0; i < k; ++i) {
    cin >> a[i]; --a[i];
    v[a[i]] = 1;
  }
  int res = 0;
  const int M = -1e9;
  vector<array<array<int, 2>, 2>> d(v.size(), {M,M,M,M});
  int N = v.size() / 2;
  for (int i = 0; i < v.size(); i += 2) {
    int a = v[i], b = v[i + 1];
    d[N + i / 2][a][b] = (a + b) > 0;
    d[N + i / 2][b][a] = (a + b) > 0;
  }
  while (N > 1) {
    for (int i = N; i < 2 * N; i += 2) {
      for (int w1 = 0; w1 < 2; ++w1) for (int l1 = 0; l1 < 2; ++l1) {
        for (int w2 = 0; w2 < 2; ++w2) for (int l2 = 0; l2 < 2; ++l2) {
          int l = l1 || l2;
          int sum = d[i][w1][l1] + d[i + 1][w2][l2] + l + (w1 + w2 > 0);
          int w = w1, wl = w2;
          for (int tw = 0; tw < 2; ++tw) {
            upd(d[i / 2][w][max(l, wl)], sum + (wl + l > 0));
            swap(w, wl);
          }
        }
      }
    }
    N /= 2;
  }
/*  for (int i = 1; i < v.size(); ++i) for (int w = 0; w < 2; ++w) for (int l = 0; l < 2; ++l) if (d[i][w][l] > M) {
    cerr << i << ' ' << w << ' ' << l << ' ' << d[i][w][l] << endl;
  }*/
  for (int w = 0; w < 2; ++w) for (int l = 0; l < 2; ++l) {
    res = max(res, d[1][w][l] + (w + l > 0));
  }
/*  vi w(1 << (n - 1)), l(1 << (n - 1));
  for (int i = 0; i < v.size(); i += 2) {
    int c = v[i] + v[i + 1];
    if (c) ++res;
    if (c == 2) {
      w[i / 2] = l[i / 2] = 1;
    } else if (c == 1) {
      if (l[(i / 2) ^ 1]) {
        w[i / 2] = 1;
      } else {
        l[i / 2] = 1;
      }
    }
  }
  while (w.size() > 1) {
    assert(w.size() == l.size());
    f(l);
    vi l1(l.size());
    for (int i = 0; i < w.size(); i += 2) {
      int c = w[i] + w[i + 1];
      if (c) ++res;
      if (c == 2) {
        w[i / 2] = l1[i / 2] = 1;
      } else if (c == 1) {
        if (l[i / 2]) {
          w[i / 2] = 1;
        } else {
          l1[i / 2] = 1;
        }
      }
    }
  }
  res += w[0] || l[0];*/
  cout << res << endl;
  return 0;
}