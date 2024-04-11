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

int calc(const vi &ord) {
  const int n = sz(ord);
  int ans = 0;
  forn (i, n) {
    int mv = inf;
    for (int j = i; j < n; j++) {
      mv = min(mv, ord[j]);
      ans += mv;
    }
  }
  return ans;
}

int main() {
  #ifdef DEBUG
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif

  int n, k;
  while (scanf("%d%d", &n, &k) == 2) {
    vi ord(n);
    forn (i, n) ord[i] = i + 1;
    int bf = 0;
    do {
      int cf = calc(ord);
      bf = max(bf, cf);
    } while (next_permutation(ord.begin(), ord.end()));

    do {
      int cf = calc(ord);
      if (cf == bf) {
        if (!--k) {
          forn (i, n)
            printf("%d%c", ord[i], "\n "[i + 1 < n]);
          goto end;
        }
      }
    } while (next_permutation(ord.begin(), ord.end()));
    assert(false);
    end:;
  }

  return 0;
}