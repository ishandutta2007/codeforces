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
#include <unordered_map>
#include <queue>
#include <array>
#include <bitset>
#include <chrono>
#include <random>
using namespace std;
typedef long double ld;
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
//const int mod = ;

const int L = 19;
const int N = 1 << L;

ll tr[2 * N];

ll gets(int r) {
  r += N;
  int l = N;
  ll sum = 0;
  while (r >= l) {
    if (!(r & 1)) {
      sum += tr[r];
      --r;
    }
    l /= 2;
    r /= 2;
  }
  return sum;
}

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int T;
  cin >> T;
  vii q(T);
  vl ts(T);
  for (int i = 0; i < T; ++i) {
    string s;
    cin >> s >> q[i].first;
    ts[i] = q[i].first;
    if (s[0] == '-') q[i].second = -1;
    else q[i].second = 1;
  }
  sort(ts.begin(), ts.end());
  ts.erase(unique(ts.begin(), ts.end()), ts.end());
  int n = 0;
  for (int i = 0; i < T; ++i) {
    n += q[i].second;
    int ind = lower_bound(ts.begin(), ts.end(), q[i].first) - ts.begin();
    ind += N;
    while (ind > 0) {
      tr[ind] += q[i].first * q[i].second;
      ind /= 2;
    }
    int cnt = 0, pos = 0;
    ll prefsum = 0;
    if (n == 0) {
      cout << 0 << '\n';
      continue;
    }
    while (pos < ts.size()) {
      int l = pos - 1, r = ts.size();
      while (r - l > 1) {
        int x = (l + r) / 2;
        if (gets(x) <= prefsum) {
          l = x;
        } else {
          r = x;
        }
      }
      if (r >= ts.size()) break;
      if (ts[r] > 2 * gets(r - 1) && prefsum != 0 && tr[r + N] != 0) ++cnt;
      prefsum = gets(r);
      ll minval = 2 * prefsum + 1;
      pos = lower_bound(ts.begin(), ts.end(), minval) - ts.begin();
/*      for (int l = 0; l < L; ++l) {
        int ind = (pos + N) >> l;

        if (tr[ind]) {
          prefsum += tr[ind];
          if (ts[ind] * 3 > 2 * prefsum) ++cnt;
          break;
        }
      }*/
    }
    cout << n - 1 - cnt << '\n';
  }
  return 0;
}