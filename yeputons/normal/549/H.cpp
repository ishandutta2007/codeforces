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

typedef unsigned long long ull;

int main() {
  #ifdef DEBUG
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif

  ll a, b, c, d;
  while (scanf(LLD LLD LLD LLD, &a, &b, &c, &d) == 4) {
    if (a * d == b * c) {
      printf("0\n");
      continue;
    }
    ld ans = 1e100;
    for (int ka = -1; ka <= 1; ka += 2)
    for (int kb = -1; kb <= 1; kb += 2)
    for (int kc = -1; kc <= 1; kc += 2)
    for (int kd = -1; kd <= 1; kd += 2) {
      ll A = ka * kd - kb * kc; // <= 2
      ll B = a * kd + d * ka - b * kc - c * kb; // <= 4*10^9
      ll C = a * d - b * c; // <= 2 * 10^18
      assert(C);

      if (!A) {
        if (!B) {
          continue;
        } else {
          ans = min(ans, fabsl(-ld(C) / B));
          continue;
        }
      }

      double D2 = ld(B) * ld(B) - ld(4) * ld(A) * ld(C);
      double D = 0;
      if (fabs(D2) >= 1e9) {
        if (D2 < 0) continue;
        else D = sqrt(D2);
      } else {
        long long tmp = ull(B) * ull(B) - 4ull * ull(A) * ull(C);
//        assert(abs(tmp) <= ll(1e10));
        if (tmp < 0) continue;
        else if (tmp > 0) D = sqrt(D2);
      }

      for (int k = -1; k <= 1; k += 2) {
        double X = (-B + k * D) / (2 * A);
        ans = min(ans, fabsl(X));
      }
    }
    printf("%.18e\n", (double)ans);
  }

  return 0;
}