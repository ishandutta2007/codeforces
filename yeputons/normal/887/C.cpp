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
#include <sstream>

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

const int n = 24;

struct Perm {
  Perm() : goesTo(n) {
    for (int i = 0; i < n; i++)
      goesTo[i] = i;
  }
  Perm(const vi &ids, const vi &after) : goesTo(n, -1) {
    assert(sz(ids) == n);
    assert(sz(after) == n);

    set<int> was;
    for (int i = 0; i < n; i++) {
      int id = ids[i] - 1;
      assert(0 <= id && id < n);
      int v = after[i] - 1;
      assert(0 <= v && v < n);
      assert(goesTo[v] < 0);
      assert(!was.count(id));
      goesTo[v] = id;
      was.insert(id);
    }
  }

  bool operator==(const Perm &rhs) const {
    return goesTo == rhs.goesTo;
  }

  bool operator!=(const Perm &rhs) const {
    return goesTo != rhs.goesTo;
  }

  vi operator()(const vi &a) const {
    assert(sz(a) == n);
    vi result(n);
    for (int i = 0; i < n; i++)
      result[goesTo[i]] = a[i];
    return result;
  }

  void eprintln() const {
    for (int i = 0; i < n; i++)
      eprintf("%2d%c", i + 1, "\n "[i + 1 < n]);
    for (int i = 0; i < n; i++)
      eprintf("%2d%c", goesTo[i] + 1, "\n "[i + 1 < n]);
  }

private:
  vi goesTo;

  friend Perm operator*(const Perm &lhs, const Perm &rhs) {  // res(x) = lhs(rhs(x))
    Perm res;
    for (int i = 0; i < n; i++)
      res.goesTo[i] = lhs.goesTo[rhs.goesTo[i]];
    return res;
  }
};

vi parseStr(const char *a) {
  stringstream ss;
  ss << a;
  vi res;
  int x;
  while (ss >> x) res.pb(x);
  return res;
}

Perm getPerm(const char *sa, const char *sb) {
  vi as = parseStr(sa), bs = parseStr(sb);
  return Perm(as, bs);
}

void checkOrder(const Perm &p, int ord) {
  Perm cur = p;
  for (int i = 0; i + 1 < ord; i++) {
    assert(cur != Perm());
    cur = cur * p;
  }
  assert(cur == Perm());
}

const char* sinit =
"       1  2 "
"       3  4 "
"13 14  5  6 17 18 21 22 "
"15 16  7  8 19 20 23 24 "
"       9 10 "
"      11 12 "
;

const char* srot1 =
"       3  1 "
"       4  2 "
" 5  6 17 18 21 22 13 14 "
" 7  8 19 20 23 24 15 16 "
"      10 12 "
"       9 11 "
;

const char* srot2 =
"      24 23 "
"      22 21 "
"15 13  1  2 18 20 12 11 "
"16 14  3  4 17 19 10  9 "
"       5  6 "
"       7  8 "
;

const char* sfinish =
"       1  2 "
"      16 14 "
"13  9  7  5  3 18 21 22 "
"15 10  8  6  4 20 23 24 "
"      19 17 "
"      11 12 "
;

bool good(const vi &xs) {
  bool ok = true;
  for (int i = 0; i < 24; i += 4) {
    ok &= xs[i] == xs[i + 1];
    ok &= xs[i] == xs[i + 2];
    ok &= xs[i] == xs[i + 3];
  }
  return ok;
}

int main() {
  #ifdef DEBUG
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif

  const Perm rot1 = getPerm(sinit, srot1);
  const Perm rot2 = getPerm(sinit, srot2);
  const Perm finish = getPerm(sinit, sfinish);
  const Perm finish2 = finish * finish * finish;
  checkOrder(rot1, 4);
  checkOrder(rot2, 4);
  checkOrder(rot2 * rot1, 3);
  checkOrder(finish, 4);
  checkOrder(finish2, 4);
  {
    vi tmp(n);
    for (int i = 0; i < n; i++) tmp[i] = 100 + i;
    set<vi> was;
    for (int i1 = 0; i1 < 4; i1++, tmp = rot1(tmp))
    for (int i2 = 0; i2 < 4; i2++, tmp = rot2(tmp))
    for (int i3 = 0; i3 < 4; i3++, tmp = rot1(tmp)) {
      was.insert(tmp);
    }
    assert(sz(was) == 24);
  }

  vi as(n);
  while (scanf("%d", &as[0]) == 1) {
    for (int i = 1; i < n; i++)
      scanf("%d", &as[i]);

    for (int i1 = 0; i1 < 4; i1++, as = rot1(as))
    for (int i2 = 0; i2 < 4; i2++, as = rot2(as))
    for (int i3 = 0; i3 < 4; i3++, as = rot1(as)) {
      if (good(finish(as)) || good(finish2(as))) {
        printf("YES\n");
        goto end;
      }
    }
    printf("NO\n");
    end:;
  }

  return 0;
}