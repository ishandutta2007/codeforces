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

const int MAXN = int(5e4) + 100;
const int MAXQL = 4;

int calc(int p1, int p2, int l1, int l2) {
  int L = min(p1, p2);
  int R = max(p1 + l1 - 1, p2 + l2 - 1);
  return R - L + 1;
}

int getHash(const char *s, int l) {
  int res = 0;
  forn (i, l)
    res = res * 27 + s[i] - 'a' + 1;
  return res;
}

char s[MAXN];

int main() {
  #ifdef DEBUG
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif

  int q;
  while (scanf("%s%d", s, &q) == 2) {
    int n = strlen(s);

    vector<pair<pii, int>> rqs[MAXQL + 1][MAXQL + 1];
    map<pii, int> wasAt;
    vvi eqTo(q);
    forn (i, q) {
      char a[5], b[5];
      scanf("%s%s", a, b);

      int l1 = strlen(a), l2 = strlen(b);
      if (l1 > l2) swap(l1, l2), swap(a, b);

      int x = getHash(a, l1), y = getHash(b, l2);
      pii xy(x, y);
      if (wasAt.count(xy)) {
        eqTo[wasAt[xy]].pb(i);
        continue;
      }
      wasAt[xy] = i;
      rqs[l1][l2].pb(mp(xy, i));
    }

    vi anses(q, inf);
    for (int l1 = 1; l1 <= MAXQL; l1++)
    for (int l2 = l1; l2 <= MAXQL; l2++) {
      map<int, vi> pos1, pos2;
      for (int i = 0; i + l1 <= n; i++) pos1[getHash(s + i, l1)].pb(i);
      for (int i = 0; i + l2 <= n; i++) pos2[getHash(s + i, l2)].pb(i);

      for (auto rq : rqs[l1][l2]) {
        int a, b, id = rq.second;
        tie(a, b) = rq.first;

        auto it1 = pos1.find(a); if (it1 == pos1.end()) continue;
        auto it2 = pos2.find(b); if (it2 == pos2.end()) continue;

        int cl1 = l1, cl2 = l2;
        if (sz(it1->second) > sz(it2->second)) swap(it1, it2), swap(a, b), swap(cl1, cl2);

        vi &p1 = it1->second;
        vi &p2 = it2->second;
        int ans = inf;
        for (int x : p1) {
          int id = lower_bound(p2.begin(), p2.end(), x) - p2.begin();
          if (id < sz(p2)) ans = min(ans, calc(x, p2[id    ], cl1, cl2));
          if (id > 0     ) ans = min(ans, calc(x, p2[id - 1], cl1, cl2));
        }
        anses[id] = ans;
      }
    }

    forn (i, q)
    for (int x : eqTo[i])
      anses[x] = anses[i];

    forn (i, q)
      printf("%d\n", anses[i] < inf ? anses[i] : -1);
  }

  return 0;
}