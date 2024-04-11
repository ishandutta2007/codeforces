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

int n;
vector<vector<pii>> es;
vi win;

int encode(int a, int b, int c) {
  return (a * n + b) * 26 + c;
};

int calc(int a, int b, int c) {
  int &cw = win[encode(a, b, c)];
  if (cw) return cw;

  cw = -1;
//  eprintf("%d, %d, %c\n", a + 1, b + 1, c + 'a');
  for (auto e : es[a]) if (c <= e.second) {
    int nw = calc(b, e.first, e.second);
//    eprintf("-->%d %d %c\n", b + 1, e.first + 1, e.second + 'a');
    assert(nw);
    if (nw == -1) {
      cw = 1;
      break;
    }
  }
  return cw;
}

int main() {
  #ifdef DEBUG
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif

  int m;
  while (scanf("%d%d", &n, &m) == 2) {
    es.assign(n, vector<pii>());
    forn (i, m) {
      int a, b; char c;
      scanf("%d%d %c", &a, &b, &c), a--, b--;
      assert(0 <= a && a < n);
      assert(0 <= b && b < n);
      assert('a' <= c && c <= 'z');
      es[a].eb(b, c - 'a');
    }

    win.assign(n * n * 26, 0);

    forn (a, n) {
      forn (b, n) {
        int cw = calc(a, b, 0);
        assert(cw);
        printf("%c", "AB"[cw == 1 ? 0 : 1]);
      }
      printf("\n");
    }

    #ifdef DEBUG
    printf("\n");
    eprintf("\n");
    #endif
  }

  return 0;
}