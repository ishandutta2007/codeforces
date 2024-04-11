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
#include <queue>
#include <array>
#include <bitset>
using namespace std;
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
//typedef long long int;
const int mod = 1000000007;

void filter(vl & v) {
  while (v.size() > 1 && v.back() == 0) v.pop_back();
}

int dw(int x) {
  return x < mod ? x : x-mod;
}

int up(int x) {
  return x >= 0 ? x : x + mod;
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n;
  string s;
  cin >> n >> s;
  if (s.size() != n) s = string(n, '9');
  vi mu(n + 1, 1);
  for (int i = 2; i < mu.size(); ++i) {
    mu[i] = -1;
    for (int p = 2; p * p <= i; ++p) if (i % p == 0) {
      if (i / p % p == 0) mu[i] = 0;
      else mu[i] = -mu[i/p];
      break;
    }
  }
  vl p(n);
  for (int i = 0; i < n; ++i) p[i] = s[i] - '0';
  for (int k = n; k <= n; ++k) if (n % k == 0) {
    vl q = p;
    for (int d = 1; d <= k; ++d) if (k % d == 0 && mu[k/d] == -1) {
//      cerr << d << endl;
//      for (ll x : q) cerr << x << ' '; cerr << endl;
      for (int i = 0; i < d; ++i) q.push_back(0);
      for (int i = q.size() - 1; i >= d; --i) q[i] = (q[i] - q[i-d]);
    }
    filter(q);
    bool ok = 1;
    for (int d = 1; d <= k; ++d) if (k % d == 0 && mu[k/d] == 1) {
//      cerr << d << endl;
//      for (ll x : q) cerr << x << ' '; cerr << endl;
      if (q.size() < d) {
        if (q != vl(1, 0)) {
          ok = 0; 
        }
        break;
      }
      vl nq(q.size() - d);
      for (int i = q.size() - 1; i >= d; --i) {
        nq[i - d] = q[i];
        q[i - d] = (q[i-d] + q[i]);
      }
      for (int i = 0; i < d; ++i) if (q[i]) {
        ok = 0; break;
      }
      if (!ok) break;
      q.swap(nq);
      filter(q);
    }
    if (ok) {
//      cerr << k << endl;
      cout << "YES\n";
      return 0;
    }
  }
  cout << "NO\n";
  return 0;
}