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

vi p, r;

int getp(int v) {
  if (p[v] == v) return v;
  return p[v] = getp(p[v]);
}

void join(int a, int b) {
  a = getp(a);
  b = getp(b);
  if (a == b) return;
  if (r[a] > r[b]) swap(a, b);
  p[a] = b;
  r[b] += r[a];
}

ll c2(ll x) {
  return x*(x-1)/2;
}

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vi c(k);
  for (int i = 0; i < k; ++i) {
    cin >> c[i];
    --c[i];
  }
  r.assign(n, 1);
  p.resize(n);
  for (int i = 0; i < n; ++i) p[i] = i;
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    join(a, b);
  }
  int ma = 0;
  ll res = -m;
  vi was(n);
  for (int i = 0; i < k; ++i) {
    c[i] = getp(c[i]);
    ma = max(ma, r[c[i]]);
    was[c[i]] = 1;
    res += c2(r[c[i]]);
  }
  res -= c2(ma);
  for (int i = 0; i < n; ++i) if (!was[i] && getp(i) == i) {
    ma += r[i];
  }
  res += c2(ma);
  cout << res << endl;
  return 0;
}