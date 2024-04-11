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

vi fen(5e5);

void add(int i, int v) {
  for (; i < fen.size(); i |= i + 1)
    fen[i] = max(fen[i], v);
}

int getma(int i) {
  int ma = 0;
  for (; i >= 0; i = (i & (i + 1)) - 1)
    ma = max(ma, fen[i]);
  return ma;
}

vi p;

int getp(int v) {
  if (p[v] == v) return v;
  return p[v] = getp(p[v]);
}

void join(int a, int b) {
  p[getp(a)] = getp(b);
}

const int N = 2e5;
const int DEBUG = 0;

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n = N;
  if (!DEBUG) cin >> n;
  vi a(n), b(n), v(n), type(n), col(n);
  vvi rem(2);
  for (int i = n + 1; i <= 2 * n; ++i) {
    rem[rand() % 2].push_back(i);
  }
  for (int i = 0; i < n; ++i) {
    if (!DEBUG) cin >> a[i] >> b[i];
    else {
      a[i] = 1 + i;
      int t = rand() % 2;
      if (rem[t].empty()) t = 1-t;
      b[i] = rem[t].back();
      rem[t].pop_back();
    }
    if ((a[i] <= n && b[i] <= n) || (a[i] > n && b[i] > n)) {
      cout << -1 << endl;
      return 0;
    }
    if (a[i] <= n) {
      v[a[i] - 1] = b[i] - 1;
      type[a[i] - 1] = 1;
    } else v[b[i] - 1] = a[i] - 1;
  }
  for (int i = 0; i < v.size(); ++i) {
    int len = getma(v[i] - 1);
    if (len >= 2) {
//      if (!(a == vi({1, 3, 4}) && b == vi({2, 6, 5}))) assert(0);
      cout << -1 << endl;
      return 0;
    }
    add(v[i], 1 + len);
  }
  p.resize(n);
  for (int i = 0; i < p.size(); ++i) p[i] = i;
  vi q;
  for (int i = 0; i < n; ++i) {
    if (q.empty() || v[q.back()] > v[i]) q.push_back(i);
    else {
      int last = q.back();
      while (!q.empty() && v[q.back()] < v[i]) {
        join(i, q.back());
        col[i] = 1;
        q.pop_back();
      }
      q.push_back(last);
    }
  }
  vvi comp(n);
  for (int i = 0; i < n; ++i) comp[getp(i)].push_back(i);
  int res = 0;
  for (int i = 0; i < n; ++i) if (!comp[i].empty()) {
    assert(p[i] == i);
    vvi c(2, vi(2));
    for (int x : comp[i]) {
      ++c[type[x]][col[x]];
    }
    res += min(c[0][0] + c[1][1], c[0][1] + c[1][0]);
  }
//  if (!(a == vi({3,6,1,5,2}) && b == vi({10, 4, 9, 8, 7}))) assert(0);
  cout << res << endl;
  return 0;
}