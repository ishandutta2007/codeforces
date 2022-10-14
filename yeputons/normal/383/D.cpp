#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <numeric>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <list>
#include <map>
#include <set>

using namespace std;

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())

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

const int MOD = int(1e9 + 7);
void madd(int &a, int b) { if ((a += b) >= MOD) a -= MOD; }
int mmul(int a, int b) { return ll(a) * b % MOD; }

vi as;

int calc(int l, int r) {
  if (l == r) return 0;
  int m = (l + r) / 2;
  int res = 0;
  madd(res, calc(l, m));
  madd(res, calc(m + 1, r));

  int suml = 0, sumr = 0;
  for (int i = l; i <= r; i++)
    if (i <= m) suml += as[i];
    else sumr += as[i];

  vi canl(2 * suml + 1), canr(2 * sumr + 1);
  #define step(xxx) \
      for (int i2 = 0; i2 < sz(cur); i2++) { \
        ncur[i2] = 0; \
        if (i2 >= as[i]) madd(ncur[i2], cur[i2 - as[i]]); \
        if (i2 + as[i] < sz(cur)) madd(ncur[i2], cur[i2 + as[i]]); \
      } \
      cur.swap(ncur); \
      for (int i2 = 0; i2 < sz(cur); i2++) \
        madd(xxx[i2], cur[i2]);
  {
    vi cur(sz(canl)), ncur(sz(canl));
    cur[sz(canl) / 2] = 1;
    for (int i = m; i >= l; i--) {
      step(canl)
    }
  }
  {
    vi cur(sz(canr), 0), ncur(sz(canr));
    cur[sz(canr) / 2] = 1;
    for (int i = m + 1; i <= r; i++) {
      step(canr)
    }
  }

//  res = 0;
  for (int i = 0; i < sz(canl); i++) {
    int x = i - sz(canl) / 2;
    int y = -x;
    int i2 = y + sz(canr) / 2;
    if (0 <= i2 && i2 < sz(canr)) {
//      eprintf("x=%d (%d), y=%d (%d)\n", x, canl[i], y, canr[i2]);
      madd(res, mmul(canl[i], canr[i2]));
    }
  }
//  eprintf("calc(%d..%d)=%d\n", l, r, res);
  return res;
}

int main() {
  #ifdef DEBUG
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
  #endif

  int n;
  while (scanf("%d", &n) >= 1) {
    as = vi(n);
    for (int i = 0; i < n; i++)
      scanf("%d", &as[i]);
    printf("%d\n", calc(0, n - 1));
  }
  return 0;
}