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

int main() {
  int n, k;
  scanf("%d%d",&n,&k);
  vd p(n);
  for (int i = 0; i < n; ++i) {
    scanf("%lf", &p[i]);
  }
  vd q(1 << n);
  q[0] = 1;
  vd res(n);
  for (int mask = 0; mask < q.size(); ++mask) {
    int bits = __builtin_popcount(mask);
    double s = 1;
    for (int i = 0; i < n; ++i) if (mask & (1 << i)) {
      s -= p[i];
    }
    bool stop = bits == k || abs(s) < 1e-8;
    for (int i = 0; i < n; ++i) if (mask & (1 << i)) {
      if (stop) res[i] += q[mask];
    }
    if (stop) continue;
    for (int i = 0; i < n; ++i) if (!(mask & (1 << i))) {
      q[mask | (1 << i)] += q[mask] * p[i] / s;
    }
  }
  for (int i = 0; i < n; ++i) printf("%.8lf ", res[i]);
/*  vi p(n);
  for (int i = 0; i < n; ++i) {
    scanf("%lf", &p0[i]);
    p[i] = round(100 * p0[i]);
  }
  vi ind(100);
  int s = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < p[i]; ++j) {
      ind[s] = i;
      ++s;
    }
  }
  vi last(n);
  const int IT = 1e8;
  vi cnt(n);
  vi cash(k, -1);
  for (int t = 1; t <= IT; ++t) {
    int i = ind[rand() % 100];
    if (!last[i]) {
      int td = 0;
      for (int j = 0; j < k; ++j) {
        if (cash[j] == -1) {
          td = j; break;
        }
        if (last[cash[j]] < last[cash[td]]) {
          td = j;
        }
      }
      if (cash[td] != -1) {
        cnt[cash[td]] += t - last[cash[td]];
        last[cash[td]] = 0;
      }
      cash[td] = i;
    } else {
      cnt[i] += t - last[i];
    }
    last[i] = t;
  }
  for (int j = 0; j < k; ++j) cnt[cash[j]] += IT + 1 - last[cash[j]];
  for (int i = 0; i < n; ++i) {
    printf("%.8lf ", cnt[i] / (double)IT);
  } */
  return 0;
}