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

const int MOD = int(1e9 + 7);
void madd(int &a, int b) { if ((a += b) >= MOD) a -= MOD; }
int mmul(int a, int b) { return ll(a) * b % MOD; }

vvi es;
vi cols;

pii dfs(int v) {
  int cur[2];
  cur[0] = !cols[v];
  cur[1] =  cols[v];
  for (int b : es[v]) {
    int ne[2];
    tie(ne[0], ne[1]) = dfs(b);

    int ncur[2] = {};
    // no cuts
    forn (x, 2)
    forn (y, 2) if (x + y < 2) {
      madd(ncur[x + y], mmul(cur[x], ne[y]));
    }

    // cut
    forn (x, 2) {
      madd(ncur[x], mmul(cur[x], ne[1]));
    }
    memcpy(cur, ncur, sizeof cur);
  }
  return mp(cur[0], cur[1]);
}

int main() {
  #ifdef DEBUG
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif

  int n;
  while (scanf("%d", &n) == 1) {
    es = vvi(n);
    for (int i = 1; i < n; i++) {
      int p;
      scanf("%d", &p);
      es[p].pb(i);
    }
    cols = vi(n);
    for (int &x : cols) scanf("%d", &x);

    pii res = dfs(0);
    printf("%d\n", res.second);
  }

  return 0;
}