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

const int MAXN = int(1e6) + 100;
char s[MAXN];
int z[MAXN];
int n;

void calcz() {
  int r = 0, ri = 0;
  for (int i = 1; i < n; i++) {
    int k = 0;
    if (i <= r) {
      k = min(r - i + 1, z[i - ri]);
    }
    while (s[k] == s[i + k]) k++;
    z[i] = k;
    if (i + k - 1 > r) {
      r = i + k - 1;
      ri = i;
    }

    #if defined(DEBUG)
//    #if 0
    int rk = 0;
    while (s[rk] == s[i + rk]) rk++;
    assert(k == rk);
    #endif
  }
}

int main() {
  #ifdef DEBUG
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif

  int k;
  while (scanf("%*d%d%s", &k, s) == 2) {
    n = strlen(s);
    calcz();

    vi ch(n + 1, 0);
    for (int lab = 1; lab * k <= n; lab++) {
      if (z[lab] < lab * (k - 1)) continue;
//      eprintf("lab=%d\n", lab);
      ch[lab * k - 1]++;
      int maxv = min(z[lab * k], lab);
//      eprintf("maxv=%d\n", maxv);
      ch[min(n, lab * k + maxv)]--;
    }
    int bal = 0;
    static char ans[MAXN + 1];
    forn (i, n) {
      bal += ch[i];
      ans[i] = "01"[!!bal];
    }
    ans[n] = 0;
    puts(ans);
  }

  return 0;
}