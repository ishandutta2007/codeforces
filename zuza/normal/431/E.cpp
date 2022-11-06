#include <cassert>
#include <cstring>

#include <algorithm>
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

const llint inf = 1e17;

struct Node {
  llint suma;
  llint alive;
  llint maks;

  Node() { clear(); }
  void clear() { suma = alive = 0; maks = -inf; }

  void update(Node& a, Node& b) {
    maks = max(a.maks, b.maks);
    suma = a.suma + b.suma;
    alive = a.alive + b.alive;
  }
};

struct Tour {
  int offset;
  vector<Node> data;

  Tour(int n) {
    offset = 1; while (offset < n) offset *= 2;
    data.resize(2*offset);
  }

  int LO, HI;
  template<typename F> 
  void process(int x, int lo, int hi, const F& f) {
    if (hi <= LO || HI <= lo) return ;
    if (LO <= lo && hi <= HI) { f(data[x]); return; }
    process(2*x, lo, (lo+hi)/2, f);
    process(2*x+1, (lo+hi)/2, hi, f);
    data[x].update(data[2*x], data[2*x+1]);
  }

  double query(llint v) {
    int x = 1;
    llint alive = 0, maks = -inf, suma = 0;

    while (x < offset) {
      llint l_alive = alive + data[2*x].alive;
      llint l_suma = suma + data[2*x].suma;
      llint l_maks = max(maks, data[2*x].maks);

      if (l_alive*l_maks - l_suma - v < 0) {
        alive = l_alive;
        suma = l_suma;
        maks = l_maks;
        x = 2*x + 1;
      } else {
        x = 2*x;
      }
    }

    return maks + (v - (alive*maks - suma)) / (double)alive;
  }

  void update(int pos, llint val, int delta) { // [lo, hi>
    LO = pos; HI = pos+1;
    process(1, 0, offset, [val, delta](Node& d) {
        d.alive += delta;
        d.suma += delta*val;
        d.maks = val;
        if (d.alive == 0) d.maks = -inf;
      });
  }
};

const int MAXN = 1e5 + 123;

inline int get_idx(vector<int>& vals, int x) {
  auto it = lower_bound(vals.begin(), vals.end(), x); assert(*it == x);
  return it - vals.begin();
}

int main(void)
{
  struct Q {
    int type, p, x;
    llint v;
  };
  vector<Q> qs;
  vector<int> vals;

  int n, q; scanf("%d %d", &n, &q);

  static int orig[MAXN];
  REP(i, n) { scanf("%d", orig+i); vals.push_back(orig[i]); }

  REP(i, q) {
    int type; scanf("%d", &type);
    if (type == 1) { 
      int p, x; scanf("%d %d", &p, &x); --p;
      qs.push_back({type, p, x, -1});
      vals.push_back(x);
    } else if (type == 2) {
      llint v; scanf(LLD, &v);
      qs.push_back({type, -1, -1, v});
    } else assert(false);
  }

  vals.push_back(1e9 + 123);
  sort(vals.begin(), vals.end());
  vals.erase(unique(vals.begin(), vals.end()), vals.end());

  Tour T((int)vals.size());
  REP(i, n) T.update(get_idx(vals, orig[i]), orig[i], +1);

  REP(i, q) { // pazi ne koristi i
    if (qs[i].type == 1) {
      int p = qs[i].p;
      T.update(get_idx(vals, orig[p]), orig[p], -1);
      orig[p] = qs[i].x;
      T.update(get_idx(vals, orig[p]), orig[p], +1);
    } else { // 2
      assert(qs[i].type == 2);
      printf("%.9lf\n", T.query(qs[i].v));
    }
  }

  return 0;
}