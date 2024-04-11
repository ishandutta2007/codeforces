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

const int MOD = int(1e9 + 7);
void madd(int &a, int b) { if ((a += b) >= MOD) a -= MOD; }
int mmul(int a, int b) { return ll(a) * b % MOD; }

const int MAXN = int(2e5) + 100;
const int MAXK = 110;
int cs[MAXN + 1][MAXK + 1];

class Solver {
  vvi dat;
  public:
  Solver(int n) : dat(MAXK + 1, vi(n, 0)) {}
  void add(int x, int y, int k) {
    madd(dat.at(y).at(x), k);
  }
  vi solve() {
    for (int y = MAXK - 1; y >= 0; y--) {
      for (int x = 0; x < sz(dat[y]); x++) {
        if (x > 0) madd(dat[y][x], dat[y][x - 1]);
        madd(dat[y][x], dat[y + 1][x]);
      }
    }
    return dat[0];
  }
};

int main() {
  #ifdef DEBUG
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif

  for (int n = 0; n <= MAXN; n++) {
    cs[n][0] = 1;
    if (n <= MAXK) cs[n][n] = 1;
    for (int k = 1; k < n && k <= MAXK; k++) {
      cs[n][k] = cs[n - 1][k - 1];
      madd(cs[n][k], cs[n - 1][k]);
    }
  }

  int n, m;
  while (scanf("%d%d", &n, &m) == 2) {
    vi as(n);
    for (int &x : as) scanf("%d", &x);

    Solver s(n + 1);
    for (int i = 0; i < m; i++) {
      int l, r, k;
      scanf("%d%d%d", &l, &r, &k), l--, r--;
//      eprintf("%d %d %d\n", l, r, k);
      s.add(l, k, +1);
      for (int k2 = 0; k2 <= k; k2++) {
        s.add(r + 1, k2, MOD - cs[r - l + k - k2][k - k2]);
      }
    }
    vi res = s.solve();
//    for (int i = 0; i < n; i++0
    assert(res[n] == 0);
    for (int i = 0; i < n; i++) {
      madd(as[i], res[i]);
      printf("%d%c", as[i], "\n "[i + 1 < n]);
    }
  }

  return 0;
}