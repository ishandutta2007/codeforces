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

vl fen(200005);
vl fac(fen.size(), 1), invfac(fen.size(), 1), inv(fen.size(), 1);

void add(int i, ll val) {
  for (; i < fen.size(); i |= i + 1)
    fen[i] = (fen[i] + val) % mod;
}

ll getsum(int i) {
  ll s = 0;
  for (; i >= 0; i = (i & (i + 1)) - 1)
    s += fen[i];
  return s % mod;
}

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  for (int i = 2; i < fac.size(); ++i) {
    fac[i] = fac[i - 1] * i % mod;
    inv[i] = (mod - (mod/i) * (ll)inv[mod%i] % mod) % mod;
    assert(inv[i] * i % mod == 1);
    invfac[i] = invfac[i - 1] * inv[i] % mod;
  }
  int T = 1;
//  cin >> T;
  for (int test = 1; test <= T; ++test) {
    int n, m;
    cin >> n >> m;
    vi cnt(fen.size());
    ll prod = 1;
    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      if (cnt[x]) add(x, mod - cnt[x]);
      ++cnt[x];
      add(x, cnt[x]);
      prod = prod * inv[cnt[x]] % mod;
    }
    ll res = 0;
    for (int i = 0; i < m; ++i) {
      int x;
      cin >> x;
      if (i == n) {
        res++;
      } else {
        res = (res + fac[n - i - 1] * prod % mod * getsum(x - 1)) % mod;
      }
//      cerr << res << ' ' << fac[n - i - 1] << ' ' << prod << ' ' << getsum(x - 1) << endl;
      if (cnt[x] == 0) break;
      prod = prod * cnt[x] % mod;
      add(x, mod - cnt[x]);
      --cnt[x];
      if (cnt[x] != 0) add(x, cnt[x]);
    }
    cout << (res + mod) % mod << endl;
  }
  return 0;
}