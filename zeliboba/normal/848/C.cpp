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

set<int> w[100005];
const int N = 1 << 17;
vi trpos[2 * N];
vl trfen[2 * N];
vi a;

void add(int i, int val, vl & f) {
  for (; i < f.size(); i |= i + 1)
    f[i] += val;
}

ll sum(int i, const vl & f) {
  ll s = 0;
  for (; i >= 0; i = (i & (i + 1)) - 1)
    s += f[i];
  return s;
}

void addpos(int i, int j) {
  i += N;
  while (i) {
    trpos[i].push_back(j);
    i /= 2;
  }
}

void addtr(int l, int r, int val) {
  l += N;
  while (l) {
    int it = lower_bound(trpos[l].begin(), trpos[l].end(), r) - trpos[l].begin();
    add(it, val, trfen[l]);
    l /= 2;
  }
}

ll gettr(int l, int R) {
  int it = upper_bound(trpos[l].begin(), trpos[l].end(), R) - trpos[l].begin();
  return sum(it - 1, trfen[l]);
}

void add(int i, int val, bool work) {
  w[val].insert(i);
  auto it = w[val].lower_bound(i);
  int l = -1;
  if (it != w[val].begin()) {
    --it;
    l = *it;
    if (work) addtr(l, i, i - l);
    else addpos(*it, i);
    ++it;
  }
  ++it;
  if (it != w[val].end()) {
    if (work) addtr(i, *it, *it - i);
    else addpos(i, *it);
    if (l >= 0) {
      if (work) addtr(l, *it, l - *it);
    }
  }
}

void rem(int i, int val, bool work) {
  auto it = w[val].lower_bound(i);
  int l = -1;
  if (it != w[val].begin()) {
    --it;
    l = *it;
    if (work) addtr(l, i, -i + l);
    ++it;
  }
  ++it;
  if (it != w[val].end()) {
    if (work) addtr(i, *it, -*it + i);
    if (l >= 0) {
      if (work) addtr(l, *it, *it - l);
      else addpos(l, *it);
    }
  }
  w[val].erase(i);
}
  
void initw(bool work) {
  for (int i = 0; i <= a.size(); ++i) w[i].clear();
  for (int i = 0; i < a.size(); ++i) {
    w[a[i]].insert(i);
    add(i, a[i], work);
  }
}

void norm(vi & v) {
  sort(v.begin(), v.end());
  v.resize(unique(v.begin(), v.end()) - v.begin());
}

ll f(int l, int r, int R) {
  l += N;
  r += N;
  ll s = 0;
  while (l <= r) {
    if (l & 1) {
      s += gettr(l, R);
      ++l;
    }
    if (!(r & 1)) {
      s += gettr(r, R);
      --r;
    }
    if (l > r) break;
    l /= 2; r /= 2;
  }
  return s;
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n, m;
  cin >> n >> m;
  a.resize(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i]; 
  }
  vi a0 = a;
  initw(0);
  vector<array<int, 3>> q(m);
  for (int t = 0; t < m; ++t) for (int i = 0; i < 3; ++i) cin >> q[t][i];
  for (int t = 0; t < m; ++t) {
    if (q[t][0] == 1) {
      int p = q[t][1], x = q[t][2];
      --p;
      rem(p, a[p], 0);
      add(p, x, 0);
      a[p] = x;
    }
  }
  for (int i = 0; i < 2 * N; ++i) {
    norm(trpos[i]);
    trfen[i].assign(trpos[i].size(), 0);
  }
  a = a0;
  initw(1);
  for (int t = 0; t < m; ++t) {
    if (q[t][0] == 1) {
      int p = q[t][1], x = q[t][2];
      --p;
      rem(p, a[p], 1);
      add(p, x, 1);
      a[p] = x;
    } else {
      int l = q[t][1], r = q[t][2];
      --l; --r;
      cout << f(l, r, r) << endl;
    }
  }
  return 0;
}