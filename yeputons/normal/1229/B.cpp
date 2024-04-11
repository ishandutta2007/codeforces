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
#define eb emplace_back
#define mp make_pair
#define TASKNAME ""

#ifdef DEBUG
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
#define eprintf(...)
#endif

#define TIMESTAMP(x) eprintf("[" #x "] Time = %.3lfs\n",clock()*1.0/CLOCKS_PER_SEC)

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

ll gcd(ll a, ll b) {
  return b ? gcd(b, a % b) : a;
}

struct segm_tree {
  segm_tree(int n) {
    off = 1;
    while (off < n) off <<= 1;
    tr = vll(2 * off);
  }

  void set(int pos, ll val) {
    assert(0 <= pos && pos < off);
    tr[pos += off] = val;
    for (pos >>= 1; pos >= 1; pos >>= 1)
      tr[pos] = gcd(tr[2 * pos], tr[2 * pos + 1]);
  }

  ll get(int l, int r) {
    ll res = 0;
    assert(0 <= l && l <= r && r < off);
    l += off; r += off;
    while (l <= r) {
      if (l & 1) res = gcd(res, tr[l++]);
      if (!(r & 1)) res = gcd(res, tr[r--]);
      l >>= 1;
      r >>= 1;
    }
    return res;
  }

  int findLastLt(ll minv) {
    int pos = 1;
    if (mp(tr[pos] == 0, tr[pos]) >= mp(minv == 0, minv)) {
      return -1;
    }

    ll toRight = 0;
    while (pos < off) {
      ll rv = gcd(toRight, tr[2 * pos + 1]);
//      eprintf("      pos=%d / %d (%lld; %lld; %lld)\n", pos, off, toRight, rv, minv);
      if (mp(rv == 0, rv) < mp(minv == 0, minv)) {
        pos = 2 * pos + 1;
      } else {
        toRight = gcd(toRight, rv);
        pos = 2 * pos;
      }
    }
    return pos - off;
  }

public:
  vll tr;
  int off;
};

const int MOD = int(1e9) + 7;

void madd(int &a, int b) {
  if ((a += b) >= MOD) a -= MOD;
}

int mmul(int a, int b) {
  return ll(a) * b % MOD;
}

vll xs;
vvi es;
int ans;
segm_tree tr(1);

void dfs(int v, int par, int depth) {
  tr.set(depth, xs[v]);

  int curpos = depth;
/*  eprintf("v=%d:", v);
  for (int i = 0; i <= depth; i++)
    eprintf(" %lld", tr.get(i, i));
  eprintf("\n");*/

  while (curpos >= 0) {
    ll curx = tr.get(curpos, depth);
    int L = tr.findLastLt(curx);
//    eprintf("  %d..%d: %lld\n", L + 1, curpos, curx);
    madd(ans, mmul(curx % MOD, curpos - L));
    curpos = L;
  }

  for (int b : es[v])
    if (b != par)
      dfs(b, v, depth + 1);
  tr.set(depth, 0);
}

int main() {
  #ifdef DEBUG
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif

  int n;
  while (scanf("%d", &n) == 1) {
    xs = vll(n);
    forn (i, n) {
      scanf("%lld", &xs[i]);
    }

    es = vvi(n);
    forn (i, n - 1) {
      int a, b;
      scanf("%d%d", &a, &b), a--, b--;
      es[a].pb(b);
      es[b].pb(a);
    }

    ans = 0;
    tr = segm_tree(n);
    dfs(0, -1, 0);
    printf("%d\n", ans);
  }

  return 0;
}