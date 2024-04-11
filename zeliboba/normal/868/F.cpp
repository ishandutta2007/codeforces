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

ll stupid(const vi & a, int k) {
  int n = a.size();
  vi c(n);
  vvl d(k, vl(n + 1));
  for (int i = 0; i < n; ++i) {
    d[0][i + 1] = d[0][i] + c[a[i]];
    ++c[a[i]];
  }
  for (int t = 1; t < k; ++t) {
    d[t] = d[t-1];
    for (int i = 1; i <= n; ++i) {
      c.assign(n, 0);
      ll s = 0;
      for (int j = i-1; j >= 0; --j) {
        s += c[a[j]];
        d[t][i] = min(d[t][i], s + d[t-1][j]);
        ++c[a[j]];
      }
    }
  }
  return d[k-1][n];
}

int c[100005];
int used[100005];
ll sum = 0;

void sw(int i, const vi & a) {
  used[i] ^= 1;
  if (used[i]) {
    sum += c[a[i]];
    ++c[a[i]];
  } else {
    --c[a[i]];
    sum -= c[a[i]];
  }
}

void go(int from, int to, const vi & a) {
  if (from < to) for (int i = from; i < to; ++i) sw(i, a);
  else for (int i = from - 1; i >= to; --i) sw(i, a);
}

void check(int l, int r, int n) {
  for (int i = 0; i < n; ++i) {
    assert(used[i] == (i >= l && i < r));
  }
}

void rec(int l, int r, int p, int l1, int r1, const vi & a, const vl & d, vl & res) { //[l1; p)
  if (l >= r) return;
  int m = (l + r) / 2;
  int e = min(r1, m - 1);
  int b = l1;
//  cerr << l << ' ' << r << ' ' << l1 << ' ' << p << endl;
//  check(l1, p, a.size());
  while (b >= m) {
    --b;
    sw(b, a);
  }
  for (int i = min(m, p); i < max(m, p); ++i) sw(i, a);
  int best = b;
  res[m] = sum + d[b];
  if (b <= e) {
    for (int i = b; i < e; ++i) {
      sw(i, a);
      ll cand = sum + d[i+1];
      if (cand < res[m]) {
        res[m] = cand;
        best = i+1;
      }
    }
  } else {
    for (int i = b - 1; i >= e; --i) {
      sw(i, a);
      ll cand = sum + d[i];
      if (cand < res[m]) {
        res[m] = cand;
        best = i;
      }
    }
  }
  go(e, best, a);
//  cerr << l << ' ' << r << ' ' << m << ' ' << l1 << ' ' << r1 << ' ' << res[m] << ' ' << p << ' ' << sum << endl;
  rec(l, m, m, best, p < m ? l1 : r1, a, d, res);
  rec(m + 1, r, m, best, p < m ? r1 : l1, a, d, res);
  go(best, b, a);
  for (int i = min(m, p); i < max(m, p); ++i) sw(i, a);
  while (b < l1) {
    sw(b, a);
    ++b;
  }
//  check(l1, p, a.size());
}

ll solve(const vi & a, int k) {
  int n = a.size();
  assert(sum == 0); for (int i = 0; i < n; ++i) assert(c[i] == 0 && used[i] == 0);
  vl d(n + 1);
  for (int i = 0; i < n; ++i) {
    d[i + 1] = d[i] + c[a[i]];
    ++c[a[i]];
  }
  memset(c, 0, n * sizeof(c[0]));
  for (int t = 1; t < k; ++t) {
    vl nd(n + 1);
    rec(1, n + 1, 0, 0, n - 1, a, d, nd);
    d.swap(nd);
  }
  return d[n];
}

int main() {
  if (0) for (int n = 1; n <= 18; ++n) for (int k = 1; k <= n; ++k) for (int t = 0; t < 1000; ++t) {
    vi a(n);
    for (int i = 0; i < n; ++i) a[i] = rand() % n;
    ll s1 = solve(a, k), s2 = stupid(a, k);
    if (s1 != s2) {
      cerr << s1 << ' ' << s2 << endl;
      cerr << n << ' ' << k << endl;
      for (int i : a) cerr << i + 1 << ' '; cerr << endl;
      assert(0);
    }
  }
  //std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n, k;
  scanf("%d%d", &n, &k);
  vi a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    --a[i];
  }
  ll res = solve(a, k);
  printf("%lld\n", res);
//  cerr << stupid(a, k) << endl;
  return 0;
}