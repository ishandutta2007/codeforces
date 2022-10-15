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
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef long double ld;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<ll, int> pli;
typedef pair<double, double> pdd;
typedef vector<pli> vli;
typedef vector<string> vs;

const int P = 131;
const int P1 = 3124;
const int mod = 848431753+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1;
vl pw(1000001, 1);
vl pw1(pw.size(), 1);

vli mhash(const string & s) {
  vli h(s.size() + 1);
  for (int i = 0; i < (int)s.size(); ++i) {
    h[i+1].first = h[i].first*P + s[i];
    h[i+1].second = (h[i].second*(ll)P1 + s[i]) % mod;
  }
  return h;
}

int up(int x) {
  if (x < 0) return x+mod;
  return x;
}

pli geth(const vli& v, int b, int len) {
  return pli(v[b+len].first - pw[len]*v[b].first, up((v[b+len].second - pw1[len]*v[b].second)%mod));
}

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  for (int i = 1; i < (int)pw.size(); ++i) {
    pw[i] = pw[i-1] * P;
    pw1[i] = pw1[i-1] * (ll)P1 % mod;
  }
  string s, t;
  cin >> s >> t;
  if (s[0] == '1') {
    for (int i = 0; i < (int)s.size(); ++i) {
      s[i] = s[i] == '0' ? '1' : '0';
    }
  }
  vi c(2);
  for (int i = 0; i < (int)s.size(); ++i) {
    c[s[i] - '0']++;
  }
  vli thash = mhash(t);
  int res = 0;
  for (int l0 = 1; l0 * c[0] < (int)t.size(); ++l0) {
    int totl1 = t.size() - l0 * c[0];
    if (totl1 % c[1]) continue;
    int l1 = totl1 / c[1];
//    cerr << l0 << ' ' << l1 << endl;
    int it = 0;
    array<pli, 2> h;
    array<int, 2> l = {l0, l1};
    array<int, 2> was = {0, 0};
    bool fail = 0;
    for (int i = 0; i < (int)s.size(); ++i) {
      int t = s[i] - '0';
      pli cur = geth(thash, it, l[t]);
      if (!was[t]) {
        h[t] = cur;
        was[t] = 1;
      } else if (cur != h[t]) {
        fail = 1; break;
      }
      it += l[t];
    }
    if (!fail && (l[0] != l[1] || h[0] != h[1])) ++res;
  }
  cout << res << endl;
  return 0;
}