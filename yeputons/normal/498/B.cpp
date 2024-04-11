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

int main() {
  #ifdef DEBUG
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif

  int n, maxt;
  while (scanf("%d%d", &n, &maxt) == 2) {
    vector<ld> ps(n);
    vi ts(n);
    forn (i, n) {
      int p;
      scanf("%d%d", &p, &ts[i]);
      ps[i] = p / 100.0;
    }

    vector<ld> cdyn(maxt + 1, 0);
    cdyn[maxt] = 1;

    vector<ld> ndyn(maxt + 1, 0);
    vector<ld> toadd(maxt + 2, 0);

    ld ans = 0;
    forn (id, n) {
      fill(ndyn.begin(), ndyn.end(), 0);
      fill(toadd.begin(), toadd.end(), 0);

/*      ld toCur = 1;
      for (int was = 1; was < ts[id]; was++) {
        ld cprob = toCur * ps[id];

        for (int olt = was; olt <= maxt; olt++) {
          ndyn[olt - was] += cprob * cdyn[olt];
        }

        toCur *= 1 - ps[id];
      }*/
      ld toCur = 1;
      for (int was = 1; was < ts[id]; was++) toCur *= 1 - ps[id];
      for (int olt = 1; olt <= maxt; olt++) {
        toadd[olt - 1] += ps[id] * cdyn[olt];
        if (olt >= ts[id]) {
          toadd[olt - ts[id]] -= toCur * ps[id] * cdyn[olt];
        }
      }
      
      for (int i = maxt; i >= 0; i--) {
        ndyn[i] = toadd[i];
        if (i < maxt) ndyn[i] += ndyn[i + 1] * (1 - ps[id]);
      }
      for (int olt = ts[id]; olt <= maxt; olt++) {
        ndyn[olt - ts[id]] += toCur * cdyn[olt];
      }

      {
        ld csum = 0;
        for (ld x : ndyn) csum += x;
        ans += csum;
      }
      cdyn.swap(ndyn);
    }
    printf("%.18f\n", (double)ans);
  }

  return 0;
}