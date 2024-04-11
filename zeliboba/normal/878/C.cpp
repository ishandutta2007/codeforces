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
typedef vector<vl> vvl;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;

struct T {
  vi mi;
  vi ma;
  int sz;
};

bool cmp0(const vi & a, const vi & b) {
  for (int i = 0; i < a.size(); ++i) if (a[i] < b[i]) return 1;
  return 0;
}

bool cmp1(const vi & a, const vi & b) {
  for (int i = 0; i < a.size(); ++i) if (a[i] != b[i]) return a[i] < b[i];
  return 0;
}

struct classcomp {
  bool operator() (const T& a, const T& b) const {
    return cmp1(a.mi, b.mi);
  }
};

vi mmin(vi a, const vi & b) {
  for (int i = 0; i < a.size(); ++i) a[i] = min(a[i], b[i]);
  return a;
}

vi mmax(vi a, const vi & b) {
  for (int i = 0; i < a.size(); ++i) a[i] = max(a[i], b[i]);
  return a;
}

int main() {
  //std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n, k;
  scanf("%d%d", &n, &k);
  vvi a(n, vi(k));
  for (int i = 0; i < n; ++i) for (int j = 0; j < k; ++j) scanf("%d", &a[i][j]);
  const int M = 200;
  set<T, classcomp> q;
  for (int i = 0; i < n; ++i) {
    auto it = q.lower_bound({a[i], a[i], 1});
    while (it != q.begin()) {
      --it;
      if (!cmp0(a[i], it->ma)) {
        ++it; break;
      }
    }
    vi mi = a[i], ma = a[i];
    int sz = 1;
    while (it != q.end()) {
      if (cmp0(it->mi, ma)) {
        sz += it->sz;
        mi = mmin(mi, it->mi);
        ma = mmax(ma, it->ma);
        q.erase(it++);
      } else break;
    }
    q.insert({mi, ma, sz});
    it = q.end(); --it;
    printf("%d\n", it->sz);
  }
  return 0;
}