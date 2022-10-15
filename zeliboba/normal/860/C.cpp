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
#include <array>
#include <bitset>
using namespace std;
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
//typedef long long int;

vs res;
map<string, int> w;
set<string> bad;
vs rem[2];

void mv(string s, string to) {
//  cerr << s << ' ' << to << endl;
  res.push_back(s);
  res.push_back(to);
  if (bad.count(s)) {
    bad.erase(s);
    rem[w[s]].push_back(s);
  }
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n;
  cin >> n;
  vs s(n);
  vi t(n);
  int r = 0;
  for (int i = 0; i < n; ++i) {
    cin >> s[i] >> t[i];
    r += t[i];
  }
  for (int i = 1; i <= n; ++i) {
    w[to_string(i)] = (i <= r);
  }
  vs todo[2], q[2];
  set<string> used;
  for (int i = 0; i < n; ++i) {
    if (w.count(s[i])) {
      if (w[s[i]] != t[i]) {
        bad.insert(s[i]);
        q[t[i]].push_back(s[i]);
      } else {
        used.insert(s[i]);
      }
    } else {
      todo[t[i]].push_back(s[i]);
    }
  }
  for (int i = 1; i <= n; ++i) if (!bad.count(to_string(i)) && !used.count(to_string(i))) {
//    cerr << "rem " << (i <= r) << ' ' << i << endl;
    rem[i <= r].push_back(to_string(i));
  }
  while (1) {
    if (rem[0].size() + rem[1].size() == 0) {
      if (q[0].size() + q[1].size() == 0) break;
      for (int t = 0; t < 2; ++t) if (!q[t].empty()) {
        mv(q[t].back(), "hgurld");
        todo[t].push_back("hgurld");
        q[t].pop_back();
        break;
      }
    }
    for (int t = 0; t < 2; ++t) {
      if (rem[t].size()) {
        if (q[t].size()) {
          mv(q[t].back(), rem[t].back());
          q[t].pop_back();
        } else {
          assert(!todo[t].empty());
          mv(todo[t].back(), rem[t].back());
          todo[t].pop_back();
        }
        rem[t].pop_back();
      }
    }
  }
  cout << res.size() / 2 << endl;
  for (int i = 0; i < res.size(); i += 2) {
    cout << "move " << res[i] << ' ' << res[i+1] << endl;
  }
  return 0;
}