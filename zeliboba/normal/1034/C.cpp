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
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;
const int mod = 1000000007;

vl a;
vvi g;
vl rems;
bool FAIL = 0;

void dfs(int v, int p, ll lim, vi& x) {
  rems[v] = a[v];
  for (int nv : g[v]) if (nv != p && !FAIL) {
    dfs(nv, v, lim, x);
    rems[v] += rems[nv];
  }
  if (rems[v] == lim) {
    rems[v] = 0;
    x.push_back(v);
  }
  if (rems[v] > lim) {
    FAIL = 1;
  }
}

bool contains(const vi & a, const vi & b) {
  return true;
  if (a.size() * 10 < b.size()) {
    for (int x : a) if (!binary_search(b.begin(), b.end(), x)) return false;
    return true;
  }
  int it = 0;
  for (int x : a) {
    while (it < b.size() && b[it] < x) ++it;
    if (it >= b.size() || b[it] != x) return false;
  }
  return true;
}

int main() {
  //std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n = 720720;
  scanf("%d", &n);
  a.resize(n);
  rems.resize(n);
  g.resize(n);
  ll s = 0;
  for (int i = 0; i < n; ++i) {
    a[i] = 1 << 29;
    scanf("%lld", &a[i]);
    s += a[i];
  }
  for (int i = 0; i < n - 1; ++i) {
    int p = i + 1;
    scanf("%d", &p);
    --p;
    g[p].push_back(i+1);
    g[i+1].push_back(p);
  }
  vl sums(n);
  unordered_map<ll, int> w;
  vl c(n + 1);
  for (int i = n - 1; i >= 0; --i) {
    sums[i] = a[i];
    for (int j : g[i]) if (j > i) sums[i] += sums[j];
    w[sums[i]] += 1;
    ll d = __gcd(sums[i], s);
    ll x = s / d;
    if (x <= n) ++c[x];
  }
  vl c1(n + 1);
  for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) c1[j] += c[i];
  vi div;
  for (int i = 1; i <= n; ++i) if (s % i == 0) {
    div.push_back(i);
  }
  vvi p;
  vi ndiv;
  for (int i = 0; i < div.size(); ++i) {
    vi x;
    FAIL = 0;
//    dfs(0, -1, s / div[i], x);
//    ll lim = s / div[i];
//    int c = 0;
//    for (int j = 1; j <= div[i]; ++j) c += w[j * lim];
    if (c1[div[i]] == div[i]) {
      ndiv.push_back(div[i]);
      sort(x.begin(), x.end());
      p.push_back(x);
    }
  }
  div.swap(ndiv);
  vl d(div.size(), 1);
  for (int i = d.size() - 1; i >= 0; --i) {
    for (int j = i + 1; j < d.size(); ++j) if (div[j] % div[i] == 0) {
      if (contains(p[i], p[j])) {
        d[i] = (d[i] + d[j]) % mod;
      }
    }
//    cerr << div[i] << ' ' << d[i] << endl;
  }
  printf("%lld\n", d[0]);
  return 0;
}