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

const int h = 7;

struct Mat {
  static const int n = 1 << h;
  int dat[n][n];

  Mat(int x = 0) {
    memset(dat, 0, sizeof dat);
    forn (i, n) dat[i][i] = x;
  }
        int *operator[](int y)       { return dat[y]; }
  const int *operator[](int y) const { return dat[y]; }

  friend Mat operator*(const Mat &a, const Mat &b) {
    const ll MOD2 = ll(MOD) * MOD;
    Mat res;
    forn (i, n)
    forn (j, n) {
      ll cur = 0;
      forn (k, n) {
        cur += ll(a[i][k]) * b[k][j];
        if (cur >= MOD2) cur -= MOD2;
      }
      res[i][j] = cur % MOD;
    }
    return res;
  }
};

Mat mpow(Mat a, int b) {
  Mat res = 1;
  for (; b; b >>= 1, a = a * a)
    if (b & 1) res = res * a;
  return res;
}

int main() {
  #ifdef DEBUG
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif

  vi ws(h + 1);
  while (scanf("%d", &ws[1]) == 1) {
    for (int y = 2; y <= h; y++)
      scanf("%d", &ws[y]);

    Mat ans = 1;
    int py = 0;
    for (int y = 1; y <= h; y++) if (ws[y]) {
      // first step
      for (int x = 0; x < 2; x++) {
        Mat cur;
        int prevMsk = x ? (1 << y) : (1 << py);
        forn (old, prevMsk) {
          forn (vmsk, prevMsk) if (!(old & vmsk)) {
            forn (hmsk, 1 << (y - 1)) {
              int hasBottom = (hmsk << 1) | 1;
              int hasMiddle = vmsk;
              if (x == 0) hasMiddle |= ((1 << (y - py)) - 1) << py;
              int hasTop = hmsk | (1 << (y - 1));
              int ne = hasBottom & hasMiddle & hasTop;
              madd(cur[old][ne], 1);
            }
          }
        }

        int need = 1;
        if (x == 1) need = ws[y] - 1;
        ans = ans * mpow(cur, need);
      }
      py = y;
    }
    printf("%d\n", ans[0][0]);
  }

  return 0;
}