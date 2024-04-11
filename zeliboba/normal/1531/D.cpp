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

const int N = 100001;
bitset<N> cur, ones;

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n;
  cin >> n;
  ones.set();
  vs s(n + 1, "blue");
  cur[n] = 1;
  set<int> w;
  bool lock = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> s[i];
    if (s[i] == "lock" || s[i] == "unlock") {
      w.insert(i);
      if (s[i] == "lock") lock = 1;
      else lock = 0;
    } else cur[n - i] = !lock;
  }
  int T;
  cin >> T;
  for (int test = 0; test <= T; ++test) {
//    for (int i = 0; i <= n; ++i) cerr << cur[i];
//    cout << n - cur._Find_first() << endl;
    cout << s[n - cur._Find_first()] << '\n';
    if (test < T) {
      int i;
      string t;
      cin >> i >> t;
      int j = n - i;
      if (t == "lock" || t == "unlock") {
        cur[j] = 0;
        w.insert(i);
        auto it = w.lower_bound(i + 1);
        int nx = it == w.end() ? n + 1 : *it;
        int j1 = n - nx;
        int len = j - j1 - 1;
        if (t == "unlock") {
          cur |= (ones >> (N - len)) << (j1 + 1);
        } else {
          cur &= ones ^ ((ones >> (N - len)) << (j1 + 1));
        }
      } else {
        if (w.count(i)) {
          auto it = w.lower_bound(i);
          bool lock = false;
          if (it != w.begin()) {
            --it;
            lock = s[*it] == "lock";
            ++it;
          }
          int nx = n + 1;
           ++it;
          if (it != w.end()) {
            nx = *it;
          }
          int j1 = n - nx;
          int len = j - j1;
          if (!lock) {
            cur |= (ones >> (N - len)) << (j1 + 1);
          } else {
            cur &= ones ^ ((ones >> (N - len)) << (j1 + 1));
          }
        }
//        cur[j] = 1;
        w.erase(i);
      }
      s[i] = t;
//      cerr << i << ' ' << s[i] << endl;
    }
  }
  return 0;
}