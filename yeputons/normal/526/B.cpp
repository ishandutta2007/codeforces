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

int n;
vector<vector<pii>> chi;

pii calc(int v) {
  int maxd = 0;
  int ans = 0;
  int pcnt = 0;
  for (pii e : chi[v]) {
    pii sub = calc(e.first);
    sub.first += e.second;
    ans += sub.second;

    if (maxd < sub.first) {
      ans += pcnt * (sub.first - maxd);
      maxd = sub.first;
    } else if (maxd > sub.first) {
      ans += maxd - sub.first;
    }
    pcnt++;
    assert(maxd >= sub.first);
  }
  return mp(maxd, ans);
}

int main() {
  #ifdef DEBUG
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif

  int k;
  while (scanf("%d", &k) == 1) {
    n = (2 << k) - 1;
    chi = vector<vector<pii>>(n);
    for (int i = 2; i < (2 << k); i++) {
      int x;
      scanf("%d", &x);
      int par = i / 2;
      chi[par - 1].pb(mp(i - 1, x));
    }
    printf("%d\n", calc(0).second);
  }

  return 0;
}