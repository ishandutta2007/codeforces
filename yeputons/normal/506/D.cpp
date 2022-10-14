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

vvi es;
vi col;
int ccol;

void dfs1(int v) {
  if (col[v] >= 0) {
    assert(col[v] == ccol);
    return;
  }
  col[v] = ccol;
  for (int x : es[v])
    dfs1(x);
}

vi curs;
void dfs2(int v) {
  if (col[v] >= 0) return;
  col[v] = 0;
  curs.pb(v);
  for (int x : es[v])
    dfs2(x);
}

const int K = 160;

int main() {
  #ifdef DEBUG
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif

  int n, m;
  while (scanf("%d%d", &n, &m) == 2) {
    vector<vector<pii>> aes(m);
    forn (i, m) {
      int a, b, c;
      scanf("%d%d%d", &a, &b, &c), a--, b--, c--;
      aes[c].pb(mp(a, b));
    }
    
    vvi graphByCol;

    vector<pii> was(n, mp(0, 0));
    int wver = 0;

    es = vvi(n);
    col = vi(n, -1);

    vector<map<int, int>> anses(n);

    forn (c, m) {
      if (sz(aes[c]) <= K) {
        wver++;
        int vcnt = 0;
        static vi oids;
        oids.clear();
        for (pii e : aes[c]) {
          int a = e.first, b = e.second;
          for (int i = 0; i < 2; i++, swap(a, b)) {
            if (was[a].first < wver) {
              oids.pb(a);
              was[a] = mp(wver, vcnt);
              vcnt++;
            }
          }
        }
        fill(es.begin(), es.begin() + vcnt, vi());
        for (pii e : aes[c]) {
          int a = was[e.first].second;
          int b = was[e.second].second;
          es[a].pb(b);
          es[b].pb(a);
        }
        fill(col.begin(), col.begin() + vcnt, -1);
        ccol = 0;
        forn (i, vcnt) if (col[i] < 0) {
          curs.clear();
          dfs2(i);
          for (int a = 0; a < sz(curs); a++)
          for (int b = a + 1; b < sz(curs); b++) {
            int x = oids[curs[a]], y = oids[curs[b]];
            if (x > y) swap(x, y);
            anses[x][y]++;
          }
        }
      } else {
        fill(es.begin(), es.end(), vi());
        for (pii e : aes[c]) {
          es[e.first].pb(e.second);
          es[e.second].pb(e.first);
        }
        fill(col.begin(), col.end(), -1);
        ccol = 0;
        forn (i, n) if (col[i] < 0)
          dfs1(i), ccol++;
        graphByCol.pb(col);
      }
    }

    int q;
    scanf("%d", &q);
    while (q --> 0) {
      int a, b;
      scanf("%d%d", &a, &b), a--, b--;
      if (a > b) swap(a, b);

      int res = 0;
      {
        auto it = anses[a].find(b);
        if (it != anses[a].end()) res += it->second;
      }
      for (auto &c : graphByCol) {
        res += c[a] == c[b];
      }
      printf("%d\n", res);
    }
    #ifdef DEBUG
    printf("\n");
    #endif
  }

  return 0;
}