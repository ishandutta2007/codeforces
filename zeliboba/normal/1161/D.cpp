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
const int mod = 998244353;

vi p, xr;

int getp(int v) {
  if (p[v] == v) return v;
  int pr = getp(p[v]);
  xr[v] ^= xr[p[v]];
  p[v] = pr;
  return pr;
}

bool FAIL;

void join(int a, int b, int c) {
  int pa = getp(a);
  int pb = getp(b);
  if (pa == pb) {
    if ((xr[a] ^ xr[b]) != c) FAIL = true;
  }
  p[pa] = pb;
  xr[pa] = xr[a] ^ xr[b] ^ c;
}

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  string s;
  cin >> s;
  int n = s.size();
  vl pw2(2 * n + 2, 1);
  for (int i = 1; i < pw2.size(); ++i) {
    pw2[i] = pw2[i - 1] * 2 % mod;
  }
  ll res = 0;
  for (int l = 1; l <= n; ++l) {
    FAIL = false;
    p.resize(2 * n);
    xr.assign(2 * n, 0);
    for (int i = 0; i < p.size(); ++i) {
      p[i] = i;
    }
    for (int i = 0; i < n - i - 1; ++i) {
      join(i, n - i - 1, 0);
    }
    for (int i = 0; i < l - i - 1; ++i) {
      join(n + i, n + l - i - 1, 0);
    }
    for (int i = 0; i < n; ++i) {
      if (s[i] != '?') {
        join(i, n + i, s[i] - '0');
      }
    }
    join(n, 2 * n - 1, 1);
    for (int i = l; i < n; ++i) {
      join(n + i, 2 * n - 1, 0);
    }
    if (!FAIL) {
      int cnt = 0;
      for (int i = 0; i < p.size(); ++i) if (p[i] == i) ++cnt;
      res += pw2[cnt - 1];
    }
  }
  cout << res % mod << endl;
  return 0;
}