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
//const int mod = ;

void no() {
  cout << "NO\n";
  exit(0);
}

const int N = 1 << 18;
int mi[2 * N];

int getmi(int l, int r) {
  l += N;
  r += N;
  int res = 1e9;
  while (l <= r) {
    if (l & 1) {
      res = min(res, mi[l]);
      ++l;
    }
    if (!(r & 1)) {
      res = min(res, mi[r]);
      --r;
    }
    l /= 2;
    r /= 2;
  }
  return res;
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n, q;
  cin >> n >> q;
  vi a(n);
  bool was = false;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (a[i] == q) was = true;
  }
  for (int i = 0; i < n; ++i) {
    if (a[i] == 0) {
      if (!was) {
        a[i] = q;
        was = true;
      } else if (i) {
        a[i] = a[i-1];
      }
    }
  }
  if (!was) no();
  for (int i = n-2; i >= 0; --i) {
    if (a[i] == 0) {
      a[i] = a[i + 1];
    }
  }
  for (int i = 0; i < 2 * N; ++i) mi[i] = 1e9;
  for (int i = 0; i < n; ++i) mi[N+i] = a[i];
  for (int i = N - 1; i > 0; --i) mi[i] = min(mi[2*i], mi[2*i+1]);
  vi pr(q + 1, -1);
  for (int i = 0; i < n; ++i) {
    if (pr[a[i]] != -1) {
      if (getmi(pr[a[i]], i) < a[i]) no();
    }
    pr[a[i]] = i;
  }
  cout << "YES\n";
  for (int x : a) cout << x << ' ';
  cout << endl;
  return 0;
}