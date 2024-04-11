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

vi all1, all2;
vector<pii> ces;

vb was1, was2;
vvi es, rves;

void dfs1(int v) {
  if (was1[v]) return;
  was1[v] = true;
  all1.pb(v);
  for (int x : es[v]) dfs1(x), ces.pb(mp(v, x));
  for (int x : rves[v]) dfs1(x);
}

void dfs2(int v) {
  if (was2[v]) return;
  was2[v] = true;
  for (int x : es[v]) dfs2(x);
  all2.pb(v);
}

int main() {
  #ifdef DEBUG
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif

  int n, m;
  while (scanf("%d%d", &n, &m) == 2) {
    es = vvi(n);
    rves = vvi(n);
    forn (i, m) {
      int a, b;
      scanf("%d%d", &a, &b), a--, b--;
      es[a].pb(b);
      rves[b].pb(a);
    }
    was1 = vb(n, false);
    was2 = vb(n, false);

    int ans = 0;
    int bigcyc = 0;
    forn (i, n) if (!was1[i]) {
      all1.clear();
      all2.clear();
      ces.clear();
      dfs1(i);
      if (ces.empty()) continue;

      for (int x : all1) if (!was2[x]) {
        dfs2(x);
      }

      reverse(all2.begin(), all2.end());
//      for (int x : all2)
//        eprintf("x=%d\n", x + 1);

      map<int, int> ids;
      forn (i2, sz(all2)) ids[all2[i2]] = i2;
      bool ncyc = true;
      for (pii e : ces) {
        int a = ids[e.first];
        int b = ids[e.second];
//        eprintf("%d %d\n", a, b);
        ncyc = ncyc && a <= b;
      }
      if (ncyc) {
        ans += sz(all2) - 1;
      } else {
        bigcyc += sz(all2);
      }
    }
    printf("%d\n", ans + bigcyc);
//    break;
  }

  return 0;
}