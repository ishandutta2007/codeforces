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
const int N = (1 << 20);
int v[2*N], c[2*N];

int getmi(int l, int r) {
  l += N;
  r += N;
  int res = 2e9;
  while (l <= r) {
    if (l & 1) {
      res = min(res, c[l]);
      ++l;
    }
    if (!(r & 1)) {
      res = min(res, c[r]);
      --r;
    }
    if (l > r) break;
    l /= 2; r /= 2;
  }
  return res;
}

int getma(int l, int r) {
  l += N;
  r += N;
  int res = 0;
  while (l <= r) {
    if (l & 1) {
      res = max(res, v[l]);
      ++l;
    }
    if (!(r & 1)) {
      res = max(res, v[r]);
      --r;
    }
    if (l > r) break;
    l /= 2; r /= 2;
  }
  return res;
}

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  vector<long double> lnfac(n + 1);
  for (int i = 2; i < lnfac.size(); ++i) {
    lnfac[i] = lnfac[i-1] + log(i);
  }
  for (int i = N; i < 2*N; ++i) c[i] = 2e9;
  for (int i = 0; i < n; ++i) scanf("%d", &v[i+N]);
  for (int i = 0; i < n; ++i) scanf("%d", &c[i+N]);
  for (int i = N-1; i > 0; --i) {
    v[i] = max(v[2*i], v[2*i+1]);
    c[i] = min(c[2*i], c[2*i+1]);
  }
  vi res(n);
  for (int i = 0; i < n; ++i) {
    int l = i, r = n;
    int d = 1;
    while (4*d <= r-l) d *= 2;
    int curmi = 1e9, curma = 0;
    while (r - l > 1) {
      int x = (l + r) / 2;
      if (d && 2*d <= r-l) {
        x -= x%d;
        d /= 2;
      }
      int ma = 100*max(curma, getma(l, x));
      int mi = min(curmi, getmi(l, x));
      if (ma > mi) {
        r = x;
      } else {
        l = x;
        curma = ma/100;
        curmi = mi;
      }
    }
    res[i] = min(100*getma(i, l), getmi(i, l));
    if (r < n) res[i] = max(res[i], min(100*getma(i, r), getmi(i, r)));
  }
  sort(res.begin(), res.end());
  long double ans = 0;
  for (int i = 0; i+k <= n; ++i) {
//    cerr << res[i] << endl;
    ans += res[i] * (ll)k * exp(lnfac[n-i-1] - lnfac[n-i-k] + lnfac[n-k] - lnfac[n]);
  }
  printf("%.10lf\n", (double)ans);
  return 0;
}