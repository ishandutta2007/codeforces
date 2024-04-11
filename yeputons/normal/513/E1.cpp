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

void relax(int &a, int b) { a = max(a, b); }

const int MAXN = 400;
const int MAXK = 50;
int n;
int dyn[MAXN + 1][MAXK + 1][2];

int sums[MAXN][MAXN];
int as[MAXN];

int main() {
  #ifdef DEBUG
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif

  int k;
  while (scanf("%d%d", &n, &k) == 2) {
    assert(k >= 2);
    forn (i, n) scanf("%d", &as[i]);

    for (int l = 0; l < n; l++) {
      int csum = 0;
      for (int r = l; r < n; r++) {
        sums[l][r] = csum += as[r];
      }
    }

    memset(dyn, 0xC0, sizeof dyn);
    for (int ck = 1; ck <= 1; ck++) {
      for (int l = n - 1; l >= 0; l--) {
        for (int r = l; r < n; r++) {
          relax(dyn[l][ck][0],  sums[l][r]);
          relax(dyn[l][ck][1], -sums[l][r]);
        }
        forn (t, 2)
          relax(dyn[l][ck][t], dyn[l + 1][ck][t]);
      }
    }

    for (int ck = 2; ck <= k; ck++) {
      for (int l = n - 1; l >= 0; l--) {
        for (int r = l; r < n; r++) {
          int tail = -inf;
          relax(tail,  sums[l][r] + dyn[r + 1][ck - 1][1]);
          relax(tail, -sums[l][r] + dyn[r + 1][ck - 1][0]);

          relax(dyn[l][ck][0],  sums[l][r] + tail);
          relax(dyn[l][ck][1], -sums[l][r] + tail);
        }
        forn (t, 2)
          relax(dyn[l][ck][t], dyn[l + 1][ck][t]);
      }
    }

    int ans = -inf;
    for (int l = 0; l < n; l++)
    for (int r = l; r < n; r++) {
      ans = max(ans,  sums[l][r] + dyn[r + 1][k - 1][1]);
      ans = max(ans, -sums[l][r] + dyn[r + 1][k - 1][0]);
    }
    printf("%d\n", ans);
  }

  return 0;
}