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
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;
//const int mod = ;

const int N = 100000;
const int M = 400;
const int MAX = (M + 1) * (N + 1);
unsigned short c[2 * MAX + 1];
unordered_map<int, int> w;
unordered_map<int, int> dyn[N];
//unordered_map<int, short> dyn[N];

const int DEBUG = 0;

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int T = 1;
  for (int test = 1; test <= T; ++test) {
    int n = N;
    if (!DEBUG) cin >> n;
    vi a(n);
    for (int i = 0; i < n; ++i) {
      if (!DEBUG) cin >> a[i];
      else a[i] = rand() % N + 1;
    }
    if (n == 1) {
      cout << 0 << '\n';
      break;
    }
    int ma = 2;
    for (int d = -M; d <= M; ++d) {
      if (abs(d) <= 1) {
        for (int i = 0; i < n; ++i) {
          int x = a[i] + d * i;
          w[x]++;
          ma = max(ma, w[x]);
        }
        w.clear();
      } else {
        for (int i = 0; i < n; ++i) {
          int x = a[i] + d * i;
          //        assert(abs(x) <= MAX);
          x += MAX;
          c[x]++;
          ma = max(ma, (int)c[x]);
        }
        for (int i = 0; i < n; ++i) {
          int x = a[i] + d * i;
          x += MAX;
          c[x] = 0;
        }
      }
    }
    int D = N / M + 2;
    for (int i = 0; i < n; ++i) {
      if (i >= D + 1) dyn[i - D - 1].clear();
      dyn[i].reserve(D);
      for (int j = i - 1; j >= max(0, i - D); --j) if ((a[i] - a[j]) % (i - j) == 0 || DEBUG) {
        int d = (a[i] - a[j]) / (i - j);
        if (abs(d) <= M) continue;
        dyn[i][d] = max(dyn[i][d], 1 + dyn[j][d]);
        ma = max(ma, dyn[i][d] + 1);
      }
    }
    cout << n - ma << '\n';
  }
  return 0;
}