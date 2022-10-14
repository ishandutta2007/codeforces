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
class Solver {
  int n1, n2;
  vvi scs;
  vvi cs;

  vi p1, p2;

  public:
  Solver(int _n1, int _n2) : n1(_n1), n2(_n2), cs(n1, vi(n2, INF)) {  }
  void add(int a, int b, int c) {
    cs[a][b] = min(cs[a][b], c);
  }
  int solve() {
    scs = cs;
    p1.assign(n1, -1);
    p2.assign(n2, -1);
    int ans = 0;

    for (;; ans++) {
      vb red(n1, false);
      vi d1(n1, INF), fr1(n1, -1);
      vi d2(n2, INF), fr2(n2, -1);
      for (int i = 0; i < n1; i++)
        if (p1[i] < 0) d1[i] = 0;

      for (;;) {
        int minv = INF, mini = -1;
        for (int i = 0; i < n1; i++)
          if (!red[i] && d1[i] < minv) {
            minv = d1[i];
            mini = i;
          }
        if (mini < 0) break;

        red[mini] = true;
        for (int b = 0; b < n2; b++) {
          if (d2[b] > minv + cs[mini][b]) {
            d2[b] = minv + cs[mini][b];
            fr2[b] = mini;
          }
          if (p2[b] >= 0) {
            int nb = p2[b];
            int nd = minv + cs[mini][b] + cs[nb][b];
            if (nd < d1[nb]) {
              d1[nb] = nd;
              fr1[nb] = mini;
            }
          }
        }
      }

      int rminv = INF, rmini = -1;
      for (int i = 0; i < n2; i++)
        if (p2[i] < 0 && d2[i] < rminv) { rminv = d2[i]; rmini = i; }
      if (rmini < 0) break;

      for (int a = 0; a < n1; a++)
      for (int b = 0; b < n2; b++) if (cs[a][b] < INF) {
        cs[a][b] += d1[a] - d2[b];
        assert(cs[a][b] >= 0);
      }

      for (int b = rmini; b >= 0;) {
        int a = fr2[b];
        assert(a >= 0);

        int nb = p1[a];
        p1[a] = b;
        p2[b] = a;

        b = nb;
      }
      for (int i = 0; i < n1; i++)
        if (p1[i] >= 0) assert(p2[p1[i]] == i);
      for (int i = 0; i < n2; i++)
        if (p2[i] >= 0) assert(p1[p2[i]] == i);
    }
    return ans;
  }

  int getp2(int x) { return p2[x]; }
};

string gset(int a, int val) {
  char buf[16];
  snprintf(buf, sizeof buf, "%d", val);
  return string(1, 'a' + a) + "=" + buf;
}
string gpr(int a) {
  return string("print(") + string(1, 'a' + a) + string(")");
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

    Solver s(n + m, n);
    for (int b = 0; b < n; b++) {
      for (int a = 0; a < b; a++)
        s.add(a, b, as[a] == as[b] ? 0 : __builtin_popcount(as[b]));
      for (int a = 0; a < m; a++)
        s.add(n + a, b, __builtin_popcount(as[b]));
    }

    assert(s.solve() == n);
    vi fir(m, -1);
    vi ne(n, -1);
    for (int b = 0; b < n; b++) {
      int p1 = s.getp2(b);

      assert(p1 >= 0);
      if (p1 < n) ne[p1] = b;
      else fir[p1 - n] = b;
    }

    vector<string> res;
    vi cval(m, -1);
    int price = 0;

    for (int i = 0; i < m; i++)
      if (fir[i] >= 0) {
        res.pb(gset(i, as[fir[i]]));
        price += __builtin_popcount(as[fir[i]]);
        cval[i] = fir[i];
      }
    for (int i = 0; i < n; i++) {
      int vid = -1;
      for (int i2 = 0; i2 < m; i2++)
        if (cval[i2] == i) {
          vid = i2;
          break;
        }
      assert(vid >= 0);
      res.pb(gpr(vid));
      if (ne[i] >= 0) {
        if (as[i] != as[ne[i]]) {
          price += __builtin_popcount(as[ne[i]]);
          res.pb(gset(vid, as[ne[i]]));
        }
        cval[vid] = ne[i];
      }
    }
    printf("%d %d\n", sz(res), price);
    for (int i = 0; i < sz(res); i++)
      printf("%s\n", res[i].c_str());
  }
  return 0;
}