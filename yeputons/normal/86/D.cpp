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

struct Req {
  int l, r, id;
  bool operator<(const Req &r2) const { return r < r2.r; }
};
const int STEP = 800;
const int MAXV = 1e6;

int cnt[MAXV + 1];
inline void change(int x, int d, ll &cur) {
  cur -= ll(cnt[x]) * cnt[x] * x;
  cnt[x] += d;
  cur += ll(cnt[x]) * cnt[x] * x;
}

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int n, m;
  while (scanf("%d%d", &n, &m) >= 1) {
    vi as(n);
    for (int i = 0; i < n; i++)
      scanf("%d", &as[i]);

    vll ans(m, 0);
    
    vector<vector<Req> > rs((n + STEP - 1) / STEP);
    for (int i = 0; i < m; i++) {
      Req r;
      scanf("%d%d", &r.l, &r.r), r.l--, r.r--;
      r.id = i;

      rs[r.l / STEP].pb(r);
    }

    memset(cnt, 0, sizeof cnt);
    for (int st = 0; st < sz(rs); st++) {
      eprintf("%d/%d\n", st, sz(rs));
      vector<Req> &crs = rs[st];

      int cl = st * STEP, cr = cl - 1;
      sort(crs.begin(), crs.end());
      ll cur = 0;

      for (int i = 0; i < sz(crs); i++) {
        while (cr < crs[i].r) {
          cr++;
          change(as[cr], 1, cur);
        }
        while (cl < crs[i].l) {
          change(as[cl], -1, cur);
          cl++;
        }
        while (crs[i].l < cl) {
          cl--;
          change(as[cl], 1, cur);
        }
        ans[crs[i].id] = cur;
      }
      while (cl <= cr) {
        change(as[cl], -1, cur);
        cl++;
      }
    }
    for (int i = 0; i < m; i++)
      printf("%I64d\n", ans[i]);
  }
  return 0;
}