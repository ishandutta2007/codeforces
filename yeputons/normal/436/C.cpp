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
#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...)
#endif
#define sz(x) ((int)(x).size())
#define forn(i, n) for (int i = 0; i < (n); i++)

#ifdef DEBUG
struct Timestamper {
  string msg;
  clock_t start;

  Timestamper(const string &_msg) : msg(_msg), start(clock()) {}
  ~Timestamper() {
    eprintf("[ %s ] Time=%.3lfs\n", msg.c_str(), (clock() - start) * 1.0 / CLOCKS_PER_SEC);
  }
} __timestamper("end");
#else
struct Timestamper {};
#endif

typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<ll, ll> pll;

const int inf = 1e9;

class Dsu {
  vi par, ss;

public:
  Dsu(int n) : par(n), ss(n, 0) {
    forn (i, n) par[i] = i;
  }
  int get(int x) { return par[x] == x ? x : par[x] = get(par[x]); }
  bool merge(int a, int b) {
    a = get(a); b = get(b);
    if (a == b) return false;
    if (ss[a] > ss[b]) swap(a, b);
    par[a] = b;
    if (ss[a] == ss[b]) ss[b]++;
    return true;
  }
};

class Solver {
  vector<pair<int, pii>> es;
  Dsu dsu;

public:
  Solver(int n) : dsu(n) {}
  void adde(int a, int b, int w) {
    es.pb(mp(w, mp(a, b)));
  }
  pair<int, vector<pii>> solve() {
    int sum = 0;
    sort(es.begin(), es.end());
    vector<pii> ans;
    for (auto e : es) {
      int a, b;
      tie(a, b) = e.second;
      if (dsu.merge(a, b)) ans.pb(e.second), sum += e.first;
    }
    return mp(sum, ans);
  }
};

vvi chi;
vector<pii> anses;
void dfs(int v, int par = -1) {
  for (int b : chi[v]) if (b != par) {
    anses.pb(mp(b, v));
    dfs(b, v);
  }
}

int main() {
  #ifdef DEBUG
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
  #endif

  int h, w, n, dcost;
  while (scanf("%d%d%d%d", &h, &w, &n, &dcost) >= 1) {
    const int MAXN = 1010;
    const int MAXH = 15;
    const int MAXW = 15;
    static char f[MAXN][MAXH][MAXW + 1];
    forn (i, n)
    forn (y, h)
      scanf("%s", f[i][y]);

    Solver s(n + 1);
    forn (a, n) {
      s.adde(a, n, h * w);
      for (int b = 0; b < a; b++) {
        int su = 0;
        forn (y, h)
        forn (x, w)
          su += f[a][y][x] != f[b][y][x];
        s.adde(a, b, su * dcost);
      }
    }
    int sum;
    vector<pii> aes;
    tie(sum, aes) = s.solve();
    chi = vvi(n + 1);
//    eprintf("\n");
    for (pii e : aes) {
//      eprintf("%d %d\n", e.first, e.second);
      chi[e.first].pb(e.second);
      chi[e.second].pb(e.first);
    }
    anses.clear();
    dfs(n);

    printf("%d\n", sum); 
    for (pii x : anses) {
      if (x.second == n) x.second = -1;
      printf("%d %d\n", x.first + 1, x.second + 1);
    }
    #ifdef DEBUG
    printf("\n");
    #endif
  }
  return 0;
}