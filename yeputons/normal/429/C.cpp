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

const int MCNT = 180000;
const int MAXS = 11;
const int MAXN = 24;

vi ss;
bool was[MCNT][MAXN + 1];
bool go(int roots, int lcnt) {
  if (was[roots][lcnt]) return false;
  was[roots][lcnt] = true;

  int states[sz(ss)];
  {
    int x = roots;
    for (int i = 0; i < sz(ss); i++)
      states[i] = x % 3, x /= 3;
  }

/*  eprintf("lcnt=%d: ", lcnt);
  for (int i = 0; i < sz(ss); i++)
    eprintf(" %d", states[i]);
  eprintf("\n");*/
  for (int id = 0; id < sz(ss); id++) if (!states[id]) {
    int fr = 0;
    for (int i2 = 0; i2 < id; i2++) if (states[i2] == 1)
      fr |= 1 << i2;

    for (int m = fr;; m = (m - 1) & fr) {
      int reml = ss[id] - 1;
      int mydeg = 0;
      for (int i2 = 0; i2 < id; i2++)
        if (m & (1 << i2)) {
          reml -= ss[i2];
          mydeg++;
        }

      if (reml >= 0 && reml <= lcnt) {
        mydeg += reml;
        if (mydeg != 1) {
          int nroots = 0;
          for (int i2 = sz(ss) - 1; i2 >= 0; i2--) {
            int cst = states[i2];
            if (i2 == id) cst = 1;
            if (m & (1 << i2)) cst = 2;
            nroots = nroots * 3 + cst;
          }
          if (go(nroots, lcnt - reml)) return true;
        }
      }
      if (!m) break;
    }
    return false;
  }

  int rcnt = 0;
  for (int i = 0; i < sz(ss); i++) if (states[i] == 1)
    rcnt++;
  return rcnt == 1 && lcnt == 0;
}

int main() {
  #ifdef DEBUG
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif

  int n;
  while (scanf("%d", &n) == 1) {
    ss = vi(n);
    int lcnt = 0;
    for (int &x : ss) scanf("%d", &x), lcnt += x == 1;
    sort(ss.begin(), ss.end());
    if (lcnt <= n - lcnt || ss.back() != n) {
      printf("NO\n");
      continue;
    }
    if (n == 1) {
      printf("YES\n");
      continue;
    }

    while (ss[0] == 1) ss.erase(ss.begin());
    assert(sz(ss) <= MAXS);
    memset(was, 0, sizeof was);

    if (go(0, lcnt)) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }

  return 0;
}