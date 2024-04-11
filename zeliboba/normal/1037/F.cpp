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
const int mod = 1000000007;

vl len, slen;
ll f(ll l, ll r, int k) {
  ++l; ++r;
  if (l > r) swap(l, r);
  ll res = 0;
  int it = upper_bound(len.begin(), len.end(), l) - len.begin();
  if (it > 0) res = (res + slen[it]) % mod;
  int itr = upper_bound(len.begin(), len.end(), r) - len.begin();
  if (itr > it) res = (res + l * (itr - it)) % mod;
  int it2 = upper_bound(len.begin(), len.end(), r + l) - len.begin();
  if (it2 > itr) res = (res + (l + r) * (it2 - itr) - (slen[it2] - slen[itr])) % mod;
  return res % mod;
}

int main() {
  //std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n, k;
  scanf("%d%d", &n, &k);
  for (ll t = 1; ; ++t) {
    ll cur = k + (k - 1) * (t - 1);
    if (cur > n) break;
    len.push_back(cur);
  }
  slen.assign(len.size() + 1, 0);
  for (int i = 0; i < (int)len.size(); ++i) {
    slen[i + 1] = slen[i] + len[i];
  }
  vi a(n);
  vii ts(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    ts[i] = pii(a[i], i);
  }
  sort(ts.begin(), ts.end());
  vi pr(n), nx(n);
  for (int i = 0; i < n; ++i) {
    pr[i] = i - 1;
    nx[i] = i + 1;
  }
  ll res = 0;
  for (int t = 0; t < n; ++t) {
    int i = ts[t].second;
    int l = i - pr[i] - 1, r = nx[i] - i - 1;
//    cerr << a[i] << ' ' << l << ' ' << r << ' ' << f(l, r, k) << endl;
    res = (res + a[i] * f(l, r, k)) % mod;
    if (pr[i] >= 0) nx[pr[i]] = nx[i];
    if (nx[i] < n) pr[nx[i]] = pr[i];
  }
  cout << (res % mod + mod) % mod << endl;
  return 0;
}