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

const int MOD = 1e9 + 7;
void madd(int &a, int b) { if ((a += b) >= MOD) a -= MOD; }
int mmul(int a, int b) { return ll(a) * b % MOD; }

const int INF = 1e9;

class Solver {
  static const int MAXN = 51 * 51 * 2 + 100;
  static const int MAXE = MAXN * 51 * 51 + 100;

  int n;

  int firs[MAXN];
  struct Edge {
    int b, ne;
    int cnt;
  } es[MAXE];
  int ecnt;

  public:
  Solver() : n(0), ecnt(0) {}
  void init(int _n) {
    assert(n <= MAXN);
    n = _n;
    ecnt = 0;
    memset(firs, -1, sizeof(firs[0]) * n);
  }
  void adde(int a, int b, int cnt) {
    assert(0 <= a && a < n);
    assert(0 <= b && b < n);
    assert(ecnt < MAXE);

//    eprintf("adde(%d, %d)\n", a, b);
    es[ecnt].b = b;
    es[ecnt].ne = firs[a];
    es[ecnt].cnt = cnt;
    firs[a] = ecnt;
    ecnt++;
  }
  pii solve(int st, int en) {
    assert(0 <= st && st < n);
    assert(0 <= en && en < n);
    static pii d[MAXN];
    static int q[MAXN];
    for (int i = 0; i < n; i++) {
      d[i] = mp(INF, 0);
    }

    int qe = 0;
    d[st] = mp(0, 1);
    q[qe++] = st;
    for (int qb = 0; qb < qe;) {
      int v = q[qb]; qb++;
      int nd = d[v].first + 1;

      for (int i = firs[v]; i >= 0; i = es[i].ne) {
        int b = es[i].b;
        if (d[b].first < nd) continue;
        if (d[b].first > nd) {
          assert(qe < MAXN);
          q[qe++] = b;
        }
        d[b].first = d[v].first + 1;
        madd(d[b].second, mmul(d[v].second, es[i].cnt));
      }
    }
    return d[en];
  }
};

Solver s;

const int MAXN = 60;
int cs[MAXN + 1][MAXN + 1];

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  for (int n = 0; n <= MAXN; n++) {
    cs[n][0] = cs[n][n] = 1;
    for (int k = 1; k < n; k++) {
      cs[n][k] = cs[n - 1][k - 1];
      madd(cs[n][k], cs[n - 1][k]);
    }
  }

  int n, sumw;
  while (scanf("%d%d", &n, &sumw) >= 1) {
    sumw /= 50;
    eprintf("n=%d, sumw=%d ==========\n", n, sumw);

    int c1 = 0, c2 = 0;
    for (int i = 0; i < n; i++) {
      int x;
      scanf("%d", &x);
      if (x == 50) c1++;
      else c2++;
    }

    s.init((c1 + 1) * (c2 + 1) * 2);
    for (int a = 0; a <= c1; a++)
    for (int b = 0; b <= c2; b++)
    for (int sd = 0; sd < 2; sd++) {
      int ag = sd == 0 ? a : c1 - a;
      int bg = sd == 0 ? b : c2 - b;

      for (int xa = 0; xa <= ag; xa++) {
      for (int xb = 0; xb <= bg; xb++) if (xa + xb && (xa + 2 * xb <= sumw)) {
        int an = a, bn = b;
        if (sd == 0) an -= xa, bn -= xb;
        else an += xa, bn += xb;

        assert(0 <= an && an <= c1);
        assert(0 <= bn && bn <= c2);
        s.adde(
          (a * (c2 + 1) + b) * 2 + sd,
          (an * (c2 + 1) + bn) * 2  + !sd,
          mmul(cs[ag][xa], cs[bg][xb])
        );
      }
      }
    }
    pii res = s.solve(
      (c1 * (c2 + 1) + c2) * 2 + 0,
      1
    );
    if (res.first >= INF) printf("-1\n0\n");
    else
      printf("%d\n%d\n", res.first, res.second);
  }
  return 0;
}