#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>

using namespace std;

#define pb push_back
#define mp make_pair
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define sz(x) ((int)(x).size())

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;

typedef pair<int, ll> Line;
const double eps = 1e-9;

double cross(const Line &a, const Line &b) {
  assert(a.second != b.second);
  double x = double(b.second - a.second) / (a.first - b.first);
/*  #ifdef DEBUG
  assert(fabs(a.first * x + a.second - b.first * x - b.second) < 1e-6);
  #endif*/
  return x;
}

class Solver {
  vector<Line> ls;
  vector<double> sxs;

  ll calc(const Line &l, int x) { return ll(l.first) * x + l.second; }

  public:
  Solver() : ls(), sxs() {}
  // a descends
  void add(int a, ll b) {
    while (!sxs.empty()) {
      double x = sxs.back();
      double y = ls.back().first * x + ls.back().second;
      if (a * x + b <= y + eps) {
        ls.pop_back();
        sxs.pop_back();
      } else {
        break;
      }
    }
    ls.pb(mp(a, b));
    if (sz(ls) >= 2) {
      Line l1 = ls[sz(ls) - 2], l2 = ls[sz(ls) - 1];
      sxs.pb(cross(l1, l2));
    }
    assert(sz(ls) - 1 == sz(sxs));
  }
  // ascends
  ll getMinVal(int x) {
    assert(!ls.empty());
    assert(sz(ls) - 1 == sz(sxs));

    int ptr = lower_bound(sxs.begin(), sxs.end(), x) - sxs.begin();
    assert(0 <= ptr && ptr < sz(ls));

    ll res = calc(ls[ptr], x);
    for (int d = -1; d <= 1; d++) if (ptr + d >= 0 && ptr + d < sz(ls))
      res = min(res, calc(ls[ptr + d], x));
    return res;
  }
};

int main() {
  #ifdef DEBUG
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
  #endif

  int n;
  while (scanf("%d", &n) >= 1) {
    vi as(n), bs(n);
    for (int i = 0; i < n; i++)
      scanf("%d", &as[i]);
    for (int i = 0; i < n; i++)
      scanf("%d", &bs[i]);

    vector<ll> ps(n);
    ps[0] = ll(as[0]) * bs[n - 1];
    for (int i = 1; i < n; i++) {
      ps[i] = ps[i - 1];
      ps[i] += ll(as[i]) * bs[n - 1];
    }

    vector<ll> dyn(n);
    Solver s;
    dyn[0] = 0;
    s.add(bs[0], dyn[0] - ps[0]);

    for (int i = 1; i < n; i++) {
      ll val = s.getMinVal(as[i]) + ps[i - 1];
      dyn[i] = val;
      s.add(bs[i], dyn[i] - ps[i]);
    }
    printf("%I64d\n", dyn.back());
  }
  return 0;
}