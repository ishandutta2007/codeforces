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

ll roundUp(ll a, ll b) {
  assert(b > 0);
  ll d = a % b;
  if (d < 0) d += b;
  if (d) a += b - d;
  return a / b;
}
ll roundDn(ll a, ll b) {
  assert(b > 0);
  ll d = a % b;
  if (d < 0) d += b;
  a -= d;
  return a / b;
}

const int RINF = int(1e7);

struct Rect {
  // a = x + y
  // b = x - y
  ll mina, maxa;
  ll minb, maxb;

  Rect() : mina(0), maxa(0), minb(0), maxb(0) {}
  Rect(ll x, ll y) : mina(x + y), maxa(x + y), minb(x - y), maxb(x - y) {}
  void extend(ll x) {
    mina -= x; maxa += x;
    minb -= x; maxb += x;
  }
  bool contains(ll x, ll y) {
    ll a = x + y, b = x - y;
    return
      mina <= a && a <= maxa &&
      minb <= b && b <= maxb;
  }
  void divideBy(ll k) {
    if (!k) {
      if (!contains(0, 0)) {
        mina = 0; maxa = -1;
        minb = 0; maxb = -1;
      } else {
        mina = minb = -RINF;
        maxa = maxb = RINF;
      }
      return;
    }
    if (k < 0) {
      swap(mina, maxa);
      swap(minb, maxb);
      mina = -mina;
      maxa = -maxa;
      minb = -minb;
      maxb = -maxb;
      k = -k;
    }
    mina = roundUp(mina, k);
    minb = roundUp(minb, k);
    maxa = roundDn(maxa, k);
    maxb = roundDn(maxb, k);
  }

  pair<ll, ll> getAny() const {
    for (int da = 0; da <= 2 && mina + da <= maxa; da++)
    for (int db = 0; db <= 2 && minb + db <= maxb; db++) {
      ll ca = mina + da, cb = minb + db;
      eprintf("ca = %I64d cb=%I64d\n", ca, cb);
      if ((ca + cb) % 2) continue;
      ll x = (ca + cb) / 2;
      ll y = ca - x;
      return mp(x, y);
    }
    throw runtime_error("No points inside");
  }
  bool empty() const {
    return mina > maxa || minb > maxb;
  }
};
Rect operator&(const Rect &a, const Rect &b) {
  Rect r;
  r.mina = max(a.mina, b.mina);
  r.maxa = min(a.maxa, b.maxa);
  r.minb = max(a.minb, b.minb);
  r.maxb = min(a.maxb, b.maxb);
  return r;
}

struct Ev {
  int tim;
  ll k;
  ll x, y;

  bool operator<(const Ev &e2) const {
    return tim < e2.tim;
  }
};

int main() {
  #ifdef DEBUG
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif

  int n, l;
  while (scanf("%d%d", &n, &l) == 2) {
    bool parityOk = true;

    vector<Ev> evs(n);
    for (Ev &e : evs) {
      ll tim;
      scanf(LLD LLD LLD, &tim, &e.x, &e.y);
      e.tim = tim % l;
      e.k = tim / l;
      parityOk &= abs(e.x + e.y) % 2 == tim % 2;
    }
    if (!parityOk) {
      printf("NO\n");
      continue;
    }

    evs.pb({ 0, 0, 0, 0 });
    n = sz(evs);
    sort(evs.begin(), evs.end());

    Rect cur;
    cur.extend(l);
    for (int i = 0; i + 1 < sz(evs); i++) {
      const Ev &e1 = evs[i], &e2 = evs[i + 1];
//      eprintf("nya %lld %lld\n",e1.k * l + e1.tim, e2.k * l + e2.tim);

      Rect r(e2.x - e1.x, e2.y - e1.y);
      r.extend(e2.tim - e1.tim);
      r.divideBy(e2.k - e1.k);
//      eprintf("%d; r=%lld..%lld; %lld..%lld\n", r.empty(), r.mina, r.maxa, r.minb, r.maxb);
      cur = cur & r;
    }
    for (const Ev &e : evs) {
      Rect r(e.x, e.y);
      r.extend(l - e.tim);
      r.divideBy(e.k + 1);
      cur = cur & r;
    }

    eprintf("\n");
    eprintf("last=" LLD ".." LLD "; " LLD ".." LLD "\n", cur.mina, cur.maxa, cur.minb, cur.maxb);
    ll alpha0, beta0;
    try {
      tie(alpha0, beta0) = cur.getAny();
    } catch (...) {
      printf("NO\n");
      continue;
    }

    bool found = false;
    for (int ddy = -2; ddy <= 2; ddy++)
    for (int ddx = -2; ddx <= 2; ddx++) {
      ll alpha = alpha0 + ddx;
      ll beta = beta0 + ddy;
      if (!cur.contains(alpha, beta)) continue;

      eprintf("diff=(" LLD ", " LLD ")\n", alpha, beta);

      vector<Ev> pts;
      for (const Ev &e : evs) {
        pts.pb({
          e.tim, 0,
          e.x - e.k * alpha, e.y - e.k * beta
        });
      }
      pts.pb({
        l, 0,
        alpha, beta 
      });

      string s = "";
      bool bad = false;
      for (int i = 0; i + 1 < sz(pts); i++) {
        ll dx = pts[i + 1].x - pts[i].x;
        ll dy = pts[i + 1].y - pts[i].y;
  //      eprintf("tim=%d\n", pts[i + 1].tim);
        assert(sz(s) == pts[i].tim);
        ll remt = pts[i + 1].tim - pts[i].tim - abs(dx) - abs(dy);
        assert(remt >= 0);
        if (remt % 2) {
          bad = true;
          break;
        }
        assert(remt % 2 == 0);

  //      eprintf("dx=%lld, dy=%lld, remt=%lld\n", dx, dy, remt);
        while (dx > 0) { s += "R"; dx--; }
        while (dx < 0) { s += "L"; dx++; }
        while (dy > 0) { s += "U"; dy--; }
        while (dy < 0) { s += "D"; dy++; }
        assert(dx == 0 && dy == 0);
  //      eprintf("len=%s\n", s.c_str());
        while (remt > 0) {
          s += "LR";
          remt -= 2;
        }
        assert(sz(s) == pts[i + 1].tim);
      }
      if (!bad) {
        assert(sz(s) == l);
        printf("%s\n", s.c_str());
        found = true;
        goto end;
      }
    }
    end:;
    if (!found) {
      printf("NO\n");
    }
  }

  return 0;
}