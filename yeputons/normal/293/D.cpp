#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <list>
#include <map>
#include <set>

using namespace std;

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;

class Solver {
  double sum, sumx, sumx2;
  double curx;

  public:
  Solver() : sum(0), sumx(0), sumx2(0), curx(0) {}
  void push(double val) {
    sum += val;
    sumx += val * curx;
    sumx2 += val * curx * curx;
    curx += 1;
  }
  double get() {
    return sum * curx * curx - 2 * curx * sumx + sumx2;
  }
};

struct pt {
  int x, y;
  pt() : x(0), y(0) {}
  pt(int x, int y) : x(x), y(y) {}
  pt operator-(const pt &p2) const { return pt(x - p2.x, y - p2.y); }
  ll operator*(const pt &p2) const { return ll(x) * p2.y - ll(y) * p2.x; }
  bool operator<(const pt &p2) const { return x != p2.x ? x < p2.x : y < p2.y; }
};

int getBord(const pt &p) {
  assert(p.x || p.y);
  return abs(__gcd(p.x, p.y));
}

double getY(pt a, pt b, int x) {
  if (b < a) swap(a, b);
  assert(a.x <= x && x <= b.x);
  assert(a.x != b.x);
  return a.y + double(b.y - a.y) * (x - a.x) / (b.x - a.x);
}

const double eps = 1e-9;
ll rUp(double x) {
  if (fabs(x) < eps) return 0;
  if (x > 0) return (ll)(x + 1 - eps);
  else return (ll)(x - eps);
}

ll rDn(double x) {
  if (fabs(x) < eps) return 0;
  if (x > 0) return (ll)(x + eps);
  else return (ll)(x - 1 + eps);
}

int main() {
  #ifdef DEBUG
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
  #endif

  assert(ll(-1.5) == -1);

  int n;
  while (scanf("%d", &n) >= 1) {
    vector<pt> pts(n);
    for (int i = 0; i < n; i++)
      scanf("%d%d", &pts[i].x, &pts[i].y);
    pts.pb(pts[0]);

    ll sq = 0;
    for (int i = 0; i < n; i++)
      sq += pts[i + 1] * pts[i];
    if (sq < 0) {
      reverse(pts.begin() + 1, pts.end() - 1);
      sq = -sq;
    }
    assert(sq >= 0);
    ll bord = 0;
    for (int i = 0; i < n; i++)
      bord += getBord(pts[i + 1] - pts[i]);
    ll inner = sq + 2 - bord;
    assert(inner % 2 == 0);
    inner /= 2;
    inner += bord;
    eprintf("all=%I64d\n", inner);

    double res = 0;
    for (int step = 0; step < 2; step++) {
      pts.erase(pts.begin() + n);
      rotate(pts.begin(), min_element(pts.begin(), pts.end()), pts.end());
      pts.pb(pts[0]);
      int mid = max_element(pts.begin(), pts.end()) - pts.begin();

/*      for (int i = 0; i < sz(pts); i++)
        eprintf("%d %d\n", pts[i].x, pts[i].y);
      eprintf("mid=%d\n", mid);*/

      int minx = pts[0].x, maxx = pts[mid].x;
      int p1 = 0, p2 = n - 1;

      Solver s;
      for (int x = minx; x <= maxx; x++) {
        while (pts[p1 + 1].x <= x && p1 + 1 < mid) p1++;
        while (pts[p2].x < x) p2--;

        assert(p1 + 1 <= mid);
        assert(p2 >= mid);
        ll y1 = rDn(getY(pts[p1], pts[p1 + 1], x));
        ll y2 = rUp(getY(pts[p2], pts[p2 + 1], x));
        assert(y2 <= y1 + 1);
        ll ccnt = y1 - y2 + 1;

        res += s.get() * ccnt;
        s.push(ccnt);
      }

      pts.erase(pts.begin() + n);
      for (int i = 0; i < sz(pts); i++)
        swap(pts[i].x, pts[i].y);
      reverse(pts.begin(), pts.end());
      pts.pb(pts[0]);
    }
    res /= inner;
    res /= inner - 1;
    printf("%.18lf\n", res);
  }
  return 0;
}