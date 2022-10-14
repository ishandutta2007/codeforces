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

struct num {
  int a, b;
  explicit num(int _a, int _b) : a(_a), b(_b) {
    assert(0 <= a && a <= b);
    assert(0 < b);
  }
  bool operator<(const num &other) const {
    return ll(a) * other.b < ll(b) * other.a;
  }
  bool operator==(const num &other) const {
    return ll(a) * other.b == ll(b) * other.a;
  }
};

int n;
vvi es;
vi ibad;
vi answer;

bool check(const num &minf) {
  vb alive(n, true);
  vi deg(n);
  forn (i, n) deg[i] = sz(es[i]);

  deque<int> q;
  for (int x : ibad) {
    alive[x] = false;
    q.pb(x);
  }
  while (!q.empty()) {
    int v = q.front();
    q.pop_front();
    for (int b : es[v]) if (alive[b]) {
      deg[b]--;
      if (num(deg[b], sz(es[b])) < minf) {
        alive[b] = false;
        q.pb(b);
      }
    }
  }
  if (find(alive.begin(), alive.end(), true) == alive.end()) return false;
  answer.clear();
  forn (i, n)
    if (alive[i])
      answer.pb(i);
  assert(!answer.empty());
  return true;
}

int main() {
  #ifdef DEBUG
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
  #endif

  int m, k;
  while (scanf("%d%d%d", &n, &m, &k) >= 1) {
    ibad = vi(k);
    for (int &x : ibad)
      scanf("%d", &x), x--;

    es = vvi(n);
    forn (i, m) {
      int a, b;
      scanf("%d%d", &a, &b), a--, b--;
      es[a].pb(b);
      es[b].pb(a);
    }

    vector<num> cands;
    forn (i, n) {
      for (int i2 = 0; i2 <= sz(es[i]); i2++)
        cands.pb(num(i2, sz(es[i])));
    }
    sort(cands.begin(), cands.end());
    cands.erase(unique(cands.begin(), cands.end()), cands.end());
    assert(!cands.empty());

    assert(cands[0] == num(0, 1));
    answer.clear();
    bool res = check(cands[0]);
    assert(res);

    int L = 0, R = sz(cands);
    while (L + 1 < R) {
      int M = (L + R) / 2;
      if (check(cands[M])) L = M;
      else R = M;
    }
    assert(!answer.empty());
    eprintf("%d/%d\n", cands[L].a, cands[L].b);
    printf("%d\n", sz(answer));
    forn (i, sz(answer))
      printf("%d%c", answer[i] + 1, "\n "[i + 1 < sz(answer)]);
  }
  return 0;
}