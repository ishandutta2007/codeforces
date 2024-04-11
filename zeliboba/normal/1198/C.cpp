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
  int T;
  cin >> T;
  for (int test = 1; test <= T; ++test) {
    int n, m;
    cin >> n >> m;
    vii e;
//    vvi g(3 * n);
    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      --a; --b;
      e.emplace_back(a, b);
//      g[a].push_back(b);
//      g[b].push_back(a);
    }
    vi match;
    vi was(3 * n);
    int it = 0;
    while (it < e.size() && match.size() < n) {
      pii p = e[it];
      int a = p.first, b = p.second;
      if (!was[a] && !was[b]) {
        match.push_back(it + 1);
        was[a] = was[b] = 1;
      }
      ++it;
    }
    if (match.size() == n) {
      cout << "Matching\n";
      for (int x : match) cout << x << ' ';
    } else {
      cout << "IndSet\n";
      int c = 0;
      for (int i = 0; c < n && i < was.size(); ++i) if (!was[i]) {
        cout << i + 1 << ' ';
        ++c;
      }
      assert(c == n);
    }
    cout << '\n';
  }
  return 0;
}