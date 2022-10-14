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

int gcd(int a, int b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}

struct pt {
  int x, y;
  pt() : x(0), y(0) {}
  pt(int _x, int _y) : x(_x), y(_y) {}
  pt operator-(const pt &p2) const { return pt(x - p2.x, y - p2.y); }
  ll operator*(const pt &p2) const { return ll(x) * p2.y - ll(y) * p2.x; }
  int getHBorder() const {
    return gcd(abs(x), abs(y));
  }
};

int randint(int l, int r) {
  int v = (rand() << 16) ^ rand();
  v %= r - l + 1;
  return l + abs(v);
}

int main() {
  #ifdef DEBUG
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
  #endif

  int n;
  while (scanf("%d", &n) >= 1) {
    vector<pt> pts(n);
    for (pt &p : pts)
      scanf("%d%d", &p.x, &p.y);
/*    vector<pt> pts(n);
    for (pt &p : pts) {
      p.x = randint(-int(1e9), int(1e9));
      p.y = randint(-int(1e9), int(1e9));
    }*/

    ll alpha = ll(n) * (n + 1) / 2 + 1;

    const int MAXD = min(n, 130);
    vector<ld> ks(MAXD);
    for (int d = 2; d < MAXD; d++) {
      ld p2dn = powl(2, d - n);
      ld tmp1 = (ld)1 - p2dn;
      ld tmp2 = powl(2, d) - (ld)alpha * p2dn;
      ks[d] = tmp1 / tmp2;
//      eprintf("%.2e; %.2e / %.2e (%.2e)\n", (double)ks[d], (double)tmp1, (double)tmp2, p2dn);
    }

    vector<ld> ss(MAXD);
    vector<ll> gs(MAXD);

    forn (a, n) {
      for (int d = 2; d < MAXD; d++) {
        int b = (a + n - (d - 1)) % n;
        pt p1 = pts[a], p2 = pts[b];
        pt pd = p1 - p2;

        ss[d] += p2 * p1;
        gs[d] += pd.getHBorder();
      }
    }
    ld es = 0, eg = 0;
    forn (d, MAXD) {
      es += ss[d] * ks[d];
      eg += gs[d] * ks[d];
    }
    es /= 2;
//    eprintf("es=%.2lf\n", (double)es);
//    eprintf("eg=%.2lf\n", (double)eg);

    ld ans = es - eg / 2 + 1;
    printf("%.18e\n", (double)ans);
  }
  return 0;
}