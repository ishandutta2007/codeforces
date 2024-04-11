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

void out(const vi & v) {
  for (int i = 0; i < v.size(); ++i) {
    printf("%c", 'a' + v[i]);
  }
  printf("\n");
}

int main() {
  int n;
  cin >> n;
  vi a(n);
  int d = 0;
  int cntodd = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    d = __gcd(a[i], d);
    cntodd += a[i] % 2;
  }
  vi res;
  if (cntodd > 1) {
    cout << 0 << endl;
    for (int i = 0; i < a.size(); ++i) for (int j = 0; j < a[i]; ++j) res.push_back(i);
    out(res);
    return 0;
  }
/*  int ans = (cntodd == 1) ? 1 : 2;
  for (int i = 0; i < a.size(); ++i) for (int j = 0; j < a[i] / 2; ++j) res.push_back(i);
  for (int i = 0; i < a.size(); ++i) if (a[i] % 2) res.push_back(i);
  for (int i = a.size() - 1; i >= 0; --i) for (int j = 0; j < a[i] / 2; ++j) res.push_back(i);
  if (d > 1) {*/
  int ans = d;
  if (cntodd) {
    for (int t = 0; t < d; ++t) {
      for (int i = 0; i < a.size(); ++i) for (int j = 0; j < a[i] / 2 / d; ++j) res.push_back(i);
      for (int i = 0; i < a.size(); ++i) if (a[i] % 2) res.push_back(i);
      for (int i = a.size() - 1; i >= 0; --i) for (int j = 0; j < a[i] / 2 / d; ++j) res.push_back(i);
    }
  } else {
    for (int t = 0; t < d / 2; ++t) {
      for (int i = 0; i < a.size(); ++i) for (int j = 0; j < a[i] / d; ++j) res.push_back(i);
      for (int i = a.size() - 1; i >= 0; --i) for (int j = 0; j < a[i] / d; ++j) res.push_back(i);
    }
  }
//  }
  cout << ans << endl;
  out(res);
  return 0;
}