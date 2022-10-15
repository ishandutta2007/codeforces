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
  int n, q;
  cin >> n;
  vi a(n), last(n, -1);
  for (int i = 0; i < n; ++i) cin >> a[i];
  cin >> q;
  vi t, v;
  for (int j = 0; j < q; ++j) {
    int type;
    cin >> type;
    if (type == 1) {
      int p, x;
      cin >> p >> x;
      a[p - 1] = x;
      last[p - 1] = j;
    } else {
      int x;
      cin >> x;
      t.push_back(j);
      v.push_back(x);
    }
  }
  for (int i = (int)t.size() - 2; i >= 0; --i) {
    v[i] = max(v[i], v[i + 1]);
  }
  for (int i = 0; i < n; ++i) {
    int it = lower_bound(t.begin(), t.end(), last[i]) - t.begin();
    if (it < t.size()) {
      a[i] = max(a[i], v[it]);
    }
    cout << a[i] << ' ';
  }
  cout << endl;
  return 0;
}