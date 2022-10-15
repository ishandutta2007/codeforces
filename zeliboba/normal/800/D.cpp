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
using namespace std;
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

const int mod = 1000000007;
vi pw10(7, 1);

vi tovi(int x) {
  vi v(6);
  for (int i = 0; i < 6; ++i) {
    v[i] = x % 10;
    x /= 10;
  }
  return v;
}

int main() {
  for (int i = 1; i < pw10.size(); ++i) pw10[i] = pw10[i-1] * 10;
  int n;
  scanf("%d", &n);
  vi a(n), cnt(1000000);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    cnt[a[i]]++;
  }
  vl c(1000000), s(1000000), s2(1000000), val(1000000), res(1000000), pw2(1000005, 1);
  for (int i = 1; i < pw2.size(); ++i) pw2[i] = pw2[i-1] * 2 % mod;
  for (int i = 999999; i >= 0; --i) {
    c[i] = cnt[i];
    s[i] = i * (ll)cnt[i] % mod;
    s2[i] = i * (ll)i % mod * cnt[i] % mod;
    vi v = tovi(i);
    for (int mask = 1; mask < (1 << 6); ++mask) {
      int zn = -1;
      int cur = i;
      for (int b = 0; b < 6; ++b) if (mask & (1 << b)) {
        zn = -zn;
        if (v[b] == 9) {
          zn = 0;
          break;
        }
        cur += pw10[b];
      }
      c[i] += zn * c[cur];
      s[i] = (s[i] + zn * s[cur]);
      s2[i] = (s2[i] + zn * s2[cur]);
      res[i] = (res[i] - zn * val[cur]);
    }
    c[i] %= mod;
    s[i] %= mod;
    s2[i] %= mod;
    if (c[i] > 0) {
      val[i] = (val[i] + s2[i] * (ll)pw2[c[i]-1]) % mod;
    }
    if (c[i] > 1) {
      val[i] = (val[i] + (s[i] * (ll)s[i] - s2[i]) % mod * pw2[c[i]-2]) % mod;
    }
    res[i] = (res[i] + val[i]) % mod;
  }
  ll ans = 0;
  for (int i = 0; i < res.size(); ++i) {
    res[i] = (res[i] % mod + mod) % mod * i;
//    if (res[i]) cerr << i << ' ' << res[i] << endl;
    ans ^= res[i];
  }
  printf("%lld\n", ans);
  return 0;
}