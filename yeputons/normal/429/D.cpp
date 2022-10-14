

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

typedef double ld; // WARNING!!!

int randint(int l, int r) {
  int v = (rand() << 16) ^ rand();
  v %= r - l + 1;
  return l + abs(v);
}

const ld eps = 1e-7;
struct pt {
  int x, y;
  ld proj;

  bool operator<(const pt &p2) const { return proj < p2.proj - eps; }
};

ll dist(const pt &a, const pt &b) {
  ll res = 0;
  res += ll(a.x - b.x) * (a.x - b.x);
  res += ll(a.y - b.y) * (a.y - b.y);
  return res;
}

#define sqr(x) ((x) * (x))

int main() {
  #ifdef DEBUG
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif

  int n;
  while (scanf("%d", &n) == 1) {
    vector<pt> pts(n);
    for (int i = 0; i < n; i++) {
      scanf("%d", &pts[i].y);
      pts[i].x = i;
      if (i) pts[i].y += pts[i - 1].y;
    }

    ld A = randint(-int(1e5), int(1e5));
    ld B = randint(-int(1e5), int(1e5));
    ld D = sqrtl(A * A + B * B);
    A /= D; B /= D;
    for (int i = 0; i < n; i++) {
      pts[i].proj = A * pts[i].x + B * pts[i].y;
    }
    sort(pts.begin(), pts.end());

    vi ord(n);
    for (int i = 0; i < n; i++) ord[i] = i;
    random_shuffle(ord.begin(), ord.end());

    ll ans = 1e18;
    for (int i : ord) {
      int p1 = i - 1, p2 = i + 1;
      for (;;) {
        bool cont = false;
        if (p1 >= 0 && sqr(pts[i].proj - pts[p1].proj) < ans - eps) {
          ans = min(ans, dist(pts[i], pts[p1]));
          p1--;
          cont = true;
        }
        if (p2 < n && sqr(pts[p2].proj - pts[i].proj) < ans - eps) {
          ans = min(ans, dist(pts[i], pts[p2]));
          p2++;
          cont = true;
        }
        if (!cont) break;
      }
    }
    printf(LLD"\n", ans);
  }

  return 0;
}