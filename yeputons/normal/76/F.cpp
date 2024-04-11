#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <string>
#include <vector>

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

const int INF = 1e9;
const ll INFLL = 1e18;

class fenv_tree1 {
  vi tr;
  vi xs;
  static int f(int x) { return x ^ (x & (x - 1)); }

  public:
  fenv_tree1() {}
  fenv_tree1(int n) : tr(n + 1, -INF) {}
  void relax(int x, int val) {
    for (x++; x > 0; x -= f(x))
      tr[x] = max(tr[x], val);
  }
  int get(int l) {
    int res = -INF;
    for (l++; l < sz(tr); l += f(l))
      res = max(res, tr[l]);
    return res;
  }
};

ll ar, br;
ll al, bl;
struct Ev {
  int x, t;
  bool operator<(const Ev &e) const { return yl != e.yl ? yl > e.yl : yr > e.yr; }
  int yl, yr;

  ll g_yl() { return al * x + bl * t; }
  ll g_yr() { return ar * x + br * t; }
};
int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int n;
  while (scanf("%d", &n) >= 1) {
    vector<Ev> evs(n);
    for (int i = 0; i < n; i++)
      scanf("%d%d", &evs[i].x, &evs[i].t);

    int v;
    scanf("%d", &v);
    ar = -1, br = v;
    al = 1, bl = v;

    vll yls, yrs;
    for (int i = 0; i < n; i++)
      yls.pb(evs[i].g_yl()),
      yrs.pb(evs[i].g_yr());
    sort(yls.begin(), yls.end());
    yls.resize(unique(yls.begin(), yls.end()) - yls.begin());
    sort(yrs.begin(), yrs.end());
    yrs.resize(unique(yrs.begin(), yrs.end()) - yrs.begin());

    for (int i = 0; i < n; i++) {
      evs[i].yl = lower_bound(yls.begin(), yls.end(), evs[i].g_yl()) - yls.begin();
      evs[i].yr = lower_bound(yrs.begin(), yrs.end(), evs[i].g_yr()) - yrs.begin();
    }

    sort(evs.begin(), evs.end());
    vi ans(n);

    fenv_tree1 tr(sz(yrs));

    for (int st = 0; st < n;) {
      int cyl = evs[st].yl;
      int en = st;
      for (; en < n && evs[en].yl == cyl; en++);

      for (int i = st; i < en; i++) {
        ans[i] = max(0, tr.get(evs[i].yr)) + 1;
        tr.relax(evs[i].yr, ans[i]);
      }
      st = en;
    }

    int ans1 = 0, ans2 = 0;
    for (int i = 0; i < n; i++) {
      if (evs[i].g_yl() >= 0 && evs[i].g_yr() >= 0)
          ans1 = max(ans1, ans[i]);
      ans2 = max(ans2, ans[i]);
    }
    printf("%d %d\n", ans1, ans2);
  }
  return 0;
}