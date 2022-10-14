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

const int MAXN = int(1e5);
int facs[MAXN + 1];
int ifacs[MAXN + 1];

vvi es;
vi col;
int ccnt;

void dfs1(int v) {
  if (col[v] >= 0) {
    assert(col[v] == ccnt);
    return;
  }
  col[v] = ccnt;
  for (int b : es[v])
    dfs1(b);
}

vector<pii> bcol;
int bccnt;
vvi bes;

bool dfs2(int v, int ty) {
  if (bcol[v].first >= 0) {
    assert(bcol[v].first == bccnt);
    return bcol[v].second == ty;
  }
  bcol[v] = mp(bccnt, ty);
  for (int b : bes[v])
    if (!dfs2(b, !ty)) return false;
  return true;
}

int n, m;
vector<pii> badvl;
bool solve() {
  col = vi(n, -1);
  ccnt = 0;
  forn (i, n)
    if (col[i] < 0) {
      dfs1(i);
      ccnt++;
    }

  bes = vvi(ccnt);
  for (pii x : badvl) {
    int a = col[x.first];
    int b = col[x.second];
    assert(0 <= a && a < sz(bes));
    assert(0 <= b && b < sz(bes));
    bes[a].pb(b);
    bes[b].pb(a);
  }
  bcol = vector<pii>(ccnt, mp(-1, -1));
  bccnt = 0;
  forn (i, ccnt)
    if (bcol[i].first < 0) {
      if (!dfs2(i, 0)) return false;
      bccnt++;
    }
  assert(bccnt >= 1);
  printf("%d\n", mpow(2, bccnt - 1));
  return true;
}

int main() {
  #ifdef DEBUG
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
  #endif

  facs[0] = 1;
  for (int i = 1; i <= MAXN; i++)
    facs[i] = mmul(facs[i - 1], i);
  ifacs[MAXN] = mpow(facs[MAXN], MOD - 2);
  for (int i = MAXN; i > 0; i--)
    ifacs[i - 1] = mmul(ifacs[i], i);

  for (int i = 0; i <= MAXN; i++)
    assert(mmul(facs[i], ifacs[i]) == 1);

  while (scanf("%d%d", &n, &m) >= 1) {
    es = vvi(n);
    badvl.clear();
    forn (i, m) {
      int a, b, t;
      scanf("%d%d%d", &a, &b, &t), a--, b--;
      if (t == 1) {
        es[a].pb(b);
        es[b].pb(a);
      } else {
        badvl.pb(mp(a, b));
      }
    }
    if (!solve()) {
      printf("0\n");
    }
  }
  return 0;
}