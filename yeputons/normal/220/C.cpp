#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <map>
#include <set>

using namespace std;

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;

class Solver {

  int n;
  vector<vector<pii> > epl, emi;

  public:
  Solver(int n) : n(n), epl(n + 1), emi(n + 1) { }
  void add(int l, int r, int sval, int ty) {
    assert(0 <= l && l <= r && r < n);
    assert(0 <= sval);
    assert(ty == 1 || ty == -1);
    if (ty == -1) {
      assert(r - l <= sval);
    }
    
    if (ty == 1) {
      epl[l].pb(mp(1, sval)); 
      epl[r + 1].pb(mp(-1, sval + r - l + 1)); 
    } else {
      emi[l].pb(mp(1, sval)); 
      emi[r + 1].pb(mp(-1, sval - (r - l + 1))); 
    }
  }
  vi solve() {
    vi res(n, 1e9);
    for (int step = 0; step < 2; step++) {
      multiset<int> vals;
      int ck = 0;
      for (int i = 0; i < n; i++) {
        for (int i2 = 0; i2 < sz(epl[i]); i2++)
          if (epl[i][i2].first == 1) {
            vals.insert(epl[i][i2].second - ck);
          } else {
            #ifdef DEBUG
            assert(vals.count(epl[i][i2].second - ck));
            #endif
            vals.erase(vals.find(epl[i][i2].second - ck));
          }

        if (!vals.empty()) res[i] = min(res[i], *vals.begin() + ck);
        if (step == 0) ck++;
        else ck--;
      }
      epl.swap(emi);
    }
    return res;
  }
};

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int n;
  while (scanf("%d", &n) >= 1) {
    vi as(n);
    for (int i = 0; i < n; i++)
      scanf("%d", &as[i]), as[i]--;

    vi posb(n);
    for (int i = 0; i < n; i++) {
      int b;
      scanf("%d", &b), b--;
      posb[b] = i;
    }

    for (int i = 0; i < n; i++)
      as[i] = posb[as[i]];

    Solver s(n);
    for (int i = 0; i < n; i++) {
      if (i <= as[i]) {
        s.add(0, as[i] - i, as[i] - i, -1);
        if (i > 0)
          s.add(as[i] - i + 1, as[i], 1, +1);
        if (as[i] < n - 1)
          s.add(as[i] + 1, n - 1, n - 1 - i, -1);
      } else {
        // as[i] < i
        s.add(0, as[i], i - as[i], +1);
        s.add(as[i] + 1, as[i] + n - i, n - 1 - i, -1);
        if (as[i] + 1 <= i - 1)
          s.add(as[i] + n - i + 1, n - 1, 1, +1);
      }
    }
    vi res = s.solve();
    for (int i = 0; i < n; i++)
      printf("%d\n", res[i]);
  }
  return 0;
}