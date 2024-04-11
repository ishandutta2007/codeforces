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

int go(int l, int r, int v) {
  if (v < l) return l;
  if (v > r) return r;
  return v;
}

int main() {
  #ifdef DEBUG
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
  #endif

  int vals[6];
  while (scanf("%d", &vals[0]) >= 1) {
    for (int i = 1; i < 6; i++)
      scanf("%d", &vals[i]);
    int h = vals[1] + vals[2];
    assert(vals[4] + vals[5] == h);

    int ans = 0;
    int pw = vals[0];
    for (int y = 1; y <= h; y++) {
      int cw = 2 * vals[0];
      cw += go(0, vals[1], y);
      cw -= go(0, vals[2], y - vals[1]);

      cw += go(0, vals[5], y);
      cw -= go(0, vals[4], y - vals[5]);
      assert(cw % 2 == 0);
      cw /= 2;
//      eprintf("y=%d; %d-->%d\n", y, pw, cw);
      ans += cw + pw;

      pw = cw;
    }
    printf("%d\n", ans);
  }
  return 0;
}