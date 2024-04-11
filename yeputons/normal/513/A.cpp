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

  int n, m, k1, k2;
  while (scanf("%d%d%d%d", &n, &m, &k1, &k2) == 4) {
    int nm = max(n, m);
    vector<vvb> d(nm + 1, vvb(nm + 1, vb(2, false)));
    for (int cs = 0; cs <= 2 * nm; cs++)
    for (int v1 = 0; v1 <= nm; v1++) {
      int v2 = cs - v1;
      if (v2 < 0 || v2 > nm) continue;
      for (int tu = 0; tu < 2; tu++) {
        int maxv = tu == 0 ? k1 : k2;
        bool ok = false;
        for (int c = 1; c <= v1 && c <= maxv; c++) {
          if (!d[v2][v1 - c][!tu]) {
            ok = true;
            break;
          }
        }
        d[v1][v2][tu] = ok;
      }
    }
    printf("%s\n", d[n][m][0] ? "First" : "Second");
  }

  return 0;
}