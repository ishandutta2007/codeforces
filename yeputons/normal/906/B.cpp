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

bool check(const vvi &res) {
  const int h = sz(res);
  const int w = sz(res[0]);
  forn (y, h)
    forn (x, w) {
      assert(0 <= res[y][x] && res[y][x] < w * h);
      int oy1 = res[y][x] / w;
      int ox1 = res[y][x] % w;
      forn (i, 4) {
        const int dx[] = { 1, 0, -1, 0 };
        const int dy[] = { 0, 1, 0, -1, 0 };
        int x2 = x + dx[i], y2 = y + dy[i];
        if (x2 < 0 || x2 >= w || y2 < 0 || y2 >= h) continue;
        int oy2 = res[y2][x2] / w;
        int ox2 = res[y2][x2] % w;
        int d = abs(ox1 - ox2) + abs(oy1 - oy2);
        assert(d >= 1);
        if (d == 1) return false;
      }
    }
  return true;
}

vvi solve(int h, int w) {
  if (w < h) {
    vvi res(h, vi(w));
    vvi res2 = solve(w, h);
    if (res2.empty()) return vvi();

    forn (y, h)
    forn (x, w) {
      int ox = res2[x][y] / h;
      int oy = res2[x][y] % h;
      res[y][x] = oy * w + ox;
    }
    return res;
  }
  if (w >= 5) {
    vi cols;
    for (int i = 0; i < w; i += 2) cols.pb(i);
    for (int i = 1; i < w; i += 2) cols.pb(i);

    vvi res(h, vi(w));
    forn (y, h)
      forn (x, w) {
        res[y][(x + y % 2) % w] = y * w + cols[x];
      }
    return res;
  }
  if (w == 1) {
    assert(h == 1);
    return {{0}};
  }
  int n = h * w;
  int cnt = h * w * 2 - h - w;
  if (2 * cnt > n * (n - 1) / 2) {
    return vvi();
  }
  assert(2 <= w && w <= 4);
  if (h == 1) {
    assert(w == 4);
    return {{2, 0, 3, 1}};
  }
  if (h == 2 && w == 4) {
    return {
      { 4, 3, 6, 1 },
      { 2, 5, 0, 7 }
    };
  }
  if (h == 2 && w == 3) {
    return vvi();  // proved
  }
  if (h == 3 && w == 3) {
    return {
      {0, 2, 3},
      {4, 6, 5},
      {8, 1, 7}
    };
/*    vi perm;
    forn (i, 9) perm.pb(i);
    do {
      vvi res = {
        { perm[0], perm[1], perm[2] },
        { perm[3], perm[4], perm[5] },
        { perm[6], perm[7], perm[8] },
      };
      if (check(res)) return res;
    } while (next_permutation(perm.begin(), perm.end()));
    return vvi();*/
  }
  if (h == 3 && w == 4) {
    return {
      {  0,  8,  2,  5 },
      {  3,  6,  9, 11 },
      { 10,  1,  7,  4 },
    };
  }
  if (h == 4 && w == 4) {
    return {
      {  0,  2,  5,  8 },
      { 15,  7, 10, 13 },
      {  1,  4,  3,  6 },
      {  9, 12, 14, 11 }
    };
  }
  eprintf("%d %d\n", w, h);
  assert(false);
  return vvi();
}

int main() {
  #ifdef DEBUG
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif

  int h, w;
  while (scanf("%d%d", &h, &w) == 2) {
    vvi res = solve(h, w);
    if (res.empty()) {
      printf("NO\n");
    } else {
      printf("YES\n");
      assert(sz(res) == h);

      forn (y, h) {
        assert(sz(res[y]) == w);
        forn (x, w)
          printf("%d%c", res[y][x] + 1, "\n "[x + 1 < w]);
      }

      set<int> was;
      forn (y, h)
        forn (x, w) {
          was.insert(res[y][x]);
          assert(0 <= res[y][x] && res[y][x] < w * h);
          int oy1 = res[y][x] / w;
          int ox1 = res[y][x] % w;
          forn (i, 4) {
            const int dx[] = { 1, 0, -1, 0 };
            const int dy[] = { 0, 1, 0, -1, 0 };
            int x2 = x + dx[i], y2 = y + dy[i];
            if (x2 < 0 || x2 >= w || y2 < 0 || y2 >= h) continue;
            int oy2 = res[y2][x2] / w;
            int ox2 = res[y2][x2] % w;
            int d = abs(ox1 - ox2) + abs(oy1 - oy2);
            assert(d >= 1);
            if (d == 1) {
              eprintf("FAIL at (%d,%d)-(%d,%d): %d and %d are neighbors\n", x + 1, y + 1, x2 + 1, y2 + 1, res[y][x], res[y2][x2]);
            }
            assert(d > 1);
          }
        }
      assert(sz(was) == w * h);
    }
  }

  return 0;
}