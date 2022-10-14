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

vvi es;
vi dyn, rdyn;

void calc(int v) {
  for (int x : es[v]) {
    es[x].erase(find(es[x].begin(), es[x].end(), v));
    calc(x);
  }

  int min1 = 0, min2 = 0;
  for (int x : es[v]) {
    int cur = rdyn[x] - 1 - dyn[x];
    if (cur <= min1) {
      min2 = min1;
      min1 = cur;
    } else if (cur <= min2) {
      min2 = cur;
    }
  }

  int sum = 0;
  for (int x : es[v])
    sum += dyn[x];
  rdyn[v] = 1 + sum + min1;
  dyn[v] = 1 + sum + min1 + min2;
//  eprintf("dyn[%d]=%d; rdyn=%d (sum=%d, min1=%d, min2=%d)\n", v + 1, dyn[v], rdyn[v], sum, min1, min2);
}

pii getFar(int v, int par = -1) {
  pii res(0, v);
  for (int x : es[v]) if (x != par) {
    pii sub = getFar(x, v);
    sub.first++;
    res = max(res, sub);
  }
  return res;
}

int main() {
  #ifdef DEBUG
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif

  int n; ll x, y;
  while (scanf("%d%I64d%I64d", &n, &x, &y) == 3) {
    es = vvi(n);
    forn (i, n - 1) {
      int a, b;
      scanf("%d%d", &a, &b), a--, b--;
      es[a].pb(b);
      es[b].pb(a);
    }

    if (x <= y) {
      dyn = vi(n);
      rdyn = vi(n);
      calc(0);
      int jumps = dyn[0] - 1;
      printf("%I64d\n", (n - 1 - jumps) * x + jumps * y);
    } else {
      int a = getFar(0).second, b;
      int di;
      tie(di, b) = getFar(a);
//      eprintf("%d..%d: %d\n", a, b, di);
      if (di <= 2) {
        printf("%I64d\n", x + (n - 2) * y);
      } else {
        printf("%I64d\n", (n - 1) * y);
      }
    }
  }

  return 0;
}