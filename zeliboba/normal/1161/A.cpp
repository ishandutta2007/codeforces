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

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n, k;
  cin >> n >> k;
  vi x(k);
  vi b(n, -1), e(n, -1);
  for (int i = 0; i < k; ++i) {
    cin >> x[i];
    --x[i];
    e[x[i]] = i;
    if (b[x[i]] == -1) b[x[i]] = i;
  }
  int res = 0;
  for (int i = 0; i < n; ++i) {
    if (b[i] == -1) ++res;
    for (int j : {i-1, i+1}) if (j >= 0 && j < n) {
      if (b[j] == -1 || b[i] == -1 || b[i] > e[j]) {
//        cerr << i << ' ' << j << endl;
        ++res;
      }
    }
  }
  cout << res << endl;
  return 0;
}