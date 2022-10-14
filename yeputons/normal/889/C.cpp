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

const int MOD = int(1e9) + 7;
void madd(int &a, int b) { if ((a += b) >= MOD) a -= MOD; }
int mmul(int a, int b) { return ll(a) * b % MOD; }
int mpow(int a, int b) {
  int res = 1;
  for (; b; b >>= 1, a = mmul(a, a))
    if (b & 1) res = mmul(res, a);
  return res;
}
int minv(int a) {
  assert(a);
  int b = mpow(a, MOD - 2);
  assert(mmul(a, b) == 1);
  return b;
}

const int MAXN = int(1e6) + 10;
int facs[MAXN + 1], ifacs[MAXN + 1];

int calcA(int n, int k) {
  assert(0 <= k && k <= n && n <= MAXN);
  return mmul(facs[n], ifacs[n - k]);
}

int main() {
  #ifdef DEBUG
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif

  {
    facs[0] = 1;
    for (int i = 1; i <= MAXN; i++) {
      facs[i] = mmul(facs[i - 1], i);
    }
    assert(facs[5] == 120);
    ifacs[MAXN] = minv(facs[MAXN]);
    for (int i = MAXN; i >= 1; i--) {
      ifacs[i - 1] = mmul(ifacs[i], i);
    }
    for (int i = 0; i <= MAXN; i++) {
      assert(mmul(facs[i], ifacs[i]) == 1);
    }
    assert(ifacs[0] == 1);
  }

  int maxn, k;
  while (scanf("%d%d", &maxn, &k) == 2) {
//    eprintf("maxn=%d, k=%d\n", maxn, k);
    vi f0(maxn + 1), f0b(maxn + 1);
    f0[0] = 1;
    f0[1] = 1; f0b[1] = mmul(f0[1], ifacs[0]);

    int ans = facs[maxn];
    { // pos == 0
      int cans = f0[0];
      cans = mmul(cans, facs[maxn - 1]);
      madd(ans, MOD - cans);
    }

    vi f0bs(maxn + 2);
    f0bs[0] = f0b[0];
    madd(f0bs[1] = f0bs[0], f0b[1]);
    for (int pos = 1; pos < maxn; pos++) {
      madd(f0[pos + 1], f0bs[pos]);
      madd(f0[pos + 1], MOD - f0bs[pos - min(pos, k)]);
      f0[pos + 1] = mmul(f0[pos + 1], facs[pos - 1]);
      f0b[pos + 1] = mmul(f0[pos + 1], ifacs[pos]);
      madd(f0bs[pos + 1] = f0bs[pos], f0b[pos + 1]);

      int cans = f0[pos + 1];
      cans = mmul(cans, mmul(facs[maxn - 1], ifacs[pos]));
      madd(ans, MOD - cans);
    }
    printf("%d\n", ans);
  }

  return 0;
}