
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
vb was;
vi ord;
void dfs(int v) {
  if (was[v]) return;
  was[v] = true;
  for (int x : es[v]) dfs(x);
  ord.pb(v);
}

int main() {
  #ifdef DEBUG
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif

  int n;
  while (scanf("%d", &n) == 1) {
    es = vvi(26);
    static char prev[110], cur[110];
    scanf("%s", prev);
    bool bad = false;
    forn (id, n - 1) {
      scanf("%s", cur);
      int l = 0;
      while (prev[l] && cur[l] && prev[l] == cur[l]) l++;
      if (prev[l] && cur[l]) {
        es[prev[l] - 'a'].pb(cur[l] - 'a');
      } else if (!cur[l]) {
        bad = true;
      }
      strcpy(prev, cur);
    }

    ord.clear();
    was = vb(26, false);
    forn (i, 26)
      if (!was[i]) dfs(i);
    reverse(ord.begin(), ord.end());

    forn (a, 26)
    for (int b : es[a]) {
      int aid = find(ord.begin(), ord.end(), a) - ord.begin();
      int bid = find(ord.begin(), ord.end(), b) - ord.begin();
      bad = bad || !(aid < bid);
    }
    if (bad) {
      printf("Impossible\n");
    } else {
      for (int a : ord)
        printf("%c", 'a' + a);
      printf("\n");
    }
  }

  return 0;
}