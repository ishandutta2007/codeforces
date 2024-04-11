#include <cstdio>
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
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;

ll vect(const pii& a, const pii& b) {
  return a.first*(ll)b.second - a.second*(ll)b.first;
}

bool in(pii a, pii b, pii c) {
  a.first -= b.first;
  c.first -= b.first;
  a.second -= b.second;
  c.second -= b.second;
  if (vect(a, c)) return 0;
  if (a.first*(ll)c.first > 0 || a.second*(ll)c.second > 0) return 0;
  return 1;
}

vii a, b;
vi bad[1000][7];
int dad[1000];

bool f(const vi & td, int mask) {
  if (td.empty()) return 1;
  if (mask == 0) return 0;
  int rem = __builtin_popcount(mask);
  int i = td.back();
  for (int j = 0; j < a.size(); ++j) if (mask & (1 << j)) {
    if (bad[i][j].size() >= a.size()) continue;
    vi nd = td;
    nd.pop_back();
    for (int x : bad[i][j]) if (!dad[x]) nd.push_back(x);
    sort(nd.begin(), nd.end());
    nd.resize(unique(nd.begin(), nd.end()) - nd.begin());
    if (nd.size() < rem) {
      dad[i]++;
      bool ok = f(nd, mask ^ (1 << j));
      --dad[i];
      if (ok) return true;
    }
  }
  return 0;
}

int main() {
  int n, k;
  scanf("%d%d", &k, &n);
  a.resize(k);
  b.resize(n);
  for (int i = 0; i < a.size(); ++i) scanf("%d%d", &a[i].first, &a[i].second);
  for (int i = 0; i < b.size(); ++i) scanf("%d%d", &b[i].first, &b[i].second);
  for (int i = 0; i < b.size(); ++i) for (int j = 0; j < a.size(); ++j) {
    for (int l = 0; l < b.size() && bad[i][j].size() <= k-1; ++l) if (l != i) {
      if (in(b[i], b[l], a[j])) {
        bad[i][j].push_back(l);
//        cerr << i << ' ' << j << ' ' << l << endl;
      }
    }
  }
  vi res(n);
  for (int i = 0; i < b.size(); ++i) if (f(vi(1, i), (1 << k) - 1)) {
    res[i] = 1;
//    if (res[i]) cerr << i << endl;
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) ans += res[i];
  printf("%d\n", ans);
  return 0;
}