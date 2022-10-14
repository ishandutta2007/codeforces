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
#define eb emplace_back
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

const int MAXV = int(2e5);

int solve(vi as) {
  int n = sz(as);
  vi last(MAXV + 1, -1);
  forn (i, n) last[as[i]] = i;

  eprintf("===== n=%d =====\n", n);
  int ans = 0;
  for (int l = 0; l < n;) {
    int r = l;
    int bord = last[as[l]];
    while (r < bord) {
      bord = max(bord, last[as[++r]]);
    }
    map<int, int> cnts;
    for (int i = l; i <= r; i++)
      cnts[as[i]]++;
    int maxCnt = 0;
    for (auto [val, cnt] : cnts)
      maxCnt = max(maxCnt, cnt);
    eprintf("%d..%d; maxCnt=%d\n", l, r, maxCnt);
    ans += (r - l + 1) - maxCnt;
    l = r + 1;
  }
  return ans;
}

int main() {
  #ifdef DEBUG
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif

  int n, q;
  while (scanf("%d%d", &n, &q) == 2) {
    vi as(n);
    forn (i, n)
      scanf("%d", &as[i]);

    printf("%d\n", solve(as));
    while (q --> 0) {
      int pos, x;
      scanf("%d%d", &pos, &x), pos--;
      assert(0 <= pos && pos < n);
      as[pos] = x;
      printf("%d\n", solve(as));
    }
  }

  return 0;
}