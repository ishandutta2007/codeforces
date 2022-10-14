#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <iostream>

#define pb push_back
#define mp make_pair
#define TASKNAME ""

#ifdef DEBUG
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
#define eprintf(...)
#endif

#define TIMESTAMP(x) eprintf("[" #x "] Time = %.3lfs\n",clock()*1.0/CLOCKS_PER_SEC)

#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

#define sz(x) ((int)(x).size())
#define forn(i, n) for (int i = 0; i < (n); i++)

using namespace std;

typedef long double ld;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;

const int inf = 1e9;
const double eps = 1e-9;
const int INF = inf;
const double EPS = eps;

#ifdef DEBUG
struct __timestamper {
  ~__timestamper(){
    TIMESTAMP(end);
  }
} __Timestamper;
#else
struct __timestamper {};
#endif

/*Template end*/

class Solver {
  vvi es;
  vi p1, p2;

  vb was;
  bool dfs(int v) {
    if (was.at(v)) return false;
    was[v] = true;
    for (int b : es[v]) {
      if (p2[b] < 0 || dfs(p2[b])) {
        p1[v] = b;
        p2[b] = v;
        return true;
      }
    }
    return false;
  }

public:
  Solver(int n1, int n2) : es(n1), p1(n1, -1), p2(n2, -1) {}
  bool solve() {
    vi ord;
    forn (i, sz(p1)) ord.pb(i);
    random_shuffle(ord.begin(), ord.end());

    for (int i : ord) {
      random_shuffle(es[i].begin(), es[i].end());
    }

    for (int i : ord) if (p1[i] < 0) {
      was = vb(sz(p1), false);
      if (!dfs(i)) return false;
    }
    return true;
  }
  void adde(int a, int b) {
    assert(0 <= a && a < sz(p1));
    assert(0 <= b && b < sz(p2));
    es[a].pb(b);
  }
  vi getP1() const { return p1; }
  vi getP2() const { return p2; }
};

const int MAXS = int(2e4) + 100;
bool isp[MAXS];

int main() {
  #ifdef DEBUG
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif

  memset(isp, 1, sizeof isp);
  isp[1] = false;
  for (int i = 2; i <= MAXS; i++) if (isp[i]) {
    for (int i2 = min(MAXS + 1LL, ll(i) * i); i2 <= MAXS; i2 += i)
      isp[i2] = false;
  }

  int n;
  while (scanf("%d", &n) == 1) {
    vi as(n);
    for (int &x : as) scanf("%d", &x);

    vi ids(n);
    vi s0, s1;
    forn (i, n) {
      if (as[i] % 2 == 0) {
        ids[i] = sz(s0); s0.pb(i);
      } else {
        ids[i] = sz(s1); s1.pb(i);
      }
    }

    int ops = 0;
    while (ops++ < 1) {
      Solver s(sz(s0), sz(s1));
      forn (i, n)
      forn (j, n) if (isp[as[i] + as[j]]) {
        assert(as[i] % 2 != as[j] % 2);
        int v1 = ids[i], v2 = ids[j];
        if (as[i] % 2 == 0) {
          s.adde(v1, v2);
        }
      }
      if (!s.solve()) {
        printf("Impossible\n");
        goto end;
      }
      vi p1 = s.getP1();
      vi p2 = s.getP2();

      s = Solver(sz(s0), sz(s1));
      forn (i, n)
      forn (j, n) if (isp[as[i] + as[j]] && p1[ids[i]] != ids[j]) {
        assert(as[i] % 2 != as[j] % 2);
        int v1 = ids[i], v2 = ids[j];
        if (as[i] % 2 == 0) {
          s.adde(v1, v2);
        }
      }
      if (!s.solve()) {
        continue;
      }

      vi p1b = s.getP1();
      vi p2b = s.getP2();

      vb was(n, false);
      assert(sz(s0) == sz(s1));
      vvi anses;
      for (int i = 0; i < sz(s0); i++) {
        int x = s0[i];
        if (was[x]) continue;

        vi cur;
        while (!was[x]) {
          cur.pb(x);
          was[x] = true;
          int y = s1[p1[ids[x]]];
          cur.pb(y);
          assert(!was[y]);
          was[y] = true;
          x = s0[p2b[ids[y]]];
        }
        anses.pb(cur);
      }
      printf("%d\n", sz(anses));
      for (vi &sq : anses) {
        printf("%d", sz(sq));
        for (int x : sq)
          printf(" %d", x + 1);
        printf("\n");
      }
      goto end;
    }
    printf("Impossible\n");

    end:;
  }

  return 0;
}