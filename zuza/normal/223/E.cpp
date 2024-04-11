#include <algorithm>

#include <ctime>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

#ifdef ONLINE_JUDGE
# define LLD "%I64d"
#else
# define LLD "%ll" "d"
#endif

typedef long long llint;

const int MAXV = 1e5 + 123;
struct Pt { llint x, y; };

int v;
vector<int> E[MAXV];
vector<Pt> pts;

struct Dir {
  int a, b;
  double alpha;

  llint cap;
  llint pref;

  Dir(int a = -1, int b = -1, double alpha = 100, llint cap = 0, llint pref = -1)
    : a(a), b(b), alpha(alpha), cap(cap), pref(pref) {}

  friend bool operator < (Dir a, Dir b) { return a.alpha < b.alpha; }
};

vector<Dir> dirs[MAXV];
vector<int> bio;

double get_alpha(int a, int b) {
  double dx = pts[b].x - pts[a].x;
  double dy = pts[b].y - pts[a].y;
  return atan2(dy, dx);
}

llint get_sum(vector<Dir>& dirs, int lo, int hi) {
  if (lo > hi) {
    llint ans = 0;
    ans += get_sum(dirs, lo, (int)dirs.size()-1);
    ans += get_sum(dirs, 0, hi);
    return ans;
  }
  return dirs[hi].pref - dirs[lo].pref;
}

int get_idx(int a, int b) {
  Dir tmp = {a, b, get_alpha(a, b) - 1e-9};
  auto it = lower_bound(dirs[a].begin(), dirs[a].end(), tmp);
  assert(it != dirs[a].end());
  assert(it->a == a && it->b == b);
  return it - dirs[a].begin();
}

void add_cap(int a, int b, int cap) {
  dirs[a][get_idx(a, b)].cap += cap;
}

int dfs(int x) {
  bio[x] = true;
  int ans = 0;
  for (int y : E[x]) {
    if (bio[y]) continue;
    int val = dfs(y);
    add_cap(x, y, -val);
    add_cap(y, x, +val);
    ans += val;
  }
  return ans+1;
}

int main(void)
{
  int norig, e; scanf("%d %d", &norig, &e);
  REP(i, e) {
    int a, b; scanf("%d %d", &a, &b); --a, --b;
    E[a].push_back(b);
    E[b].push_back(a);
  }
  int minx_val = 1e9 + 213;
  int minx_idx = -1;
  REP(i, norig) {
    int x, y; scanf("%d %d", &x, &y);
    pts.push_back({x, y});
    if (x < minx_val) {
      minx_val = x;
      minx_idx = i;
    }
  }

  int sink = norig;
  int v = norig+1;
  pts.push_back({pts[minx_idx].x-1, pts[minx_idx].y});
  E[minx_idx].push_back(sink);
  E[sink].push_back(minx_idx);

  REP(i, v) {
    for (int j : E[i]) {
      dirs[i].push_back({i, j, get_alpha(i, j)});
    }
    sort(dirs[i].begin(), dirs[i].end());
  }

  { bio.clear(); bio.resize(v, false); 
    int ret = dfs(sink); assert(ret == v);
  }

  REP(i, v) {
    dirs[i].push_back({});
    dirs[i].back().cap = 0; dirs[i].back().pref = 0;
    dirs[i][0].pref = 0;
    REP(j, (int)dirs[i].size()-1) dirs[i][j+1].pref = dirs[i][j].pref + dirs[i][j].cap;
  }

  int nq; scanf("%d", &nq);
  REP(iq, nq) {
    int ncyc; scanf("%d", &ncyc);
    static vector<int> idxs; idxs.clear();
    REP(i, ncyc) {
      int x; scanf("%d", &x); --x;
      idxs.push_back(x);
    }
    llint area = 0;
    REP(i, ncyc) {
      int j = (i+1) % ncyc;
      int a = idxs[i], b = idxs[j];
      area += pts[a].x*pts[b].y - pts[a].y*pts[b].x;
    }
    if (area < 0) { reverse(idxs.begin(), idxs.end()); area = -area; }

    llint ans = 0;
    REP(i, ncyc) {
      int ibef = (i-1+ncyc)%ncyc;
      int iaft = (i+1)%ncyc;

      int lo = get_idx(idxs[i], idxs[ibef]) + 1;
      int hi = get_idx(idxs[i], idxs[iaft]);
      ans += get_sum(dirs[idxs[i]], lo, hi);
    }
    printf(LLD "\n", ans);
  }

  return 0;
}