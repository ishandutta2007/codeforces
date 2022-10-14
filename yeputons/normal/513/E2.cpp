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

void relax(ll &a, ll b) { a = max(a, b); }

const int MAXN = int(3e4) + 105;
const int MAXK = 205;
int n;
ll dyn[MAXN + 1][MAXK + 1][2];
ll psums[MAXN + 1];
int as[MAXN];

const ll INFLL = ll(1e18);

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
      psums[l + 1] = psums[l] + as[l];
    }

    memset(dyn, 0xC0, sizeof dyn);
    for (int ck = 1; ck <= 1; ck++) {
      ll masuf = psums[n], misuf = psums[n];
      for (int l = n - 1; l >= 0; l--) {
        dyn[l][ck][0] = max(dyn[l + 1][ck][0], masuf - psums[l]);
        dyn[l][ck][1] = max(dyn[l + 1][ck][1], psums[l] - misuf);
        masuf = max(masuf, psums[l]);
        misuf = min(misuf, psums[l]);
      }
    }

    for (int ck = 2; ck <= k; ck++) {
      ll t0a = -INFLL;
      ll t0b = -INFLL;
      ll t1a = -INFLL;
      ll t1b = -INFLL;
      for (int l = n - 1; l >= 0; l--) {
//        for (int r = l; r < n; r++) {
        {
          int r = l;
          relax(t0a, 2 * psums[r + 1] + dyn[r + 1][ck - 1][1]);
          relax(t0b,                    dyn[r + 1][ck - 1][0]);
          relax(t1a,                    dyn[r + 1][ck - 1][1]);
          relax(t1b,-2 * psums[r + 1] + dyn[r + 1][ck - 1][0]);
        }

        relax(dyn[l][ck][0], t0a - psums[l]);
        relax(dyn[l][ck][0], t0b + psums[l]);
        relax(dyn[l][ck][1], t1a - psums[l]);
        relax(dyn[l][ck][1], t1b + psums[l]);
        dyn[l][ck][0] -= psums[l];
        dyn[l][ck][1] += psums[l];
        forn (t, 2) {
          relax(dyn[l][ck][t], dyn[l + 1][ck][t]);
        }
      }
    }

    ll ans = -INFLL;
    ll cans0 = -INFLL, cans1 = -INFLL;
    for (int l = n - 1; l >= 0; l--) {
      {
        int r = l;
        relax(cans0,  psums[r + 1] + dyn[r + 1][k - 1][1]);
        relax(cans1, -psums[r + 1] + dyn[r + 1][k - 1][0]);
      }
      relax(ans, cans0 - psums[l]);
      relax(ans, cans1 + psums[l]);
    }
    printf("%I64d\n", ans);
  }

  return 0;
}