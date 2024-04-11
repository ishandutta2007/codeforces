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

int main() {
  #ifdef DEBUG
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif

  int n;
  while (scanf("%d", &n) == 1) {
    vvi add(n);
    forn (i, n) {
      int x;
      scanf("%d", &x);
      int mpos = x + i;
      add[min(n - 1, mpos)].pb(mpos);
    }
    priority_queue<int> q;
    vi res(n, -1);
    bool ok = true;
    for (int i = n - 1; i >= 0; i--) {
      for (int x : add[i]) q.push(x);
      if (q.empty()) {
        ok = false;
        break;
      }
      res[i] = q.top() - i;
      q.pop();
    }
    for (int i = 0; i + 1 < n; i++)
      ok &= res[i] <= res[i + 1];
    if (!ok) {
      printf(":(\n");
    } else {
      forn (i, n)
        printf("%d%c", res[i], "\n "[i + 1 < n]);
    }
  }

  return 0;
}