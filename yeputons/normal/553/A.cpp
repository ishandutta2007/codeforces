#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>

using namespace std;

#define pb push_back
#define mp make_pair
#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...)
#endif
#define sz(x) ((int)(x).size())
#define forn(i, n) for (int i = 0; i < (n); i++)

#ifdef DEBUG
struct Timestamper {
  string msg;
  clock_t start;

  Timestamper(const string &_msg) : msg(_msg), start(clock()) {}
  ~Timestamper() {
    eprintf("[ %s ] Time=%.3lfs\n", msg.c_str(), (clock() - start) * 1.0 / CLOCKS_PER_SEC);
  }
} __timestamper("end");
#else
struct Timestamper {};
#endif

typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<ll, ll> pll;

const int inf = 1e9;

const int MOD = int(1e9) + 7;
void madd(int &a, int b) { if ((a += b) >= MOD) a -= MOD; }
int mmul(int a, int b) { return ll(a) * b % MOD; }

const int MAXN = 1000;
int C[MAXN + 1][MAXN + 1];

int main() {
  #ifdef DEBUG
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
  #endif

  forn (i, MAXN + 1) {
    C[i][0] = C[i][i] = 1;
    for (int i2 = 1; i2 < i; i2++) {
      madd(C[i][i2] = C[i - 1][i2 - 1], C[i - 1][i2]);
    }
  }

  int k;
  while (scanf("%d", &k) >= 1) {
    vi cs(k);
    int sum = 0;
    forn (i, k) {
      scanf("%d", &cs[i]);
      sum += cs[i];
    }
    assert(sum <= MAXN);

    vvi dyn(k + 1, vi(sum + 1, 0));
    dyn[0][0] = 1;
    int prevSum = 0;
    forn (cid, k) {
      int pdsum = 0;
      forn (nlen, sum + 1) {
        if (nlen > prevSum) {
          int &ans = dyn[cid + 1][nlen];
          madd(ans, mmul(pdsum, C[nlen - prevSum - 1][cs[cid] - 1]));
//          forn (plen, nlen) {
//            madd(ans, mmul(dyn[cid][plen], C[nlen - prevSum - 1][cs[cid] - 1]));
//          }
        }
        madd(pdsum, dyn[cid][nlen]);
      }
      prevSum += cs[cid];
    }
    forn (i, sum)
      assert(dyn[k][i] == 0);
    printf("%d\n", dyn[k][sum]);
  }
  return 0;
}