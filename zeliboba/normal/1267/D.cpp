#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef pair<double, double> pdd;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
//const int mod = ;

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n;
  cin >> n;
  vi need(n), good(n);
  for (int i = 0; i < n; ++i) for (int j = 0; j < 3; ++j) {
    int t;
    cin >> t;
    need[i] |= t << j;
  }
  vi tc(n, 1);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 3; ++j) {
      int t;
      cin >> t;
      good[i] |= t << j;
    }
    good[i] &= need[i];
    if (__builtin_popcount(need[i]) == 1) {
      good[i] = need[i];
      tc[i] = 0;
    }
  }
  vii e;
  vi was(n);
  bool fail = false;
  was[0] = 1;
  vvi added(8);
  for (int i = 1; i < n; ++i) {
    if (need[i] == 7) {
      e.emplace_back(0, i);
      was[i] = 1;
      added[good[i]].push_back(i);
    } else if (need[i] == 0) {
      was[i] = 1;
    }
  }
  for (int t = 0; t < n; ++t) {
    bool upd = false;
    for (int i = 0; i < n; ++i) if (was[i]) for (int j = 0; j < n; ++j) {
      if (!was[j] && need[j] == good[i]) {
        was[j] = 1;
        added[good[j]].push_back(j);
        e.emplace_back(i, j);
        upd = 1;
      }
    }
    if (upd) continue;
    for (int j = 0; j < n; ++j) if (!was[j] && __builtin_popcount(need[j]) == 2) {
      vi x;
      for (int b = 0; b < 3; ++b) if (need[j] & (1 << b)) x.push_back(1 << b);
      if (added[x[0]].size() && added[x[1]].size()) {
        was[j] = 1;
        e.emplace_back(added[x[0]][0], j);
        e.emplace_back(added[x[1]][0], j);
        tc[j] = 0;
        good[j] = need[j];
        upd = 1;
        break;
      }
    }
    if (!upd) break;
  }
  for (int i = 0; i < n; ++i) if (!was[i]) fail = 1;
  if (fail) cout << "Impossible\n";
  else {
    cout << "Possible\n";
    for (int x : tc) cout << x << ' ';
    cout << endl << e.size() << endl;
    assert(e.size() <= 264);
    for (pii p : e) cout << p.first + 1 << ' ' << p.second + 1 << endl;
  }
  return 0;
}