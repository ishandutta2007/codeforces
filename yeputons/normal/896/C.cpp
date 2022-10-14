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

const ll INFLL = 1e18;

void madd(int &a, int b, int m) {
  if ((a += b) >= m) a -= m;
}

int mmul(int a, int b, int m) {
  return ll(a) * b % m;
}

int mpow(int a, int b, int m) {
  assert(b >= 0);
  int res = 1;
  for (; b; b >>= 1, a = mmul(a, a, m))
    if (b & 1) res = mmul(res, a, m);
  return res;
}

class Magic {
public:
  Magic(const vector<ll> &xs) {
    for (int i = 0; i < sz(xs); i++)
      data[i] = xs[i];
    data[sz(xs)] = 0;
  }

  void add(int l, int r, ll x) {
    splitAt(l); splitAt(r + 1);
    auto lit = data.find(l), rit = data.find(r + 1);
    assert(lit != data.end() && rit != data.end());
    assert(lit->first == l);
    assert(rit->first == r + 1);
    for (; lit != rit; lit++)
      lit->second += x;
  }

  void assign(int l, int r, ll x) {
    splitAt(l); splitAt(r + 1);
    auto lit = data.find(l), rit = data.find(r + 1);
    assert(lit != data.end() && rit != data.end());
    assert(lit->first == l);
    assert(rit->first == r + 1);
    lit->second = x;

    lit++;
    while (lit != rit) {
      auto ne = lit;
      ne++;
      data.erase(lit);
      lit = ne;
    }
  }

  ll getKth(int l, int r, int k) {
    static vector<pair<ll, int>> cur;
    collect(l, r, cur);
    sort(cur.begin(), cur.end());
    for (auto &x : cur) {
      if (x.second > k) return x.first;
      k -= x.second;
    }
    assert(false);
    return 0;
  }

  int getSumPow(int l, int r, int p, int m) {
    static vector<pair<ll, int>> cur;
    collect(l, r, cur);

    int ans = 0;
    for (auto &x : cur) {
      int cval = mpow(x.first % m, p, m);
      madd(ans, mmul(x.second % m, cval, m), m);
    }
    return ans;
  }

  void eprint() {
    eprintf("eprint:\n");
    for (auto &x : data)
      eprintf("  %I64d starts at %d\n", x.second, x.first + 1);
  }

private:
  map<int, ll> data;

  map<int, ll>::iterator splitAt(int x) {
    auto it = data.lower_bound(x);
    assert(it != data.end());
    if (it->first == x) return it;
    assert(it->first > x);
    assert(it != data.begin());
    it--;
    assert(it->first < x);

    auto it2 = data.emplace(x, it->second);
    assert(it2.second);
    return it2.first;
  }

  void collect(int l, int r, vector<pair<ll, int>> &cur) {
    auto it = data.lower_bound(l);
    assert(it != data.end());
    if (it->first > l) it--;
    assert(it->first <= l);

//    eprintf("collect(%d..%d):\n", l, r);
    cur.clear();
    while (it->first <= r) {
      auto nit = it; nit++;
      assert(nit != data.end());
      int cl = max(it->first, l);
      int cr = min(nit->first - 1, r);
      assert(cl <= cr);
      cur.emplace_back(it->second, cr - cl + 1);
//      eprintf("  %I64d (%d..%d)\n", it->second, cl, cr);
      it = nit;
    }
  }
};

int seed;
int rnd() {
  int result = seed;
  seed = ((ll)seed * 7 + 13) % 1000000007;
  return result;
}

int main() {
  #ifdef DEBUG
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif

  int n, q, vmax;
  while (scanf("%d%d%d%d", &n, &q, &seed, &vmax) == 4) {
    vector<ll> as(n);
    forn (i, n) {
      as[i] = rnd() % vmax + 1;
//      eprintf("%I64d%c", as[i], "\n "[i + 1 < n]);
    }

    Magic m(as);
//    m.eprint();
    forn (qid, q) {
      int op = rnd() % 4 + 1;
      int l = rnd() % n + 1;
      int r = rnd() % n + 1;
      if (l > r) swap(l, r);

      int x;
      if (op == 3) {
        x = rnd() % (r - l + 1) + 1;
      } else {
        x = rnd() % vmax + 1;
      }

      switch (op) {
      case 1:
        m.add(l - 1, r - 1, x);
//        m.eprint();
        break;
      case 2:
        m.assign(l - 1, r - 1, x);
//        m.eprint();
        break;
      case 3:
        printf(LLD"\n", m.getKth(l - 1, r - 1, x - 1));
        break;
      case 4: {
        int y = rnd() % vmax + 1;
        printf("%d\n", m.getSumPow(l - 1, r - 1, x, y));
      } break;
      }
    }
  }

  return 0;
}