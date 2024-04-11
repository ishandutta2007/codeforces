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

void out(vi v) {
  for (int x : v) cerr << x << ' '; cerr << endl;
}

void out(vl v) {
  for (int x : v) cerr << x << ' '; cerr << endl;
}

void mfill(vl & s, const vi & a, int n) {
  int k1 = (n - 1) / 2, k2 = n - 1 - k1;
  vi s1(1 << k1), s2(1 << k2);
  for (int i = 0; i < s1.size(); ++i) {
    for (int b = 0; b < k1; ++b) if (i & (1 << b)) {
      s1[i] += a[b];
    }
  }
  for (int i = 0; i < s2.size(); ++i) {
    for (int b = 0; b < k2; ++b) if (i & (1 << b)) {
      s2[i] += a[b+k1];
    }
  }
  int B1 = (1 << k1) - 1;
  for (int mask = 0; mask < s.size(); ++mask) {
    s[mask] = s1[mask & B1] + s2[mask >> k1];
  }
//  out(a);  out(s1);  out(s2);
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n;
  cin >> n;
  vii a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].first;
    a[i].second = i;
  }
  sort(a.begin(), a.end());
  vi b(n);
  for (int i = 0; i < a.size(); ++i) {
    b[a[(i+1) % n].second] = a[i].first;
  }
  for (int i : b) cout << i << ' '; cout << endl;
/*  vl sa(1 << (n - 1));
  vl sb(sa.size());
  mfill(sa, a, n);
  vi b = a;
  for (int i = 0; i < 100; ++i) {
    random_shuffle(b.begin(), b.end());
    mfill(sb, b, n);
//    out(b);  out(sa);  out(sb);
    bool ok = 1;
    for (int i = 1; i < sa.size(); ++i) if (sa[i] == sb[i]) {
      ok = 0;
      break;
    }
    if (ok) {
      for (int i : b) cout << i << ' '; cout << endl;
      return 0;
    }
  }
  cout << -1 << endl;*/
  return 0;
}