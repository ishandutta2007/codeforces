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
const int mod = 1e9 + 7;

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int T;
  cin >> T;
  for (int tt = 0; tt < T; ++tt) {
    int n;
    cin >> n;
    vector<array<int, 2>> v(n);
    for (int i = 0; i < 2; ++i) for (int j = 0; j < n; ++j) {
      cin >> v[j][i];
      --v[j][i];
    }
    ll res = 1;
    vvi g(n);
    for (int i = 0; i < n; ++i) {
      g[v[i][0]].push_back(v[i][1]);
      g[v[i][1]].push_back(v[i][0]);
    }
    for (int i = 0; i < n; ++i) if (g[i].size() != 2) res = 0;
    if (res) {
      vi w(n);
      for (int i = 0; i < n; ++i) if (!w[i]) {
        w[i] = 1;
        res = res * 2 % mod;
        int pr = i, cur = g[i][0];
        while (!w[cur]) {
//          cerr << pr << ' ' << cur << endl;
          w[cur] = 1;
          for (int t : g[cur]) if (t != pr) {
            pr = cur;
            cur = t;
            break;
          }
        }
      }
    }
    cout << res << endl;
  }
  return 0;
}