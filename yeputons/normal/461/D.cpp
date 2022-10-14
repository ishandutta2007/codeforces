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
#include <bitset>

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

class MagicSet {
  set<pii> data;
  int xsec;

public:
  MagicSet() : data(), xsec(false) {}

  void swap(MagicSet &b) {
    data.swap(b.data);
    std::swap(xsec, b.xsec);
  }
  void insert(pii v) {
    data.insert(mp(v.first, v.second ^ xsec));
  }
  void moveTo(MagicSet &b) {
    if (sz(data) > sz(b.data)) swap(b);
    for (auto s : data)
      b.insert(mp(s.first, s.second ^ xsec));
    data.clear();
  }
  void revAll() {
    xsec ^= 1;
  }
  pii pop() {
    assert(!data.empty());
    pii res = *data.begin();
    res.second ^= xsec;
    data.erase(data.begin());
    return res;
  }
  bool empty() const { return data.empty(); }
};

int getRank(int maxw, vector<pair<pii, int>> src) {
  vector<MagicSet> ors(maxw + 1);
//  eprintf("===== maxw=%d\n", maxw);
  for (auto &s : src) {
//    eprintf("%d %d; %d\n", s.first.first, s.first.second, s.second);
    assert(s.first.first <= s.first.second);
    ors[s.first.first].insert(mp(s.first.second, s.second));
  }

  int ans = 0;
  forn (x, maxw + 1) if (!ors[x].empty()) {
    pii cur = ors[x].pop();
//    eprintf("x=%d; cur=%d %d\n", x, cur.first, cur.second);
    assert(x - 1 <= cur.first);
    if (cur.first < x) {
      if (cur.second) throw 0;
      x--;
      continue;
    }
    ans++;
    if (cur.second) ors[x].revAll();
    ors[x].moveTo(ors[cur.first + 1]);
  }
  return ans;
}

const int MOD = int(1e9 + 7);
void madd(int &a, int b) { if ((a += b) >= MOD) a -= MOD; }
//int mmul(int a, int b) { return ll(a) * b % MOD; }

int main() {
  #ifdef DEBUG
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif

  int n, k;

  while (scanf("%d%d", &n, &k) == 2) {
    vector<pair<pii, int> > ts[2];
    forn (i, k) {
      int x, y;
      char c;
      scanf("%d%d %c", &x, &y, &c), x--, y--;

      int cnt = min(min(x, n - 1 - x), min(y, n - 1 - y)) + 1;
      int st = max(x, y) - min(x, y);

      int l = st, r = st + 2 * (cnt - 1);
//      eprintf("%d %d\n", l + 1, r + 1);
      ts[(x + y) % 2].pb(mp(mp(l / 2, r / 2), c == 'o'));
    }

    try {
      int ans = 0;
      forn (i, 2) {
        int msz = (n + 1 - i) / 2;
        ans += msz - getRank(n, ts[i]);
      }

      int out = 1;
      while (ans --> 0)
        madd(out, out);
      printf("%d\n", out);
    } catch (...) {
      printf("0\n");
    }
//    break;
  }
  return 0;
}