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

vvi es;
void dfs(int v) {
  for (int x : es[v]) {
    es[x].erase(find(es[x].begin(), es[x].end(), v));
    dfs(x);
  }
}

vi vals;
vi res;
void dfs2(int v, int fl0, int fl1) {
  vals[v] ^= fl0;
  if (vals[v]) {
    res.pb(v);
    vals[v] ^= 1;
    fl0 ^= 1;
  }
  for (int x : es[v]) {
    dfs2(x, fl1, fl0);
  }
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
      int a, b;
      scanf("%d%d", &a, &b), a--, b--;
      es[a].pb(b);
      es[b].pb(a);
    }
    dfs(0);
    vals = vi(n);
    for (int i = 0; i < n; i++)
      scanf("%d", &vals[i]);
    for (int i = 0; i < n; i++) {
      int nv;
      scanf("%d", &nv);
      vals[i] ^= nv;
    }

    res.clear();
    dfs2(0, 0, 0);
    printf("%d\n", sz(res));
    for (int i = 0; i < sz(res); i++)
      printf("%d\n", res[i] + 1);
  }

  return 0;
}