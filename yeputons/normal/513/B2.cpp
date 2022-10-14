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

ll calcSufs(const vi &ord, int len) {
  assert(len > 0);

  int n = sz(ord);
  int mid = find(ord.begin(), ord.end(), n) - ord.begin();
  if (mid == n) {
    for (int i = 0; i + 1 < len; i++)
      if (ord[i] > ord[i + 1]) return 0;
    return 1LL << (n - ord[len - 1] - 1);
  }
  for (int i = 0; i < mid; i++)
    if (ord[i] > ord[i + 1]) return 0;
  for (int i = mid; i + 1 < len; i++)
    if (ord[i] < ord[i + 1]) return 0;

  vb rem(n + 1, true);
  rem[0] = false;
  forn (i, len) rem[ord[i]] = false;

  int las = ord[len - 1];
  for (int i = n; i >= 1; i--) if (rem[i]) {
    if (las < i) return 0;
    las = i;
  }
  return 1;
}

int main() {
  #ifdef DEBUG
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif

  int n; ll k;
  while (scanf("%d%I64d", &n, &k) == 2) {
    k--;
    vi ord(n, -1);
    vb was(n + 1, false);

//    assert(calcSufs({1, 2, 3, 4, 5, 8, 7, -1}, 7) == 1);
    forn (i, n) {
      for (int v = 1; v <= n; v++) if (!was[v]) {
        ord[i] = v;
        ll ccnt = calcSufs(ord, i + 1);
        if (ccnt <= k) {
          k -= ccnt;
        } else {
//          eprintf("i=%d, v=%d\n", i, v);
          was[v] = true;
          break;
        }
        ord[i] = -1;
      }
      assert(ord[i] >= 0);
    }
    assert(k == 0);
    forn (i, n)
      printf("%d%c", ord[i], "\n "[i + 1 < n]);
//    fflush(stdout);
  }

  return 0;
}