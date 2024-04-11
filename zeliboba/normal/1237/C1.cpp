#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
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

const int DEBUG = 0;

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  for (int tt = 0; tt <= DEBUG * 1000; ++tt) {
  int n = 4;
  if (!DEBUG) cin >> n;
  set<array<int, 4>> a;
  vi was(n);
  vector<array<int, 4>> a0(n);
  for (int i = 0; i < n; ++i) {
    array<int, 4> x;
    x[3] = 0;
    for (int j = 0; j < 3; ++j) {
      if (!DEBUG) cin >> x[j];
      else x[j] = rand() % 5;
    }
    if (DEBUG) {
      while (1) {
        bool go = 0;
        for (int i1 = 0; i1 < i; ++i1) if (x == a0[i1]) {
          go = 1;
          for (int j = 0; j < 3; ++j) x[j] = rand() % 5;
        }
        if (!go) break;
      }
    }
    cerr << x[0] << ' ' << x[1] << ' ' << x[2] << endl;
    a0[i] = x;
    x[3] = i + 1;
    a.insert(x);
  }
  while (!a.empty()) {
    auto it = a.end(); --it;
    auto ai = *it; --it;
    auto ai1 = *it;
    for (int j = 0; j < 3; ++j) if (ai[j] != ai1[j]) {
      auto x = ai;
      x[3] = -1;
      x[j] = ai1[j];
      auto it = a.lower_bound(x);
      auto ait = *it;
      if (it != a.begin() && j + 1 < 3 && ait[j + 1] != x[j + 1]) {
        --it;
        if ((*it)[j + 1] == x[j + 1] && (*it)[j] == x[j]) {
          ait = *it;
          j = 3;
        }
      }
      if (ait == ai && j + 1 < 3) {
        x[j + 1] = ai1[j + 1];
        ait = *a.lower_bound(x);
      }
//      cerr << x[0] << ' ' << x[1] << ' ' << x[2] << endl;
      if (ait != ai && j == 0) {
//        cerr << i << ' ' << it << ' ' << x[0] << ' ' << x[1] << ' ' << x[2] << endl;
        x[j + 1] = ait[j + 1];
        auto it = a.lower_bound(x);
        if ((*it)[j + 1] != x[j + 1]) {
          --it;
        }
        ait = *it;
      }
      if (ait == ai) ait = ai1;
      cout << ai[3] << ' ' << ait[3] << endl;
      assert(!was[ai[3] - 1] && !was[ait[3]-1]);
      was[ai[3] - 1] = was[ait[3]-1] = 1;
      if (DEBUG) {
        array<int, 3> mi;
        array<int, 3> ma = {0,0,0};
        for (int i = 0; i < 3; ++i) {
          mi[i] = min(ai[i], ait[i]);
          ma[i] = max(ai[i], ait[i]);
        }
        for (int i = 0; i < n; ++i) if (!was[i]) {
          bool in = 1;
          for (int j = 0; j < 3; ++j) {
            if (a0[i][j] < mi[j] || a0[i][j] > ma[j]) in = 0;
          }
          if (in) {
            cerr << i + 1 << endl;
            cerr << ai[0] << ' ' << ai[1] << ' ' << ai[2] << endl;
            cerr << ait[0] << ' ' << ait[1] << ' ' << ait[2] << endl;
            cerr << a0[i][0] << ' ' << a0[i][1] << ' ' << a0[i][2] << endl;
            assert(0);
          }
        }
      }
      a.erase(ai);
      a.erase(ait);
      break;
    }
  }
  }
  return 0;
}