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

const int MAXMSZ = 101;

int msz;
struct Mat {
  ld dat[MAXMSZ][MAXMSZ];
  Mat(ld x = 0) {
    memset(dat, 0, sizeof dat);
    forn (i, msz) dat[i][i] = x;
  }
        ld* operator[](int y)       { return dat[y]; }
  const ld* operator[](int y) const { return dat[y]; }
};
Mat operator*(const Mat &a, const Mat &b) {
  Mat res;
  forn (i, msz)
  forn (j, msz)
  forn (k, msz)
    res[i][j] += a[i][k] * b[k][j];
  return res;
}

int rev(int l, int r, int i) {
  assert(0 <= l && l <= r);
  if (i < l || r < i) return i;
  i -= l;
  i = (r - l + 1) - i - 1;
  i += l;
  return i;
}

int main() {
  #ifdef DEBUG
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif

  int n, k;
  while (scanf("%d%d", &n, &k) == 2) {
    vi ord(n);
    forn (i, n) scanf("%d", &ord[i]);

    vector<vector<ld>> d(n, vector<ld>(n, 0));

    int totSegs = n * (n + 1) / 2;
    ld prob = 1.0 / totSegs;
    forn (step, k) {
      vector<vector<ld>> nd(n, vector<ld>(n, 0));
      for (int i = 0; i < n; i++)
      for (int j = i + 1; j < n; j++) {
        for (int l = 0; l < n; l++)
        for (int r = l; r < n; r++) {
          int ni = rev(l, r, i), nj = rev(l, r, j);
          if (ni < nj) {
            nd[i][j] += prob * d[ni][nj];
          } else {
//            eprintf("%d %d: prob=%.2lf\n", i, j, (double)prob);
            nd[i][j] += prob * (1 - d[nj][ni]);
          }
        }
      }
      d = nd;
    }

    ld ans = 0;
    for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++) {
      if (ord[i] < ord[j])
        ans += d[i][j];
      else
        ans += 1 - d[i][j];
    }
    printf("%.18lf\n", (double)ans);
  }  

  return 0;
}