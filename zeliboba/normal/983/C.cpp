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

const int N = 13;
int d[2][1 << N][9];
int hasmask[1 << N];
//vi has[1 << N];
vi ordmask[5];
int add[1 << N][9];
int rem[1 << N][9];

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  const int MAX = 1e9;
  for (int mask = 0; mask < (1 << N); ++mask) for (int i = 0; i < 9; ++i) d[0][mask][i] = d[1][mask][i] = MAX;
  for (int mask = 0; mask < (1 << N); ++mask) {
    int sz = __builtin_popcount(mask);
    int last = 0;
    for (int i = N - 1; i >= 0; --i) if (mask & (1 << i)) {
      last = i; break;
    }
    if (sz > 4 || last - sz > 8) continue;
    ordmask[sz].push_back(mask);
    int cnt = 0;
    for (int i = 0; i < N; ++i) {
      if (sz < 4 && cnt < 9) {
        int pref = mask & ((1 << i) - 1);
        int suf = mask ^ pref;
        add[mask][cnt] = pref | (suf * 2) | (1 << i);
//        cerr << mask << ' ' << i << ' ' << cnt << ' ' << pref << ' ' << suf << ' ' << add[mask][cnt] << endl;
        if (add[mask][cnt] >= (1 << N)) continue;
        assert(__builtin_popcount(add[mask][cnt]) <= 4);
        rem[add[mask][cnt]][cnt] = mask;
      }
      if (mask & (1 << i)) {
        hasmask[mask] |= (1 << cnt);
//        has[mask].push_back(cnt);
      } else {
        ++cnt;
      }
    }
  }
//  return 0;
  int n;
  cin >> n;
  vi a(n), b(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> b[i];
    --a[i]; --b[i];
  }
  for (int i = 0; i < 9; ++i) d[0][0][i] = i;
  for (int t = 0; t < n; ++t) {
    int tt = (t + 1) % 2;
    for (int mask = 0; mask < (1 << N); ++mask) for (int i = 0; i < 9; ++i) d[tt][mask][i] = MAX;
    for (int mask = 0; mask < (1 << N); ++mask) if (__builtin_popcount(mask) < 4) {
      int nmask = add[mask][b[t]];
      d[tt][nmask][a[t]] = d[1-tt][mask][a[t]] + 1;
    }
    for (int t = 4; t >= 0; --t) for (int mask : ordmask[t]) {
      for (int i = 0; i + 1 < 9; ++i) {
        d[tt][mask][i + 1] = min(d[tt][mask][i + 1], d[tt][mask][i] + 1);
      }
      for (int i = 8; i > 0; --i) {
        d[tt][mask][i - 1] = min(d[tt][mask][i - 1], d[tt][mask][i] + 1);
      }
      for (int i = 0; i < 9; ++i) if (hasmask[mask] & (1 << i)) {
        int nmask = rem[mask][i];
        d[tt][nmask][i] = min(d[tt][nmask][i], d[tt][mask][i] + 1);
      }
    }
    /*for (int mask = 0; mask < (1 << N); ++mask) for (int i = 0; i < 5; ++i) if (d[tt][mask][i] < MAX) {
      cerr << mask << ' ' << i << ' ' << d[tt][mask][i] << endl;
    }*/
  }
  int res = MAX;
  for (int i = 0; i < 9; ++i) res = min(res, d[n%2][0][i]);
  cout << res << endl;
  return 0;
}