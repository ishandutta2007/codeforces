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

int n;
vvi chi;
vi ss, hty;

void dfs1(int v) {
  ss[v] = chi[v].empty() ? 1 : 0;
  for (int b : chi[v]) {
    chi[b].erase(find(chi[b].begin(), chi[b].end(), v));
    hty[b] = !hty[v];
    dfs1(b);
    ss[v] += ss[b];
  }
}

vi mina, maxa;
void calc(int v) {
  for (int b : chi[v])
    calc(b);

  if (chi[v].empty()) {
    mina[v] = maxa[v] = 1;
    return;
  }

  if (hty[v] == 0) { // player maximizes
    { // we maximize too
      int badCnt = INF;
      for (int b : chi[v])
        badCnt = min(badCnt, ss[b] - maxa[b]);
      maxa[v] = ss[v] - badCnt;
    }

    { // we minimize
      int badCnt = 0;
      for (int b : chi[v])
        badCnt += mina[b] - 1;
      mina[v] = badCnt + sz(chi[v]);
    }
  } else { // player minimizes
    { // we maximize
      int badCnt = 0;
      for (int b : chi[v])
        badCnt += ss[b] - maxa[b];
      maxa[v] = ss[v] - badCnt - (sz(chi[v]) - 1);
    }

    { // we minimize too
      int badCnt = INF;
      for (int b : chi[v])
        badCnt = min(badCnt, mina[b] - 1);
      mina[v] = badCnt + 1;
    }
  }
//  eprintf("v=%d; maxa=%d, mina=%d\n", v + 1, maxa[v], mina[v]);
}

int main() {
  #ifdef DEBUG
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif

  while (scanf("%d", &n) == 1) {
    chi = vvi(n);
    forn (i, n - 1) {
      int a, b;
      scanf("%d%d", &a, &b), a--, b--;
      chi[a].pb(b);
      chi[b].pb(a);
    }
    ss = vi(n, 0);
    hty = vi(n, 0);
    dfs1(0);

    mina = vi(n, INF);
    maxa = vi(n, -1);
    calc(0);
    printf("%d %d\n", maxa[0], mina[0]);
  }

  return 0;
}