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

struct pt {
  int x, y;
  pt() : x(0), y(0) {}
  pt(int _x, int _y) : x(_x), y(_y) {}
  pt operator-(const pt &p2) const { return pt(x - p2.x, y - p2.y); }
};

vector<pt> gen(int len) {
  int len2 = len * len;
  vector<pt> res;
  for (int x = 1; x <= len; x++) {
    for (int y = -len; y <= len; y++) if (x * x + y * y == len2)
      if (x && y)
        res.pb(pt(x, y));
  }
  return res;
}

int main() {
  #ifdef DEBUG
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif

  int a, b;
  while (scanf("%d%d", &a, &b) == 2) {
    int len2 = a * a + b * b;
    vector<pt> as, bs;
    as = gen(a);
    bs = gen(b);
    eprintf("%d %d\n", sz(as), sz(bs));
    for (pt p1 : as)
    for (pt p2 : bs) {
      pt mid = p1 - p2;
      if (!mid.x || !mid.y) continue;
      if (mid.x * mid.x + mid.y * mid.y != len2) continue;
      printf("YES\n");
      printf("0 0\n");
      printf("%d %d\n", p1.x, p1.y);
      printf("%d %d\n", p2.x, p2.y);
      goto end;
    }
    printf("NO\n");
    end:;
  }

  return 0;
}