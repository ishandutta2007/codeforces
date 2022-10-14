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

const int MOD = int(1e9) + 7;
void madd(int &a, int b) { if ((a += b) >= MOD) a -= MOD; }
int mmul(int a, int b) { return ll(a) * b % MOD; }
int mpow(int a, int b) {
  int res = 1;
  for (; b; b >>= 1, a = mmul(a, a))
    if (b & 1) res = mmul(res, a);
  return res;
}

const int MAXK = int(2e5) + 10;
int facs[MAXK + 1];
int ifacs[MAXK + 1];

void pc() {
  facs[0] = 1;
  for (int i = 1; i <= MAXK; i++) {
    facs[i] = mmul(facs[i - 1], i);
  }
  ifacs[MAXK] = mpow(facs[MAXK], MOD - 2);
  for (int i = MAXK - 1; i >= 0; i--) {
    ifacs[i] = mmul(ifacs[i + 1], i + 1);
  }
  #ifdef DEBUG
  for (int i = 0; i <= MAXK; i++) {
    assert(mmul(facs[i], ifacs[i]) == 1);
  }
  assert(facs[5] == 120);
  #endif
}

int getC(int n, int k) {
  assert(0 <= k && k <= n && n <= MAXK);
  return mmul(facs[n], mmul(ifacs[n - k], ifacs[k]));
}

int main() {
  #ifdef DEBUG
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
  #endif

  pc();

  int h, w, n;
  while (scanf("%d%d%d", &h, &w, &n) >= 1) {
    vector<pii> pts(n);
    for (pii &a : pts) {
      int x, y;
      scanf("%d%d", &y, &x);
      x--, y--;
      assert(0 <= x && x < w);
      assert(0 <= y && y < h);
      a = mp(x, y);
    }
    pts.pb(mp(w - 1, h - 1));
    sort(pts.begin(), pts.end());
    pts.erase(unique(pts.begin(), pts.end()), pts.end());
    n = sz(pts);
    assert(n && pts.back() == mp(w - 1, h - 1));

    vi dyn(n);
    forn (i, n) {
      int &ans = dyn[i];
      int x0 = pts[i].first, y0 = pts[i].second;
      ans = getC(x0 + y0, x0); 
//      eprintf("ans=%d\n", ans);
      forn (prev, i) {
        int x = pts[prev].first, y = pts[prev].second;
        if (x <= x0 && y <= y0) {
          int cans = dyn[prev];
          cans = mmul(cans, getC(x0 - x + y0 - y, x0 - x));
          madd(ans, MOD - cans);
        }
      }
    }
    printf("%d\n", dyn.back());
  }
  return 0;
}